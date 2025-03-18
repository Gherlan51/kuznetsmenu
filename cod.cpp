#include <fstream>
#include "raylib.h"
#include <string>
#include <cstdlib>

using namespace std;

const int screenWidth = 800;
const int screenHeight = 800;

void OpenGraph()
{
    system("start proiect\\output\\curba_kzunets\\curba_kzunets.exe");
}


int main()
{

    ofstream SelectFile("proiect\\output\\curba_kzunets\\_internal\\select.txt");
    InitWindow(screenWidth, screenHeight, "Kuznets Curve");
    InitAudioDevice();
    SetTargetFPS(30);

    Image Icon = LoadImage("textures\\k.png");
    SetWindowIcon(Icon);
    Texture2D Menu = LoadTexture("textures\\start.png");
    Texture2D selectMenu = LoadTexture("textures\\select.png");
    Texture2D infoMenu = LoadTexture("textures\\info.png");
    Sound click = LoadSound("textures\\click.mp3");

    bool MainMenu = true;
    bool Info = false;
    bool SelectMenu = false;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        //ClearBackground(RAYWHITE);
        if (MainMenu == true)
        {
            DrawTexture(Menu, 0, 0, RAYWHITE);
            Vector2 mousePos = GetMousePosition();
                
                if(mousePos.x>=268 && mousePos.x <= 537 && mousePos.y>= 468 && mousePos.y<=560 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                {
                    PlaySound(click);
                    Info = true;
                    MainMenu = false;
                }
                 else if(mousePos.x>=268 && mousePos.x <= 537 && mousePos.y>= 343 && mousePos.y<=435 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                 {
                     PlaySound(click);
                     SelectMenu = true;
                     MainMenu = false;
                 }
            }
            // select & close
            else if (SelectMenu == true)
            {
                DrawTexture(selectMenu,10,10,RAYWHITE);
                    Vector2 mousePos = GetMousePosition();
                    // back
                    if(mousePos.x>=562 && mousePos.x <= 759 && mousePos.y>= 697 && mousePos.y<=761 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    {
                        PlaySound(click);
                        SelectMenu = false;
                        MainMenu = true;
                    }
                    // Romania
                    else if(mousePos.x>=265 && mousePos.x <= 535 && mousePos.y>= 225 && mousePos.y<=313 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    {
                        PlaySound(click);
                        SelectFile << "Romania";
                        OpenGraph();
                        break;
                    }
                    // Spania
                    else if(mousePos.x>=265 && mousePos.x <= 535 && mousePos.y>= 357 && mousePos.y<=444 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    {
                        PlaySound(click);
                        SelectFile << "Spania";
                        OpenGraph();
                        break;
                    }
                    // Polonia
                    else if(mousePos.x>=265 && mousePos.x <= 535 && mousePos.y>= 487 && mousePos.y<=578 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    {
                        PlaySound(click);
                        SelectFile << "Portugalia";
                        OpenGraph();
                        break;
                    }
                
            }

            // info data
            else if (Info == true)
            {
                DrawTexture(infoMenu,0,0,RAYWHITE);
                    Vector2 mousePos = GetMousePosition();
                    // back
                    if(mousePos.x>=562 && mousePos.x <= 759 && mousePos.y>= 697 && mousePos.y<=761 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    {
                        PlaySound(click);
                        Info = false;
                        MainMenu = true;
                    }
                
            }
        
        EndDrawing();
    }

    UnloadTexture(Menu);
    UnloadTexture(selectMenu);
    UnloadSound(click);
    SelectFile.close();
    CloseAudioDevice();
    CloseWindow();
}