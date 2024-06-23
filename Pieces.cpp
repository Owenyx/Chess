#include "common.hpp"

None::None() {
    type = 0;
}

Pawn::Pawn(Colour c) {
    colour = c;
    type = 1;
    just_double_moved = false;
}

Rook::Rook(Colour c) {
    colour = c;
    type = 2;
}

Knight::Knight(Colour c) {
    colour = c;
    type = 3;
}

Bishop::Bishop(Colour c) {
    colour = c;
    type = 4;
}

Queen::Queen(Colour c) {
    colour = c;
    type = 5;
}

King::King(Colour c) {
    colour = c;
    type = 6;
}

void None::print() {
    Coord c = getCursorPos();
    int x = c.x;
    int y = c.y;

    int width = 12;
    int height = 7;
    for (int i = 0; i < height; i++, y++) {
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

    y += 1; //to make up for horse being 1 short
    gotoxy(x,y);

    cout << "   |\\.      "; y++; gotoxy(x,y);
    cout << "  /   '.    "; y++; gotoxy(x,y);
    cout << " /_.'-  \\   "; y++; gotoxy(x,y);
    cout << "    /   |   "; y++; gotoxy(x,y);
    cout << "   /____|   "; y++; gotoxy(x,y);
    cout << "  `.____.'  ";
}

void Bishop::print() {
    Coord c = getCursorPos();
    int x = c.x;
    int y = c.y;

    gotoxy(x,y);

    cout << "    .-.     "; y++; gotoxy(x,y);
    cout << "   .' '.    "; y++; gotoxy(x,y);
    cout << "   (   )    "; y++; gotoxy(x,y);
    cout << "   `. .'    "; y++; gotoxy(x,y);
    cout << "    | |     "; y++; gotoxy(x,y);
    cout << "  ._' '_.   "; y++; gotoxy(x,y);
    cout << "  '--^--'   ";
}

void Queen::print() {
    Coord c = getCursorPos();
    int x = c.x;
    int y = c.y;

    y += 1; //to make up for Queen being 1 short
    gotoxy(x,y);

    cout << "    o   o   "; y++; gotoxy(x,y);
    cout << "o   /\\ /\\  o"; y++; gotoxy(x,y);
    cout << "\\`.'  `  `'/"; y++; gotoxy(x,y);
    cout << " \\        / "; y++; gotoxy(x,y);
    cout << "  \\_.--._/  "; y++; gotoxy(x,y);
    cout << "  '.____.'  ";
}

void King::print() {
    Coord c = getCursorPos();
    int x = c.x;
    int y = c.y;

    gotoxy(x,y);

    cout << "     _      "; y++; gotoxy(x,y);
    cout << "    ( )     "; y++; gotoxy(x,y);
    cout << " .-. ^ .-.  "; y++; gotoxy(x,y);
    cout << ":   `.'   : "; y++; gotoxy(x,y);
    cout << "`.       .' "; y++; gotoxy(x,y);
    cout << " )_.---._(  "; y++; gotoxy(x,y);
    cout << " `._____.'  ";
}