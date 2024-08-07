//move all actual code here

#include "common.hpp"

Colour turn = Colour::WHITE;

Coord::Coord(int x, int y) {
    this->x = x;
    this->y = y;
}

void clearScreen() {
    // ANSI escape code to clear screen
    std::cout << "\033[2J\033[1;1H";
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

    Coord c(coord.X, coord.Y); //everything else uses Coord struct

    return c;
}

//bool Coord::operator==(Coord c) {
//    return (this->x == c.x && this->y == c.y);
//}

void vert_line(int x, int y, int h) {
    //Coord c = getCursorPos();
    //int x = c.x;
    //int y = c.y;
    h += y; //set height = to the current position + height needed
    for (; y < h; y++) { //draws top down 
        gotoxy(x,y);
        cout << '|';
    }
}
