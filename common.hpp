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

struct Piece {
    Piece(Colour c) { colour = c; }
    const Colour colour;
    const int type;
};

struct None : public Piece { type = 0; }
struct Pawn : public Piece { type = 1; bool just_double_moved == false; }
struct Rook : public Piece { type = 2; }
struct Knight : public Piece { type = 3; }
struct Bishop : public Piece { type = 4; }
struct Queen : public Piece { type = 5; }
struct King : public Piece { type = 6; }

ostream operator<<(ostream &o, ROW &r) { for (Piece p : r) cout << p; };

ostream operator<<(ostream &o, Piece &p) {
    switch(p) {
        case NONE: print_none();
        case PAWN: print_pawn();
        case ROOK: print_pawn();
        case KNIGHT: print_pawn();
        case BISHOP: print_pawn();
        case QUEEN: print_pawn();
        case KING: print_pawn();
    }
}

#endif