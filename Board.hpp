#ifndef Board_hpp //include gaurd
#define Board_hpp

#include "common.hpp"
#include "Pieces.hpp"

class Board {
  private:
    BRD b; //Board
  public:
    Board();
    void print();
    bool move(Coord c1, Coord c2); //ret true if success, 1 if not, along with actually moving the piece
    bool valid(Coord c1, Coord c2);
    Coord selectPiece(); //gets a mouse input and converts it into a Coord of the clicked piece
    void highlightPiece(Coord c);
    bool spawnPawn(Coord c);
    bool enPassantable(Coord c); //checks if a given pawn can be killed with en passant
    bool obstructed (Coord c1, Coord c2);
    void set_piece(Coord c, shared_ptr<Piece> &p);
    void set_piece(Coord c, shared_ptr<Piece> &&p);
    shared_ptr<Piece> get_piece(Coord c);
};

#endif