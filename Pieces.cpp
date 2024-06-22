#include "common.hpp"

void None::print() {
    Coord c = getCursorPos();
    int x = c.x;
    int y = c.y;

    int width = 12;
    int height = 7;
    for (int i = 0; i < height; i++, y++;) {
        gotoxy(x,y);
        cout << string(width, ' ');
    }
}

void Pawn::print() {
    Coord c = getCursorPos();
    int x = c.x;
    int y = c.y;

    y += 2; //to make up for pawn being 2 short
    gotoxy(x,y);

    cout << "   .-\"-.    "; y++; gotoxy(x,y);
    cout << "   `. .'    "; y++; gotoxy(x,y);
    cout << "   .' '.    "; y++; gotoxy(x,y);
    cout << "  .'___'.   "; y++; gotoxy(x,y);
    cout << "  `-----'   ";
}

void Rook::print() {
    Coord c = getCursorPos();
    int x = c.x;
    int y = c.y;

    cout << "    _   _   "; y++; gotoxy(x,y);
    cout << "   | |_| |  "; y++; gotoxy(x,y);
    cout << "   |     |  "; y++; gotoxy(x,y);
    cout << "   '-----'  "; y++; gotoxy(x,y);
    cout << "   |     |  "; y++; gotoxy(x,y);
    cout << "  /_.---._\\ "; y++; gotoxy(x,y);
    cout << "  '._____.' ";
}

void Knight::print() {
    Coord c = getCursorPos();
    int x = c.x;
    int y = c.y;

    y += 2; //to make up for horse being 1 short
    gotoxy(x,y);

    cout << "   |\\.      "; y++; gotoxy(x,y);
    cout << "  /   '.    "; y++; gotoxy(x,y);
    cout << " /_.'-  \\   "; y++; gotoxy(x,y);
    cout << "    /   |   "; y++; gotoxy(x,y);
    cout << "   /____|   "; y++; gotoxy(x,y);
    cout << "  `.____.'  ";
}

void Bishop::print() {
    cout << "    .-.     "; y++; gotoxy(x,y);
    cout << "   .' '.    "; y++; gotoxy(x,y);
    cout << "   (   )    "; y++; gotoxy(x,y);
    cout << "   `. .'    "; y++; gotoxy(x,y);
    cout << "    | |     "; y++; gotoxy(x,y);
    cout << "  ._' '_.   "; y++; gotoxy(x,y);
    cout << "  '--^--'   ";
}

void Queen::print() {
    cout << "    o   o   "; y++; gotoxy(x,y);
    cout << "o   /\ /\  o"; y++; gotoxy(x,y);
    cout << "\`.'  `  `'/"; y++; gotoxy(x,y);
    cout << " \        / "; y++; gotoxy(x,y);
    cout << "  \_.--._/  "; y++; gotoxy(x,y);
    cout << "  '.____.'  ";
}

void King::print() {
    cout << "     _      "; y++; gotoxy(x,y);
    cout << "    ( )     "; y++; gotoxy(x,y);
    cout << " .-. ^ .-.  "; y++; gotoxy(x,y);
    cout << ":   `.'   : "; y++; gotoxy(x,y);
    cout << "`.       .' "; y++; gotoxy(x,y);
    cout << " )_.---._(  "; y++; gotoxy(x,y);
    cout << " `._____.'  ";
}