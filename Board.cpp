#include "common.hpp"

Board::Board() {
    b = MAT {
        {Rook,Knight,Bishop,Queen,King,Bishop,Knight,Rook},
        {Pawn,Pawn,Pawn,Pawn,Pawn,Pawn,Pawn,Pawn},
        {None,None,None,None,None,None,None,None},
        {None,None,None,None,None,None,None,None},
        {None,None,None,None,None,None,None,None},
        {None,None,None,None,None,None,None,None},
        {Pawn,Pawn,Pawn,Pawn,Pawn,Pawn,Pawn,Pawn},
        {Rook,Knight,Bishop,Queen,King,Bishop,Knight,Rook}
    }
}

void Board::print() {
    for (ROW r : b) 
        cout << ROW; //g
}

void Board::move(Coord c1, Coord c2) { //g
    if (valid(c1, c2)) {
        set_piece(c2, get_piece(c1));
        set_piece(c1, NONE);
    }
}

bool Board::valid(Coord c1, Coord c2) { //basically all of the moving logic ;)

    //check OOB
    if (c1.row < 0 || c1.row > 7 || c1.col < 0 || c1.col > 7 ||
        c2.row < 0 || c2.row > 7 || c2.col < 0 || c2.col > 7)
        return false; //OOB

    Piece p1 = get_piece(c1);
    Piece p2 = get_piece(c2);
    
    //check if the piece belongs to that player
    if (p1.colour != turn)
        return false; //doesn't belong

    //check that the moving space is not empty
    if (p1.type == 0)
        return false; //empty
    
    //check friendly fire
    if (p1.colour == p2.colour && p2.type != NONE)
        return false; //friendly fire!
    
    if (p1.type == 1) { //PAWN -- add a check for piece swapping
        if (turn == WHITE) {
            
            if (c2.row != c1.row - 1) 
                return false; //if c2 is not right above, invalid
                
            if (p2.type != 0)  //if the destination is an enemy
                if (abs(c2.col - c1.col) == 1)
                    return true; //and enemy is 1 to either side, valid
            
            else { //if destination is empty
                if (c2.col == c1.col || (enPassantable(c2) && abs(c2.col - c1.col) == 1))
                    return true; //and c1 and c2 on same column, or en passant is possible, valid
            }
        }
        else { //if black turn --- LEFT HERE

            if (c2.row != c1.row + 1) 
                return false; //if c2 is not right below, invalid
                
            if (p2.type != 0) { //if the destination is an enemy
                if (abs(c2.col - c1.col) == 1)
                    return true; //and enemy is 1 to either side, valid
            }
            
            else { //if destination is empty
                if (c2.col == c1.col || (enPassantable(c2) && abs(c2.col - c1.col) == 1))
                    return true; //And c1 and c2 on same column, or en passant is possible, valid
            }
        }
    }

    if (p.type == 2) { //ROOK
        if !(c1.row == c2.row || c1.col == c2.col)
            return false; //if c2 not on the same row or column, invalid
    }

    if (p.type == 3) { //KNIGHT

    }
}

bool Board::spawnPawn(Coord c) { //g
    Piece p = get_piece(c);
    if (p.type = 1 && p.Colour == WHITE && c.row == 6) return true;
    if (p.type = 1 && p.Colour == BLACK && c.row == 1) return true;
    return false;
}

bool Board::enPassantable(Coord c) {
    if !((c.row == 2 && turn == WHITE) || (c.row == 5 && turn == BLACK))
        return false; //only rows 3 and 6 (on the actual board) can be en passantable
    
    //get the piece that would be advanced
    Piece p;
    if (turn == WHITE)
        p = get_piece(Coord(c2.row - 1, c2.col));
    else
        p = get_piece(Coord(c2.row + 1, c2.col));
        
    if (p.type != 1)
        return false; //has to be a pawn;
        
    if (p.just_double_moved == false)
        return false; //has to have just double moved
        
    return true;
}

void Board::set_piece(Coord c, Piece p) { b[c.row][c.col] = p; } //g

Piece Board::get_piece(Coord c) { return b[c.row][c.col]; } //g