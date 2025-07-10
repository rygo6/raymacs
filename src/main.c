#include "raylib.h"
#include "raymath.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_INPUT_CHARS 2048

#define LOG(...) printf(__VA_ARGS__);

const int endCharLength = 1;
float maxCharWidth = 128;
float maxCharHeight = 128;
float fontXSpacing = 10;
float fontYSpacing = 20;
const float fontSize = 24;
const char availableChars[] = "·¬ abcdefghijklmnopqrstuvwxyzABDCEFGHIJKLMNOPQRSTUVWXYZ1234567890-=!@#$%^&*()_+[];',./{}:\"<>?|`~\n\t\\";

typedef struct TextBuffer {
	int startLine;
	int caretBufferIndex;
	int caretRow;
	int caretCollumn;
	int newLineCount;
	int bufferCount;
	char* buffer;
	char* path;
	bool dirty;
} TextBuffer;

static int SearchLeft(const char* pBuffer, int index, char c) {
	while (pBuffer[index - 1] != c && index > 0) index--;    
	return index;
}

static int SearchLeftAndCount(const char* pBuffer, int index, char searchChar, char countChar, int *pCount) {
	while (pBuffer[index - 1] != searchChar && index > 0) {
		if (pBuffer[index] == countChar) *pCount = *pCount + 1;
		index--;    
	}
	return index;
}

static int SearchRight(const char* pBuffer, int index, char c, int max) {
	while (pBuffer[index] != c && index < max) index++;    
	return index;
}

static int SearchRightAndCount(const char* pBuffer, int index, char searchChar, int max, char countChar, int *pCount) {
	while (pBuffer[index] != searchChar && index < max) {
		if (pBuffer[index] == countChar) *pCount = *pCount + 1;
		index++;    
	}
	return index;
}

static inline int SearchLeftText(const TextBuffer* pText, char c) {
	return SearchLeft(pText->buffer, pText->caretBufferIndex, c);
}

static inline int SearchRightText(const TextBuffer* pText, char c) {
	return SearchRight(pText->buffer, pText->caretBufferIndex, c, pText->bufferCount);
}

static void InsertChar(TextBuffer* pText, char c) {
	memmove(pText->buffer + pText->caretBufferIndex + 1, pText->buffer + pText->caretBufferIndex, pText->bufferCount - pText->caretBufferIndex - 1);
	pText->buffer[pText->caretBufferIndex] = c;
	pText->bufferCount++;
	pText->caretBufferIndex++;
	pText->caretCollumn++;
	pText->dirty = true;
}

static inline int CurrentLineStartIndex(const TextBuffer* pText) {
	return SearchLeftText(pText,'\n');
}

static inline int CurrentLineEndIndex(const TextBuffer* pText) {
	return SearchRightText(pText,'\n');
}

static inline int CurrentCollumnIndex(const TextBuffer* pText) {
	return pText->caretBufferIndex - CurrentLineStartIndex(pText);
}

static void textMoveUpStartLine(TextBuffer* pText) {
	if (pText->caretBufferIndex < 0)	
		pText->caretBufferIndex = 0;

	LOG("%d %d\n", pText->startLine, pText->caretRow);
	if (pText->caretRow < 0) {
		pText->startLine += pText->caretRow;
		pText->caretRow = 0;

		if (pText->startLine < 0)
			pText->startLine = 0;
	}
} 

static void textMoveDownStartLine(TextBuffer* pText) {
	if (pText->caretBufferIndex < 0)
		pText->caretBufferIndex = 0;

	int iMaxCharHeight = maxCharHeight - 1;
	LOG("%d %d %d\n", pText->startLine, pText->caretRow, iMaxCharHeight);
	if (pText->caretRow > iMaxCharHeight) {
		pText->startLine += pText->caretRow - iMaxCharHeight;
		pText->caretRow = iMaxCharHeight;
	}
} 

static void MoveLeftText(TextBuffer* pText, char c) {
	if (pText->caretBufferIndex <= 0) 
		return;

	int newLineCount = 0;
	pText->caretBufferIndex = SearchLeftAndCount(pText->buffer, pText->caretBufferIndex - 1, c, '\n', &newLineCount);
	pText->caretRow -= newLineCount;
	pText->caretCollumn = CurrentCollumnIndex(pText);

	textMoveUpStartLine(pText);
}

static void MoveRightText(TextBuffer* pText, char c) {
	// if (pText->caretBufferIndex >= (pText->bufferCount - pText->newLineCount))
	if (pText->caretBufferIndex >= pText->bufferCount)
		return;

	int newLineCount = 0;
	pText->caretBufferIndex = SearchRightAndCount(pText->buffer, pText->caretBufferIndex + 1, c, pText->bufferCount, '\n', &newLineCount) + 1;
	pText->caretRow += newLineCount;
	pText->caretCollumn = CurrentCollumnIndex(pText);

	LOG("%d\n", newLineCount);

	textMoveDownStartLine(pText);
}

static TextBuffer text;

#define KEY_SHIFT_OFFSET   0b10000000000000000000000000000000
#define KEY_ALT_OFFSET     0b01000000000000000000000000000000
#define KEY_CONTROL_OFFSET 0b00100000000000000000000000000000

int main(void)
{
	//// Initialization
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
		bool leftMouse;
		bool shift;
		bool ctrl;
		bool alt;
		bool back;
		uint32_t modifierCombination;
	} input;

	//// File
	text.path = "./src/main.c";
	text.buffer = LoadFileText(text.path);
	while (text.buffer[text.bufferCount] != '\0') {
		if (text.buffer[text.bufferCount] == '\n') text.newLineCount++;
		text.bufferCount++;
	}
	
	TextBuffer* pText = &text;
	//// Loop
	while (!WindowShouldClose())   
	{
		framesCounter++;

		maxCharWidth = (textBox.width / fontXSpacing) - 1;
		maxCharHeight = (textBox.height / fontYSpacing) - 1;
		
		//// Input 
		{
			SetMouseCursor(mouseOnText ? MOUSE_CURSOR_IBEAM : MOUSE_CURSOR_DEFAULT);
	
			input.leftMouse = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
			input.back      = IsKeyDown(KEY_BACKSPACE);
			input.shift     = IsKeyDown(KEY_LEFT_SHIFT)   || IsKeyDown(KEY_RIGHT_SHIFT);
			input.alt       = IsKeyDown(KEY_LEFT_ALT)     || IsKeyDown(KEY_RIGHT_ALT);
			input.ctrl      = IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL);

			input.modifierCombination = (input.shift * KEY_SHIFT_OFFSET) |
										(input.alt   * KEY_ALT_OFFSET)   |
										(input.ctrl  * KEY_CONTROL_OFFSET);
						
			int key = GetKeyPressed();
			if (key == 0) {
				if (IsKeyPressedRepeat(KEY_BACKSPACE)) key   = KEY_BACKSPACE;
				else if (IsKeyPressedRepeat(KEY_DELETE)) key = KEY_DELETE;
				else if (IsKeyPressedRepeat(KEY_DOWN)) key   = KEY_DOWN;
				else if (IsKeyPressedRepeat(KEY_UP)) key     = KEY_UP;
				else if (IsKeyPressedRepeat(KEY_LEFT)) key   = KEY_LEFT;
				else if (IsKeyPressedRepeat(KEY_RIGHT)) key  = KEY_RIGHT;
			}


			while (key > 0)
			{
				switch (key | input.modifierCombination) {

					case KEY_CONTROL_OFFSET | KEY_LEFT:
						MoveLeftText(pText, ' ');
						break;

					case KEY_LEFT: 
						if (text.caretBufferIndex <= 0) 
							break;

						text.caretBufferIndex--;
						text.caretCollumn = CurrentCollumnIndex(&text);
						break;

					case KEY_CONTROL_OFFSET | KEY_RIGHT:
						MoveRightText(pText, ' ');
						break;

					case KEY_RIGHT: 
						if (text.caretBufferIndex >= (text.bufferCount - text.newLineCount))
							break;
						
						text.caretBufferIndex++;		
						text.caretCollumn = CurrentCollumnIndex(&text);
						break;

					case KEY_CONTROL_OFFSET | KEY_UP:
						MoveLeftText(pText, '{');
						break;

					case KEY_UP: {
						int currentLineStart = CurrentLineStartIndex(&text);                        
						int upLineEnd = currentLineStart - endCharLength;
						int upLineStart = SearchLeft(text.buffer, upLineEnd, '\n');
						int upLineDiff = upLineEnd - upLineStart;

						text.caretBufferIndex = upLineStart + (text.caretCollumn < upLineDiff ? text.caretCollumn : upLineDiff);
						text.caretRow--;
					
						textMoveUpStartLine(pText);

						break;
					}

					case KEY_CONTROL_OFFSET | KEY_DOWN:
						MoveRightText(pText, '{');
						break;

					case KEY_DOWN: {
						int currentLineStart = CurrentLineStartIndex(&text);      
						int currentLineEnd = CurrentLineEndIndex(&text);
						int downLineStart = currentLineEnd + endCharLength;
						int downLineEnd = SearchRight(text.buffer, downLineStart, '\n', text.bufferCount);
						int downLineDiff = downLineEnd - downLineStart;

						text.caretBufferIndex = downLineStart + (text.caretCollumn < downLineDiff ? text.caretCollumn : downLineDiff);
						text.caretRow++;        

						textMoveDownStartLine(pText);

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
						InsertChar(pText, '\n'); 
						text.newLineCount++; 
						break;

					case KEY_TAB: 
						InsertChar(pText, '\t'); 
						break;

					case KEY_SPACE:
						InsertChar(pText, ' '); 
						break;

					case KEY_CONTROL_OFFSET | KEY_S:
						printf("Saving: %s", text.path);
						SaveFileText(text.path, text.buffer);
						break;

					case (KEY_SHIFT_OFFSET | 'A') ... (KEY_SHIFT_OFFSET | 'Z'): 
						InsertChar(pText, key); 
						break;

					case 'A' ... 'Z': 
						InsertChar(pText, 'a' + (key - KEY_A)); 
						break;

					case KEY_KP_0 ... KEY_KP_9: 
						InsertChar(pText, '0' + (key - KEY_KP_0)); 
						break;

					case '0' ... '9': 
						InsertChar(pText, key); 
						break;

					case '`':  InsertChar(pText, key); break;
					case '-':  InsertChar(pText, key); break;
					case '=':  InsertChar(pText, key); break;
					case '[':  InsertChar(pText, key); break;
					case ']':  InsertChar(pText, key); break;
					case '\\': InsertChar(pText, key); break;
					case ';':  InsertChar(pText, key); break;
					case '\'': InsertChar(pText, key); break;
					case ',':  InsertChar(pText, key); break;
					case '.':  InsertChar(pText, key); break;
					case '/':  InsertChar(pText, key); break;

					case KEY_SHIFT_OFFSET | '1':  InsertChar(pText, '!'); break;
					case KEY_SHIFT_OFFSET | '2':  InsertChar(pText, '@'); break;
					case KEY_SHIFT_OFFSET | '3':  InsertChar(pText, '#'); break;
					case KEY_SHIFT_OFFSET | '4':  InsertChar(pText, '$'); break;
					case KEY_SHIFT_OFFSET | '5':  InsertChar(pText, '%'); break;
					case KEY_SHIFT_OFFSET | '6':  InsertChar(pText, '^'); break;
					case KEY_SHIFT_OFFSET | '7':  InsertChar(pText, '&'); break;
					case KEY_SHIFT_OFFSET | '8':  InsertChar(pText, '*'); break;
					case KEY_SHIFT_OFFSET | '9':  InsertChar(pText, '('); break;
					case KEY_SHIFT_OFFSET | '0':  InsertChar(pText, ')'); break;
					case KEY_SHIFT_OFFSET | '`':  InsertChar(pText, '~'); break;
					case KEY_SHIFT_OFFSET | '-':  InsertChar(pText, '_'); break;
					case KEY_SHIFT_OFFSET | '=':  InsertChar(pText, '+'); break;
					case KEY_SHIFT_OFFSET | '[':  InsertChar(pText, '{'); break;
					case KEY_SHIFT_OFFSET | ']':  InsertChar(pText, '}'); break;
					case KEY_SHIFT_OFFSET | '\\': InsertChar(pText, '|'); break;
					case KEY_SHIFT_OFFSET | ';':  InsertChar(pText, ':'); break;
					case KEY_SHIFT_OFFSET | '\'': InsertChar(pText, '"'); break;
					case KEY_SHIFT_OFFSET | ',':  InsertChar(pText, '<'); break;
					case KEY_SHIFT_OFFSET | '.':  InsertChar(pText, '>'); break;
					case KEY_SHIFT_OFFSET | '/':  InsertChar(pText, '?'); break;
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

			DrawRectangleRec(textBox, RAYWHITE);
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

			const int tabWidth = 4;

			for (int y = 0; y < maxCharHeight; ++y) {
				int tabCount = 0;
				for (int x = 0; x < maxCharWidth - (tabCount * tabWidth); ++x) {

					Vector2 position = {
						textBox.x + (fontXSpacing * x) + (tabCount * fontXSpacing * 4), 
						textBox.y + (fontYSpacing * y)
					};										

					if (index == text.caretBufferIndex)
						DrawLineEx((Vector2){position.x, position.y}, (Vector2){position.x, position.y + fontSize}, 4, ORANGE);

					Rectangle rect = {position.x, position.y, fontXSpacing, fontYSpacing};

					char c = text.buffer[index];
					Color color = DARKGRAY;
					switch (text.buffer[index]) {
						case '\0':
							goto FinishDrawingText;

						case '\n':

							c =  '|';
							color = LIGHTGRAY;
							int codePointSize;
							int codePoint = GetCodepoint(&c, &codePointSize);
							DrawTextCodepoint(font, codePoint, position, fontSize, color);

							index++;

							// Check click on entire line
							rect.width = textBox.width - rect.width;
							if (input.leftMouse && CheckCollisionPointRec(mousePosition, rect)){
								text.caretBufferIndex = index - 1;
								text.caretCollumn = CurrentCollumnIndex(&text);
							}
							goto NextLine;

						case '\t':
							c = '-';
							color = LIGHTGRAY;
							tabCount++;
							// Step more spaces for tab width
							rect.width += (tabCount * fontXSpacing * tabWidth);
							break;

						case ' ':
							c =  '_';
							color = LIGHTGRAY;
							break;
					}
				
					if (input.leftMouse && CheckCollisionPointRec(mousePosition, rect)){
						float xDiff = mousePosition.x - (rect.x + (rect.width / 2));
						text.caretBufferIndex = xDiff > 0 ? index + 1 : index;
						text.caretCollumn = CurrentCollumnIndex(&text);
					}
										
					int codePointSize;
					int codePoint = GetCodepoint(&c, &codePointSize);
					DrawTextCodepoint(font, codePoint, position, fontSize, color);
										
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


