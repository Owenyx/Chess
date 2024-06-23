#ifndef common_hpp //include gaurd
#define common_hpp

#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>
#include <memory>
#include <windows.h>

using namespace std;

ostream operator<<(ostream &, ROW &);
ostream operator<<(ostream &, Piece &);

using ROW = vector<Piece>;
using BRD = vector<ROW>;
using pptr = unique_ptr<Piece>;

struct Coord {
    Coord(int x, int y);
    int x;
    int y;
    bool operator==(Coord);
};

enum class Colour {
    WHITE,
    BLACK
};

extern Colour turn;

void gotoxy(int x, int y);

void gotocoor(Coord c);

Coord getCursorPos();

Coord operator==(Coord c1, Coord c2);

void vert_line(int h);

#include "Board.hpp"
#include "Pieces.hpp"

//globals


#endif