#include "common.hpp"

Board::Board() {
    b = BRD {
        {Rook,Knight,Bishop,Queen,King,Bishop,Knight,Rook},
        {Pawn,Pawn,Pawn,Pawn,Pawn,Pawn,Pawn,Pawn},
        {None,None,None,None,None,None,None,None},
        {None,None,None,None,None,None,None,None},
        {None,None,None,None,None,None,None,None},
        {None,None,None,None,None,None,None,None},
        {Pawn,Pawn,Pawn,Pawn,Pawn,Pawn,Pawn,Pawn},
        {Rook,Knight,Bishop,Queen,King,Bishop,Knight,Rook}
    }
    //set correct colours
}

void Board::print() {
    int x = 0;
    int y = 0;
    int width = 50;
    int height = 50;
    for (ROW r : b) {
        for (int i=0; i < width; i++)
            cout << '-'
        for (Piece p : r) {
            p.print();
            //ver line
        }
    }
}

void Board::move(Coord c1, Coord c2) { //g
    if (valid(c1, c2)) {
        set_piece(c2, get_piece(c1));
        set_piece(c1, NONE);
    }
}

bool Board::valid(Coord c1, Coord c2) { //basically all of the moving logic ;)

    //check not moving
    if (c1 == c2)
        return false; //piece didn't move, invalid

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
        else { //if black turn

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

    if (p1.type == 2) { //ROOK
        if !(c1.row == c2.row || c1.col == c2.col)
            return false; //if c2 not on the same row or column, invalid

        if (obstructed(c1, c2))
            return false;
        
        return true; //otherwise valid
    }

    if (p1.type == 3) { //KNIGHT
        if (
        abs(c1.row - c2.row) == 2 && abs(c1.col - c2.col) == 1 //if 2 row moves and 1 col
        || 
        abs(c1.row - c2.row) == 1 && abs(c1.col - c2.col) == 2 //or 2 col moves and 1 row
        )
            return true; //move valid
    }

    if (p1.type == 4) { //BISHOP
        if !(abs(c1.row - c2.row) == abs(c1.col - c2.col)) //if move is not diagonal
            return false; //invalid
        
        if (obstructed(c1, c2))
            return false;
        
        return true; //otherwise move is valid
    }

    if (p1.type == 5) { //QUEEN
        if !(c1.row == c2.row || c1.col == c2.col //rook rules
        ||
        abs(c1.row - c2.row) == abs(c1.col - c2.col)) //bishop rules
            return false; //if both are invalid, move is invalid
        
        if (obstructed(c1, c2))
            return false;
        
        return true; //otherwise move is valid
    }

    if (p1.type == 6) { //KING
        if (abs(c2.row - c1.row) > 1)
            return false; //if king moves more than 1 row, invalid
        if (abs(c2.col - c1.col) > 1)
            return false; //if king moves more than 1 column, invalid

        //make sure it can't move into check, still need to add check function
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

bool Board::obstructed (Coord c1, Coord c2) { //works for Q R B

    //horizontal obstructions    

    if (c1.col == c2.col) { //if only row changes
        if (c2.row > c1.row) { //c2 is below c1
            for (int r = c1.row+1; r < c2.row; r++) {
                if (get_piece(Coord(r, c1.col)).type != 0) //if space between pieces not empty
                    return true; //then obstructed
            }
        }
        
        else { //c2 above c1
            for (int r = c1.row-1; r > c2.row; r--) {
                if (get_piece(Coord(r, c1.col)).type != 0) //if space between pieces not empty
                    return true; //then obstructed
            }
        }
    }

    //vertical obstructions

    else if (c1.row == c2.row) { //if only column changes
        else if (c2.col > c1.col) { //if c2 is right of c1
            for (int c = c1.col+1; c < c2.col; r++) {
                if (get_piece(Coord(c1.row, c)).type != 0) //if space between pieces not empty
                    return true; //then obstructed
            }
        }

        else { //c2 left of c1
            for (int c = c1.col-1; c > c2.col; c--) {
                if (get_piece(Coord(c1.row, c)).type != 0) //if space between pieces not empty
                    return true; //then obstructed
            }
        }
    }

    //diagonal obstructions
    //------------------
    //dowm right
    else if (c2.row > c1.row && c1.col > c2.col) { 
        for (int r = c1.row+1, int c = c1.col+1; r < c2.row, c < c2.col; r++, c++) {
            if (get_piece(Coord(r, c)).type != 0) //if space between pieces not empty
                return true; //then obstructed
        }
    }
    
    //down left
    else if (c2.row > c1.row && c1.col < c2.col) { 
        for (int r = c1.row+1, int c = c1.col-1; r < c2.row, c > c2.col; r++, c--) {
            if (get_piece(Coord(r, c)).type != 0) //if space between pieces not empty
                return true; //then obstructed
        }
    }
    
    //up right
    else if (c2.row < c1.row && c1.col > c2.col) { 
        for (int r = c1.row-1, int c = c1.col+1; r > c2.row, c < c2.col; r--, c++) {
            if (get_piece(Coord(r, c)).type != 0) //if space between pieces not empty
                return true; //then obstructed
        }
    }
    
    //up left
    else if (c2.row < c1.row && c1.col < c2.col) { 
        for (int r = c1.row-1, int c = c1.col-1; r > c2.row, c > c2.col; r--, c--) {
            if (get_piece(Coord(r, c)).type != 0) //if space between pieces not empty
                return true; //then obstructed
        }
    }
    return false; //no obstruction
}

void Board::set_piece(Coord c, Piece p) { b[c.row][c.col] = p; } //g

Piece Board::get_piece(Coord c) { return b[c.row][c.col]; } //g