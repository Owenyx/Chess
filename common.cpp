//move all actual code here

#include "common.hpp"

Colour turn = Colour::WHITE;

Coord::Coord(int r, int c) {
    row = r;
    col = c;
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void gotocoor(Coord c) {
    gotoxy(c.x, c.y);
}

Coord getCursorPos() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD coord = { -1, -1 }; // Initialize with invalid coordinates

    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        coord = csbi.dwCursorPosition;
    } else {
        std::cerr << "Error: Unable to get console cursor position" << std::endl;
    }

    Coord c = coord; //everything else uses Coord struct

    return c;
}

Coord operator=(Coord c1, COORD c2) {
    c1.x = c2.X;
    c1.y = c2.Y;
    return c1;
}

void vert_line(int h) {
    Coord c = getCursorPos();
    int x = c.x;
    int y = c.y;
    h += y;
    while (y > h) { //draws top down 
        gotoxy(x,y);
        cout << '|';
    }
}
