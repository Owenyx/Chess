#ifndef Pieces_hpp //include gaurd
#define Pieces_hpp

struct Piece {
    Colour colour;
    int type;
    virtual void print(int x, int y) = 0;
};

struct None : public Piece { None(); void print(int x, int y); };
struct Pawn : public Piece { Pawn(Colour c); void print(int x, int y); bool just_double_moved; };
struct Rook : public Piece { Rook(Colour c); void print(int x, int y); };
struct Knight : public Piece { Knight(Colour c); void print(int x, int y); };
struct Bishop : public Piece { Bishop(Colour c); void print(int x, int y); };
struct Queen : public Piece { Queen(Colour c); void print(int x, int y); };
struct King : public Piece { King(Colour c); void print(int x, int y); };

#endif