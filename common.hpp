#ifndef common_hpp //include gaurd
#define common_hpp

#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

ostream operator<<(ostream &, ROW &);
ostream operator<<(ostream &, Piece &);

using ROW = vector<Piece>;
using BRD = vector<ROW>;

struct Coord {
    Coord(int r, int c) {
        row = r;
        col = c;
    }
    int row;
    int col;
};

enum class Colour {
    WHITE,
    BLACK,
};

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct Piece {
    Piece(Colour c) { colour = c; }
    const Colour colour;
    const int type;
    virtual void print() = 0;
};

struct None : public Piece { type = 0; }
struct Pawn : public Piece { type = 1; bool just_double_moved == false; }
struct Rook : public Piece { type = 2; }
struct Knight : public Piece { type = 3; }
struct Bishop : public Piece { type = 4; }
struct Queen : public Piece { type = 5; }
struct King : public Piece { type = 6; }

#include "Board.hpp"

#endif