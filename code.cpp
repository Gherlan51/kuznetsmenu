#include <fstream>
#include "raylib.h"
#include <string>
#include <windows.h>
#include <shellapi.h>

using namespace std;

const int screenWidth = 800;
const int screenHeight = 800;




int main()
{

    ofstream SelectFile("select.txt");
    InitWindow(screenWidth, screenHeight, "Kuznets Curve");
    SetTargetFPS(30);


    Texture2D Menu = LoadTexture("extra\\meniu.png");
Texture2D selectMenu = LoadTexture("extra\\meniu_select.png");
Sound click=LoadSound("extra\\click.mp3");

    bool MainMenu=true;
    bool Info = false;
    bool SelectMenu=false;

    while (true) 
    {
        if(MainMenu == true)
        {
            DrawTexture(Menu);
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                Vector2 mousePos = GetMousePosition();
                if(mousePos.x>=??? && mousePos.x <= ??? && mousePos.y>= ??? && mousePos.y<=???)
                    {
                        Info=true;
                        MainMenu=false;
                    }
                 else if(mousePos.x>=??? && mousePos.x <= ??? && mousePos.y>= ??? && mousePos.y<=???)
                 {
                     SelectMenu=true;
                     MainMenu=false;
                 }
                 
                    
            }
            //select & close
            else if(SelectMenu == true)
            {
                DrawTexture(selectMenu);
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                {
                    Vector2 mousePos = GetMousePosition();
                    //back
                    if(mousePos.x>=??? && mousePos.x <= ??? && mousePos.y>= ??? && mousePos.y<=???)
                    {
                        SelectMenu=false;
                        MainMenu=true;
                    }
                    //Romania
                    else if(mousePos.x>=??? && mousePos.x <= ??? && mousePos.y>= ??? && mousePos.y<=???)
                    {
                        SelectFile<<"Romania";
                        break;
                    }
                    //Spania
                    else if(mousePos.x>=??? && mousePos.x <= ??? && mousePos.y>= ??? && mousePos.y<=???)
                    {
                        SelectFile<<"Spania";
                        break;
                    }
                    //Polonia
                    else if(mousePos.x>=??? && mousePos.x <= ??? && mousePos.y>= ??? && mousePos.y<=???)
                    {
                        SelectFile<<"Polonia";
                        break;
                    }
                }
                
            }
            
            //info data
            else if(Info==true)
            {
                DrawTexture(selectMenu);
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                {
                    Vector2 mousePos = GetMousePosition();
                    //back
                    if(mousePos.x>=??? && mousePos.x <= ??? && mousePos.y>= ??? && mousePos.y<=???)
                    {
                        Info=false;
                        MainMenu=true;
                    }
                    //Romania
                    else if(mousePos.x>=??? && mousePos.x <= ??? && mousePos.y>= ??? && mousePos.y<=???)
                    {
                        ShellExecute(0, 0, L"https://www.sciencedirect.com/science/article/pii/S0264837719304260", 0, 0 , SW_SHOW );
                    }
                    //Spania
                    else if(mousePos.x>=??? && mousePos.x <= ??? && mousePos.y>= ??? && mousePos.y<=???)
                    {
                        ShellExecute(0, 0, L"https://apcz.umk.pl/DEM/article/view/DEM.2014.003/5251", 0, 0 , SW_SHOW );
                    }
                    //Polonia
                    else if(mousePos.x>=??? && mousePos.x <= ??? && mousePos.y>= ??? && mousePos.y<=???)
                    {
                        ShellExecute(0, 0, L"https://www.adb.org/sites/default/files/publication/977221/ewp-731-data-driven-environmental-kuznets-curve.pdf ", 0, 0 , SW_SHOW );
                    }
                }
                
            }
        }
        
        
    }
    WindowShouldClose();
    UnloadTexture(Menu);
    UnloadTexture(SelectMenu);
    UnloadSound(click);
    SelectFile.close();
}    