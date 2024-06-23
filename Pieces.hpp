#ifndef Pieces_hpp //include gaurd
#define Pieces_hpp

struct Piece {
    Colour colour;
    int type;
    virtual void print() = 0;
};

struct None : public Piece { None(); void print(); };
struct Pawn : public Piece { Pawn(Colour c); void print(); bool just_double_moved; };
struct Rook : public Piece { Rook(Colour c); void print(); };
struct Knight : public Piece { Knight(Colour c); void print(); };
struct Bishop : public Piece { Bishop(Colour c); void print(); };
struct Queen : public Piece { Queen(Colour c); void print(); };
struct King : public Piece { King(Colour c); void print(); };

#endif