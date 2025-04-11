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
const char availableChars[] = "abcdefghijklmnopqrstuvwxyzABDCEFGHIJKLMNOPQRSTUVWXYZ1234567890-=!@#$%^&*()_+[];',./{}:\"<>?|`~ \n";

static int SearchLeft(const char* buffer, int caret, char c) {
    while (buffer[caret - 1] != c && caret > 0) caret--;    
    return caret;
}

static int SearchRight(const char* buffer, int caret, char c, int max) {
    while (buffer[caret] != c && caret < max) caret++;    
    return caret;
}

int main(void)
{
    //// Initialization
    SetConfigFlags(FLAG_VSYNC_HINT);
    EnableEventWaiting();

    const int screenWidth = 1600;
    const int screenHeight = 1200;

    InitWindow(screenWidth, screenHeight, "raytex");

    char mainBuffer[MAX_INPUT_CHARS + 1];
    
    int mainBufferCount = 0;
    int newLineCount = 0;
    int finalNewLine =0;
    int mainCaret = 0;
    
    char defaultText[] = "TestTest\nTest\nTestTest\n";
    mainBufferCount = strlen(defaultText);
    for (int i = 0; i < sizeof(defaultText); ++i)
        if (defaultText[i] == '\n') newLineCount++;            
    mainBufferCount = sizeof(defaultText);
    mainCaret = strlen(defaultText) - 1;
    memcpy(mainBuffer, defaultText, sizeof(defaultText));
       
    int codepointCount = 0;
    int *codepoints = LoadCodepoints(availableChars, &codepointCount);
    Font font = LoadFontEx("resources/JetBrainsMono-Regular.ttf", fontSize, codepoints, codepointCount);
    SetTextureFilter(font.texture, TEXTURE_FILTER_BILINEAR);
    SetTextLineSpacing(0); 

    Rectangle textBox = { 5, 20, screenWidth - 10, screenHeight - 25 };
    bool mouseOnText = false;
    int framesCounter = 0;
    
    struct {
        bool leftMousePressed;
        bool shiftPressed;
        bool backspacePressed;
    } input;
    
    
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
            
            void insertChar(char c) {
                memmove(mainBuffer + mainCaret + 1, mainBuffer + mainCaret, mainBufferCount - mainCaret - 1);
                mainBuffer[mainCaret] = c;
                mainBufferCount++;
                mainCaret++;
            }
            
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
                        if (mainCaret > 0) mainCaret--;
                        break;
                    case KEY_RIGHT:
                        if (mainCaret <= (mainBufferCount - newLineCount)) mainCaret++;
                        break;
                    case KEY_UP: {
                        int currentLineStart = SearchLeft(mainBuffer, mainCaret, '\n');
                        int currentLineDiff = mainCaret - currentLineStart;
                        
                        int upLineEnd = currentLineStart - endCharLength;
                        int upLineStart = SearchLeft(mainBuffer, upLineEnd, '\n');
                        int upLineDiff = upLineEnd - upLineStart;

                        mainCaret = upLineStart + (currentLineDiff < upLineDiff ? currentLineDiff : upLineDiff);
                        
                        if (mainCaret < 0)
                            mainCaret = 0;

                        break;
                    }
                    case KEY_DOWN: {
                        int currentLineStart = SearchLeft(mainBuffer, mainCaret, '\n');
                        int currentLineEnd = SearchRight(mainBuffer, mainCaret, '\n', mainBufferCount);
                        int currentLineDiff = mainCaret - currentLineStart;
                        
                        int downLineStart = currentLineEnd + endCharLength;
                        int downLineEnd = SearchRight(mainBuffer, downLineStart, '\n', mainBufferCount);
                        int downLineDiff = downLineEnd - downLineStart;

                        mainCaret = downLineStart + (currentLineDiff < downLineDiff ? currentLineDiff : downLineDiff );
                        
                        if (mainCaret >= mainBufferCount)
                            mainCaret = mainBufferCount - 2;

                        break;
                    }
                    case KEY_BACKSPACE:
                        if (mainBufferCount > 0) {
                            if (mainBuffer[mainCaret - 1] == '\n') 
                                newLineCount--;
                            
                            memmove(mainBuffer + mainCaret - 1, mainBuffer + mainCaret, mainBufferCount - mainCaret);
                            mainBufferCount--;
                            mainCaret--;
                        }
                        break;
                    case KEY_DELETE:
                        if (mainBufferCount > 0 && mainCaret < mainBufferCount - 1) {
                            if (mainBuffer[mainCaret] == '\n') 
                                newLineCount--;
                            
                            mainBufferCount--;
                            memmove(mainBuffer + mainCaret, mainBuffer + mainCaret + 1, mainBufferCount - mainCaret - 1);
                        }
                        break;
                    case KEY_ENTER:
                        insertChar('\n');
                        newLineCount++;
                        break;
                    default:
                        if (key != '\n' && key < 32 || key > 126 || mainBufferCount >= MAX_INPUT_CHARS)
                            break;
                        
                        if (key >= KEY_A && key <= KEY_Z) {
                            key = (input.shiftPressed ? 'A' : 'a') + (key - KEY_A);
                        } else if (input.shiftPressed) {
                            switch (key) {
                                case '1':  key = '!'; break;
                                case '2':  key = '@'; break;
                                case '3':  key = '#'; break;
                                case '4':  key = '$'; break;
                                case '5':  key = '%'; break;
                                case '6':  key = '^'; break;
                                case '7':  key = '&'; break;
                                case '8':  key = '*'; break;
                                case '9':  key = '('; break;
                                case '0':  key = ')'; break;
                                case '`':  key = '~'; break;
                                case '-':  key = '_'; break;
                                case '=':  key = '+'; break;
                                case '[':  key = '{'; break;
                                case ']':  key = '}'; break;
                                case '\\': key = '|'; break;
                                case ';':  key = ':'; break;
                                case '\'': key = '"'; break;
                                case ',':  key = '<'; break;
                                case '.':  key = '>'; break;
                                case '/':  key = '?'; break;
                            }
                        }

                        insertChar(key);
                        break;
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
            DrawText(TextFormat("INPUT CHARS: %i/%i %i", mainBufferCount, MAX_INPUT_CHARS, mainCaret), 0, 0, 20, DARKGRAY);

            DrawRectangleRec(textBox, LIGHTGRAY);
            DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, mouseOnText ? RED : DARKGRAY);

            // Vector2 position = (Vector2){(int)textBox.x + fontSpacing, (int)textBox.y + fontSpacing};
            // DrawTextEx(font, mainBuffer, position, fontSize, fontSpacing, MAROON);
            
            bool blink = ((framesCounter/20)%2) == 0;
            
            Vector2 mousePosition = GetMousePosition();
            float xSpacing = 20;
            float ySpacing = 40;
            int index = 0;
            for (int y = 0; y < maxCharHeight; ++y) {
                for (int x = 0; x < maxCharWidth; ++x) {
                    Vector2 position = {textBox.x + xSpacing * x, textBox.y + ySpacing * y};
                    Rectangle rect = (Rectangle){position.x, position.y, xSpacing, ySpacing};

                    if (index == mainCaret) {
                        DrawLine(position.x, position.y, position.x, position.y + fontSize, BLACK);
                    }
                    
                    if (input.leftMousePressed && CheckCollisionPointRec(mousePosition, rect)){
                        float xDiff = mousePosition.x - (rect.x + (rect.width / 2));
                        mainCaret = xDiff > 0 ? index + 1 : index;
                    }
                    
                    if (mainBuffer[index] == '\0')
                        goto FinishDrawingText;
                    
                    if (mainBuffer[index] == '\n'){
                        index++;
                        goto NextLine;
                    }
                                        
                    int codePointSize;
                    int codePoint = GetCodepoint(mainBuffer + index, &codePointSize);
                    DrawTextCodepoint(font, codePoint, position, fontSize, MAROON);
                                        
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


 