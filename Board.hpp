#ifndef Board_hpp //include gaurd
#define Board_hpp

class Board {
  private:
    vector<vector<Piece>>[8][8] b; //Board
  public:
    Board();
    void print();
    void move(Coord c1, Coord c2);
    bool valid(Coord c1, Coord c2);
    bool spawnPawn(Coord c);
    bool enPassantable(Coord c); //checks if a given pawn can be killed with en passant
    void set_piece(Coord c, Piece p);
    Piece get_piece(Coord c);
};

#endif