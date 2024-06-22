#ifndef Pieces_hpp //include gaurd
#define Pieces_hpp

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

#endif