#include "raylib.h"
#include "raymath.h"
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_CHARS 2048


const int endCharLength = 1;
const float maxCharWidth = 80;
const float maxCharHeight = 80;
const float fontSize = 40;
const float fontSpacing = 5;
const char availableChars[] = " abcdefghijklmnopqrstuvwxyzABDCEFGHIJKLMNOPQRSTUVWXYZ1234567890-=!@#$%^&*()_+[];',./{}:\"<>?|`~\n\t";

static struct {
    int caretBufferIndex;
    int targetCaretCollumnIndex;
    int newLineCount;
    int bufferCount;
    char buffer[MAX_INPUT_CHARS + 1];
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
    text.targetCaretCollumnIndex++;
}

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
        bool leftMousePressed;
        bool shiftPressed;
        bool backspacePressed;
    } input;

    //// Debug Text
    char defaultText[] = "\tTest Test\nTest\nTest Test\n";
    text.bufferCount = sizeof(defaultText);
    for (int i = 0; i < text.bufferCount; ++i)
        if (defaultText[i] == '\n') text.newLineCount++;
    memcpy(text.buffer, defaultText, sizeof(defaultText));
    
    //// Loop
    while (!WindowShouldClose())   
    {
        framesCounter++;
        
        //// Input 
        {
            SetMouseCursor(mouseOnText ? MOUSE_CURSOR_IBEAM : MOUSE_CURSOR_DEFAULT);
    
            input.leftMousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
            input.shiftPressed = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT);
            input.backspacePressed = IsKeyDown(KEY_BACKSPACE);
            

            
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
                switch (key) {
                    case KEY_LEFT:
                        if (text.caretBufferIndex > 0) {
                            text.caretBufferIndex--;
                            int currentLineStart = SearchLeft(text.buffer, text.caretBufferIndex, '\n');
                            text.targetCaretCollumnIndex = text.caretBufferIndex - currentLineStart;
                        }
                        break;
                    case KEY_RIGHT:
                        if (text.caretBufferIndex <= (text.bufferCount - text.newLineCount)) {
                            text.caretBufferIndex++;
                            int currentLineStart = SearchLeft(text.buffer, text.caretBufferIndex, '\n');
                            text.targetCaretCollumnIndex = text.caretBufferIndex - currentLineStart;
                        }
                        break;
                    case KEY_UP: {
                        int currentLineStart = SearchLeft(text.buffer, text.caretBufferIndex, '\n');                        
                        int upLineEnd = currentLineStart - endCharLength;
                        int upLineStart = SearchLeft(text.buffer, upLineEnd, '\n');
                        int upLineDiff = upLineEnd - upLineStart;

                        text.caretBufferIndex = upLineStart + (text.targetCaretCollumnIndex < upLineDiff ? text.targetCaretCollumnIndex : upLineDiff);
                        
                        if (text.caretBufferIndex < 0)
                            text.caretBufferIndex = 0;

                        break;
                    }
                    case KEY_DOWN: {
                        int currentLineStart = SearchLeft(text.buffer, text.caretBufferIndex, '\n');
                        int currentLineEnd = SearchRight(text.buffer, text.caretBufferIndex, '\n', text.bufferCount);
                        int downLineStart = currentLineEnd + endCharLength;
                        int downLineEnd = SearchRight(text.buffer, downLineStart, '\n', text.bufferCount);
                        int downLineDiff = downLineEnd - downLineStart;

                        text.caretBufferIndex = downLineStart + (text.targetCaretCollumnIndex < downLineDiff ? text.targetCaretCollumnIndex : downLineDiff );
                        
                        if (text.caretBufferIndex >= text.bufferCount)
                            text.caretBufferIndex = text.bufferCount - 2;

                        break;
                    }
                    case KEY_BACKSPACE:
                        if (text.bufferCount > 0) {
                            if (text.buffer[text.caretBufferIndex - 1] == '\n') 
                                text.newLineCount--;
                            
                            memmove(text.buffer + text.caretBufferIndex - 1, text.buffer + text.caretBufferIndex, text.bufferCount - text.caretBufferIndex);
                            text.bufferCount--;
                            text.caretBufferIndex--;
                        }
                        break;
                    case KEY_DELETE:
                        if (text.bufferCount > 0 && text.caretBufferIndex < text.bufferCount - 1) {
                            if (text.buffer[text.caretBufferIndex] == '\n') 
                                text.newLineCount--;
                            
                            text.bufferCount--;
                            memmove(text.buffer + text.caretBufferIndex, text.buffer + text.caretBufferIndex + 1, text.bufferCount - text.caretBufferIndex - 1);
                        }
                        break;


                        InsertChar('\n');

                        break;

                    case 'A' ... 'Z': 
                        key = (input.shiftPressed ? 'A' : 'a') + (key - KEY_A); 
                        InsertChar(key); 
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

                    case '1':  key = '!'; InsertChar(key); break;
                    case '2':  key = '@'; InsertChar(key); break;
                    case '3':  key = '#'; InsertChar(key); break;
                    case '4':  key = '$'; InsertChar(key); break;
                    case '5':  key = '%'; InsertChar(key); break;
                    case '6':  key = '^'; InsertChar(key); break;
                    case '7':  key = '&'; InsertChar(key); break;
                    case '8':  key = '*'; InsertChar(key); break;
                    case '9':  key = '('; InsertChar(key); break;
                    case '0':  key = ')'; InsertChar(key); break;
                    case '`':  key = '~'; InsertChar(key); break;
                    case '-':  key = '_'; InsertChar(key); break;
                    case '=':  key = '+'; InsertChar(key); break;
                    case '[':  key = '{'; InsertChar(key); break;
                    case ']':  key = '}'; InsertChar(key); break;
                    case '\\': key = '|'; InsertChar(key); break;
                    case ';':  key = ':'; InsertChar(key); break;
                    case '\'': key = '"'; InsertChar(key); break;
                    case ',':  key = '<'; InsertChar(key); break;
                    case '.':  key = '>'; InsertChar(key); break;
                    case '/':  key = '?'; InsertChar(key); break;
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
            DrawText(TextFormat("INPUT CHARS: %i/%i %i", text.bufferCount, MAX_INPUT_CHARS, text.caretBufferIndex), 0, 0, 20, DARKGRAY);

            DrawRectangleRec(textBox, LIGHTGRAY);
            DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);
            
            bool blink = ((framesCounter/20)%2) == 0;
            
            Vector2 mousePosition = GetMousePosition();
            float xSpacing = 20;
            float ySpacing = 40;
            int index = 0;
            for (int y = 0; y < maxCharHeight; ++y) {
                for (int x = 0; x < maxCharWidth; ++x) {
                    Vector2 position = {textBox.x + xSpacing * x, textBox.y + ySpacing * y};
                    Rectangle rect = (Rectangle){position.x, position.y, xSpacing, ySpacing};

                    if (index == text.caretBufferIndex && blink) {
                        DrawLineEx((Vector2){position.x, position.y}, (Vector2){position.x, position.y + fontSize}, 2, ORANGE);
                    }
                    
                    if (input.leftMousePressed && CheckCollisionPointRec(mousePosition, rect)){
                        float xDiff = mousePosition.x - (rect.x + (rect.width / 2));
                        text.caretBufferIndex = xDiff > 0 ? index + 1 : index;
                    }
                    
                    if (text.buffer[index] == '\0')
                        goto FinishDrawingText;
                    
                    if (text.buffer[index] == '\n'){
                        index++;
                        goto NextLine;
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


 