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
    Coord(int r, int c);
    int row;
    int col;
};

enum class Colour {
    WHITE,
    BLACK,
};

void gotoxy(int x, int y);

void gotocoor(Coord c);

Coord getCursorPos();

Coord operator=(Coord c1, COORD c2);

void vert_line(int h);

#include "Board.hpp"
#include "Pieces.hpp"

#endif