#include "raylib.h"
#include "raymath.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_INPUT_CHARS 2048

const int endCharLength = 1;
float maxCharWidth = 128;
float maxCharHeight = 128;
float fontXSpacing = 10;
float fontYSpacing = 20;
const float fontSize = 24;
const char availableChars[] = " abcdefghijklmnopqrstuvwxyzABDCEFGHIJKLMNOPQRSTUVWXYZ1234567890-=!@#$%^&*()_+[];',./{}:\"<>?|`~\n\t\\";

static struct {
	int startLine;
	int caretBufferIndex;
	int caretRow;
	int caretCollumn;
	int newLineCount;
	int bufferCount;
	char* buffer;
	char* path;
	bool dirty;
} text;

static int SearchLeft(const char* buffer, int caret, char c) {
	while (buffer[caret - 1] != c && caret > 0) caret--;    
	return caret;
}

static int SearchRight(const char* buffer, int caret, char c, int max) {
	while (buffer[caret] != c && caret < max) caret++;    
	return caret;
}

static void InsertChar(char c) {
	memmove(text.buffer + text.caretBufferIndex + 1, text.buffer + text.caretBufferIndex, text.bufferCount - text.caretBufferIndex - 1);
	text.buffer[text.caretBufferIndex] = c;
	text.bufferCount++;
	text.caretBufferIndex++;
	text.caretCollumn++;
	text.dirty = true;
}

#define KEY_SHIFT_OFFSET   0b10000000000000000000000000000000
#define KEY_ALT_OFFSET     0b01000000000000000000000000000000
#define KEY_CONTROL_OFFSET 0b00100000000000000000000000000000

int main(void)
{
	// Initialization
	SetConfigFlags(FLAG_VSYNC_HINT);
	EnableEventWaiting();

	const int screenWidth = 1600;
	const int screenHeight = 1200;

	InitWindow(screenWidth, screenHeight, "raytex");
	   
	//// Font
	int codepointCount = 0;
	int *codepoints = LoadCodepoints(availableChars, &codepointCount);
	Font font = LoadFontEx("resources/JetBrainsMono-Regular.ttf", fontSize, codepoints, codepointCount);
	SetTextureFilter(font.texture, TEXTURE_FILTER_BILINEAR);
	SetTextLineSpacing(0); 

	//// Editor State
	Rectangle textBox = { 5, 20, screenWidth - 10, screenHeight - 25 };
	bool mouseOnText = false;
	int framesCounter = 0;
	
	struct {
		bool leftMousePressed;
		bool shiftPressed;
		bool controlPressed;
		bool altPressed;
		bool backspacePressed;
		uint32_t modifierCombination;
	} input;

	//// File
	text.path = "./src/main.c";
	text.buffer = LoadFileText(text.path);
	while (text.buffer[text.bufferCount] != '\0') {
		if (text.buffer[text.bufferCount] == '\n') text.newLineCount++;
		text.bufferCount++;
	}
	
	//// Loop
	while (!WindowShouldClose())   
	{
		framesCounter++;

		maxCharWidth = (textBox.width / fontXSpacing) - 1;
		maxCharHeight = (textBox.height / fontYSpacing) - 1;
		
		//// Input 
		{
			SetMouseCursor(mouseOnText ? MOUSE_CURSOR_IBEAM : MOUSE_CURSOR_DEFAULT);
	
			input.leftMousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
			input.backspacePressed = IsKeyDown(KEY_BACKSPACE);
			input.shiftPressed     = IsKeyDown(KEY_LEFT_SHIFT)   || IsKeyDown(KEY_RIGHT_SHIFT);
			input.altPressed       = IsKeyDown(KEY_LEFT_ALT)     || IsKeyDown(KEY_RIGHT_ALT);
			input.controlPressed   = IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL);

			input.modifierCombination = (input.shiftPressed   * KEY_SHIFT_OFFSET) |
										(input.altPressed     * KEY_ALT_OFFSET)   |
										(input.controlPressed * KEY_CONTROL_OFFSET);
						
			int key = GetKeyPressed();
			if (key == 0) {
				if (IsKeyPressedRepeat(KEY_BACKSPACE)) key = KEY_BACKSPACE;
				else if (IsKeyPressedRepeat(KEY_DELETE)) key = KEY_DELETE;
				else if (IsKeyPressedRepeat(KEY_DOWN)) key = KEY_DOWN;
				else if (IsKeyPressedRepeat(KEY_UP)) key = KEY_UP;
				else if (IsKeyPressedRepeat(KEY_LEFT)) key = KEY_LEFT;
				else if (IsKeyPressedRepeat(KEY_RIGHT)) key = KEY_RIGHT;
			}

			while (key > 0)
			{
				switch (key | input.modifierCombination) {

					case KEY_LEFT: if (text.caretBufferIndex > 0) {
							text.caretBufferIndex--;
							int currentLineStart = SearchLeft(text.buffer, text.caretBufferIndex, '\n');
							text.caretCollumn = text.caretBufferIndex - currentLineStart;
						}
						break;

					case KEY_RIGHT: if (text.caretBufferIndex <= (text.bufferCount - text.newLineCount)) {
							text.caretBufferIndex++;
							int currentLineStart = SearchLeft(text.buffer, text.caretBufferIndex, '\n');
							text.caretCollumn = text.caretBufferIndex - currentLineStart;
						}
						break;

					case KEY_UP: {
						int currentLineStart = SearchLeft(text.buffer, text.caretBufferIndex, '\n');                        
						int upLineEnd = currentLineStart - endCharLength;
						int upLineStart = SearchLeft(text.buffer, upLineEnd, '\n');
						int upLineDiff = upLineEnd - upLineStart;

						text.caretBufferIndex = upLineStart + (text.caretCollumn < upLineDiff ? text.caretCollumn : upLineDiff);
						text.caretRow--;
						
						if (text.caretBufferIndex < 0)
							text.caretBufferIndex = 0;

						if (text.caretRow < 0) {
							text.caretRow = 0;
							text.startLine--;
						}

						break;
					}
					case KEY_DOWN: {
						int currentLineStart = SearchLeft(text.buffer, text.caretBufferIndex, '\n');
						int currentLineEnd = SearchRight(text.buffer, text.caretBufferIndex, '\n', text.bufferCount);
						int downLineStart = currentLineEnd + endCharLength;
						int downLineEnd = SearchRight(text.buffer, downLineStart, '\n', text.bufferCount);
						int downLineDiff = downLineEnd - downLineStart;

						text.caretBufferIndex = downLineStart + (text.caretCollumn < downLineDiff ? text.caretCollumn : downLineDiff);
						text.caretRow++;        
						
						if (text.caretBufferIndex >= text.bufferCount)
							text.caretBufferIndex = text.bufferCount - 2;

						if (text.caretRow > maxCharHeight - 1) {
							text.caretRow = maxCharHeight - 1;
							text.startLine++;
						}

						break;
					}
					case KEY_BACKSPACE: if (text.bufferCount > 0) {
							if (text.buffer[text.caretBufferIndex - 1] == '\n') 
								text.newLineCount--;
							
							memmove(text.buffer + text.caretBufferIndex - 1, text.buffer + text.caretBufferIndex, text.bufferCount - text.caretBufferIndex);
							text.bufferCount--;
							text.caretBufferIndex--;
						}
						break;

					case KEY_DELETE: if (text.bufferCount > 0 && text.caretBufferIndex < text.bufferCount - 1) {
							if (text.buffer[text.caretBufferIndex] == '\n') 
								text.newLineCount--;
							
							text.bufferCount--;
							memmove(text.buffer + text.caretBufferIndex, text.buffer + text.caretBufferIndex + 1, text.bufferCount - text.caretBufferIndex - 1);
						}
						break;

					case KEY_ENTER: 
						InsertChar('\n'); 
						text.newLineCount++; 
						break;

					case KEY_TAB: 
						InsertChar('\t'); 
						break;

					case KEY_SPACE:
						InsertChar(' '); 
						break;

					case KEY_CONTROL_OFFSET | KEY_S:
						printf("Saving: %s", text.path);
						SaveFileText(text.path, text.buffer);
						break;

					case (KEY_SHIFT_OFFSET | 'A') ... (KEY_SHIFT_OFFSET | 'Z'): 
						InsertChar(key); 
						break;

					case 'A' ... 'Z': 
						InsertChar('a' + (key - KEY_A)); 
						break;

					case '0' ... '9': 
						InsertChar(key); 
						break;

					case 'KEY_KP_0' ... 'KEY_KP_9': 
						InsertChar('0' + (key - KEY_A)); 
						break;

					case '`':  InsertChar(key); break;
					case '-':  InsertChar(key); break;
					case '=':  InsertChar(key); break;
					case '[':  InsertChar(key); break;
					case ']':  InsertChar(key); break;
					case '\\': InsertChar(key); break;
					case ';':  InsertChar(key); break;
					case '\'': InsertChar(key); break;
					case ',':  InsertChar(key); break;
					case '.':  InsertChar(key); break;
					case '/':  InsertChar(key); break;

					case KEY_SHIFT_OFFSET | '1':  InsertChar('!'); break;
					case KEY_SHIFT_OFFSET | '2':  InsertChar('@'); break;
					case KEY_SHIFT_OFFSET | '3':  InsertChar('#'); break;
					case KEY_SHIFT_OFFSET | '4':  InsertChar('$'); break;
					case KEY_SHIFT_OFFSET | '5':  InsertChar('%'); break;
					case KEY_SHIFT_OFFSET | '6':  InsertChar('^'); break;
					case KEY_SHIFT_OFFSET | '7':  InsertChar('&'); break;
					case KEY_SHIFT_OFFSET | '8':  InsertChar('*'); break;
					case KEY_SHIFT_OFFSET | '9':  InsertChar('('); break;
					case KEY_SHIFT_OFFSET | '0':  InsertChar(')'); break;
					case KEY_SHIFT_OFFSET | '`':  InsertChar('~'); break;
					case KEY_SHIFT_OFFSET | '-':  InsertChar('_'); break;
					case KEY_SHIFT_OFFSET | '=':  InsertChar('+'); break;
					case KEY_SHIFT_OFFSET | '[':  InsertChar('{'); break;
					case KEY_SHIFT_OFFSET | ']':  InsertChar('}'); break;
					case KEY_SHIFT_OFFSET | '\\': InsertChar('|'); break;
					case KEY_SHIFT_OFFSET | ';':  InsertChar(':'); break;
					case KEY_SHIFT_OFFSET | '\'': InsertChar('"'); break;
					case KEY_SHIFT_OFFSET | ',':  InsertChar('<'); break;
					case KEY_SHIFT_OFFSET | '.':  InsertChar('>'); break;
					case KEY_SHIFT_OFFSET | '/':  InsertChar('?'); break;
				}
				
				key = GetKeyPressed();
			}
		}


		//// Draw
		BeginDrawing();
		{

			ClearBackground(RAYWHITE);
			
			float frameTime = GetFrameTime();

			DrawText(TextFormat("frameTime: %f/", frameTime), 512, 0, 20, GRAY);
			DrawText(TextFormat("INPUT CHARS: %i %i", text.bufferCount, text.caretBufferIndex), 0, 0, 20, DARKGRAY);

			DrawRectangleRec(textBox, LIGHTGRAY);
			DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);
			
			// bool blink = ((framesCounter/20) % 2) == 0;
			
			Vector2 mousePosition = GetMousePosition();

			int index = 0;
			int startLineCount = 0;
			while (startLineCount < text.startLine) {
				if (text.buffer[index] == '\n' || text.buffer[index] == '\0')
					startLineCount++;
				index++;
			}

			for (int y = 0; y < maxCharHeight; ++y) {
				int tabCount = 0;
				for (int x = 0; x < maxCharWidth; ++x) {
					Vector2 position = {textBox.x + (fontXSpacing * x) + (tabCount * fontXSpacing * 4), textBox.y + (fontYSpacing * y)};

					switch (text.buffer[index]) {
						case '\0':
							goto FinishDrawingText;
						case '\n':
							index++;
							goto NextLine;
						case '\t':
							tabCount++;
							break;
					}
				
					Rectangle rect = {position.x, position.y, (fontXSpacing) + (tabCount * fontXSpacing * 4), fontYSpacing};

					if (index == text.caretBufferIndex) {
						DrawLineEx((Vector2){position.x, position.y}, (Vector2){position.x, position.y + fontSize}, 4, ORANGE);
					}
					
					if (input.leftMousePressed && CheckCollisionPointRec(mousePosition, rect)){
						float xDiff = mousePosition.x - (rect.x + (rect.width / 2));
						text.caretBufferIndex = xDiff > 0 ? index + 1 : index;
					}
										
					int codePointSize;
					int codePoint = GetCodepoint(text.buffer + index, &codePointSize);
					DrawTextCodepoint(font, codePoint, position, fontSize, DARKGRAY);
										
					index++;
				}
				NextLine:
			}       
			FinishDrawingText:
	
		}
		EndDrawing();
		
	}

	//// Cleanup
	CloseWindow();

	return 0;
}


 