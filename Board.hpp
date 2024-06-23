#ifndef Board_hpp //include gaurd
#define Board_hpp

class Board {
  private:
    BRD b; //Board
  public:
    Board();
    void print();
    void move(Coord c1, Coord c2);
    bool valid(Coord c1, Coord c2);
    bool spawnPawn(Coord c);
    bool enPassantable(Coord c); //checks if a given pawn can be killed with en passant
    bool obstructed (Coord c1, Coord c2);
    void set_piece(Coord c, pptr p);
    pptr get_piece(Coord c);
};

#endif