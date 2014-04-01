/* Using the direction keys to control a character's position. */
#include <iostream>
#include <conio.h>
#include <Windows.h>

const int KEY_UP = 72;
const int KEY_LEFT = 75;
const int KEY_RIGHT = 77;
const int KEY_DOWN = 80;

inline int imax(int a, int b)
{
    return a > b ? a : b;
}

inline int imin(int a, int b)
{
    return a < b ? a : b;
}

/* Get the width and height of current console screen. */
void GetWH(int *screenWidth,int *screenHeight) 
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) 
    {
        *screenWidth = csbi.srWindow.Right;
        *screenHeight = csbi.srWindow.Bottom;
    } 
    else 
    {
        *screenWidth = 80;
        *screenHeight = 25;
    }
}

/* Clear the console screen. */
void ClearConsole()
{
   //Get the handle to the current output buffer...
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

   //This is used to reset the carat/cursor to the top left.
   COORD coord = {0, 0};

   //A return value... indicating how many chars were written
   //   not used but we need to capture this since it will be
   //   written anyway (passing NULL causes an access violation).
   DWORD count;

   //This is a structure containing all of the console info
   // it is used here to find the size of the console.
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   //Here we will set the current color
   if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
   {
      //This fills the buffer with a given character (in this case 32=space).
      FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

      FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

      //This will set our cursor position for the next print statement.
      SetConsoleCursorPosition(hStdOut, coord);
   }
}

int main()
{
    char c = 'O';
    char blank = ' ';
    int code0 = 0;
    int code1 = 0;
    int px = 0;
    int py = 0;
    int screenWidth = 0;
    int screenHeight = 0;

    GetWH(&screenWidth, &screenHeight);

    COORD position;

    position.X = px = screenWidth / 2;
    position.Y = py = screenHeight / 2;

    /* Output the char at initial position. */
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
    std::cout << c;

    while(true)
    {
        code0 = (int)_getch();    

        /* Press ESC to quit. */
        if(code0 == 27)
        {
            break;
        }

        code1 = (int)_getch();

        switch(code1)
        {
        case KEY_UP:
            py = imax(0, py - 1);
            break;
        case KEY_LEFT:
            px = imax(0, px - 1);            
            break;
        case KEY_RIGHT:
            px= imin(screenWidth, px + 1);
            break;
        case KEY_DOWN:
            py = imin(screenHeight, py + 1);            
            break;
        default:
            break;
        }

        ClearConsole();

        position.X = px;
        position.Y = py;

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

        /* Output the char at the new position. */
        std::cout << c;
    }

    return 0;
}