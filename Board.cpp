#include "common.hpp"

Board::Board() {
    b = BRD {
        {Rook(Colour::BLACK),Knight(Colour::BLACK),Bishop(Colour::BLACK),Queen(Colour::BLACK),King(Colour::BLACK),Bishop(Colour::BLACK),Knight(Colour::BLACK),Rook(Colour::BLACK)},
        {Pawn(Colour::BLACK),Pawn(Colour::BLACK),Pawn(Colour::BLACK),Pawn(Colour::BLACK),Pawn(Colour::BLACK),Pawn(Colour::BLACK),Pawn(Colour::BLACK),Pawn(Colour::BLACK)},
        {None(),None(),None(),None(),None(),None(),None(),None()},
        {None(),None(),None(),None(),None(),None(),None(),None()},
        {None(),None(),None(),None(),None(),None(),None(),None()},
        {None(),None(),None(),None(),None(),None(),None(),None()},
        {Pawn(Colour::WHITE),Pawn(Colour::WHITE),Pawn(Colour::WHITE),Pawn(Colour::WHITE),Pawn(Colour::WHITE),Pawn(Colour::WHITE),Pawn(Colour::WHITE),Pawn(Colour::WHITE)},
        {Rook(Colour::WHITE),Knight(Colour::WHITE),Bishop(Colour::WHITE),Queen(Colour::WHITE),King(Colour::WHITE),Bishop(Colour::WHITE),Knight(Colour::WHITE),Rook(Colour::WHITE)}
    };
    //set correct colours
}

void Board::print() {
    int x = 0;
    int y = 0;
    int width = 12; //of the widest piece
    int height = 7; //of the tallest piece
    string horz_line(width*8 + 9, ' '); //8 spaces per row + 9 seperating lines gives total width

    for (int r=0; r<8; r++) {
        x = 0;
        gotoxy(x,y);
        cout << horz_line << endl;
        y++; //each endl incurs a row increase
        vert_line(height); //left edge
        x++;
        for (int c=0; c<8; c++) {
            gotoxy(x,y);
            get_piece(Coord(r,c))->print();
            x += width;
            gotoxy(x,y);
            vert_line(height);
            x++;
        }
        y += height;
    }
}

void Board::move(Coord c1, Coord c2) { //g
    if (valid(c1, c2)) {
        set_piece(c2, get_piece(c1));
        set_piece(c1, make_unique<None>());
    }
}

bool Board::valid(Coord c1, Coord c2) { //basically all of the moving logic ;)

    //check not moving
    if (c1 == c2)
        return false; //piece didn't move, invalid

    //check OOB
    if (c1.x < 0 || c1.x > 7 || c1.y < 0 || c1.y > 7 ||
        c2.x < 0 || c2.x > 7 || c2.y < 0 || c2.y > 7)
        return false; //OOB

    auto p1 = get_piece(c1);
    auto p2 = get_piece(c2);
    
    //check if the piece belongs to that player
    if (p1->colour != turn)
        return false; //doesn't belong

    //check that the moving space is not empty
    if (p1->type == 0)
        return false; //empty
    
    //check friendly fire
    if (p2->type != 0 && p1->colour == p2->colour)
        return false; //friendly fire!
    
    if (p1->type == 1) { //PAWN -- add a check for piece swapping
        if (turn == Colour::WHITE) {
            
            if (c2.x != c1.x - 1) 
                return false; //if c2 is not right above, invalid
                
            if (p2->type != 0)  //if the destination is an enemy
                if (abs(c2.y - c1.y) == 1)
                    return true; //and enemy is 1 to either side, valid
            
            else { //if destination is empty
                if (c2.y == c1.y || (enPassantable(c2) && abs(c2.y - c1.y) == 1))
                    return true; //and c1 and c2 on same column, or en passant is possible, valid
            }
        }
        else { //if black turn

            if (c2.x != c1.x + 1) 
                return false; //if c2 is not right below, invalid
                
            if (p2->type != 0) { //if the destination is an enemy
                if (abs(c2.y - c1.y) == 1)
                    return true; //and enemy is 1 to either side, valid
            }
            
            else { //if destination is empty
                if (c2.y == c1.y || (enPassantable(c2) && abs(c2.y - c1.y) == 1))
                    return true; //And c1 and c2 on same column, or en passant is possible, valid
            }
        }
    }

    if (p1->type == 2) { //ROOK
        if (!(c1.x == c2.x || c1.y == c2.y))
            return false; //if c2 not on the same row or column, invalid

        if (obstructed(c1, c2))
            return false;
        
        return true; //otherwise valid
    }

    if (p1->type == 3) { //KNIGHT
        if (
        abs(c1.x - c2.x) == 2 && abs(c1.y - c2.y) == 1 //if 2 row moves and 1 col
        || 
        abs(c1.x - c2.x) == 1 && abs(c1.y - c2.y) == 2 //or 2 col moves and 1 row
        )
            return true; //move valid
    }

    if (p1->type == 4) { //BISHOP
        if (!(abs(c1.x - c2.x) == abs(c1.y - c2.y))) //if move is not diagonal
            return false; //invalid
        
        if (obstructed(c1, c2))
            return false;
        
        return true; //otherwise move is valid
    }

    if (p1->type == 5) { //QUEEN
        if (!((c1.x == c2.x || c1.y == c2.y) //rook rules
        ||
        abs(c1.x - c2.x) == abs(c1.y - c2.y))) //bishop rules
            return false; //if both are invalid, move is invalid
        
        if (obstructed(c1, c2))
            return false;
        
        return true; //otherwise move is valid
    }

    if (p1->type == 6) { //KING
        if (abs(c2.x - c1.x) > 1)
            return false; //if king moves more than 1 row, invalid
        if (abs(c2.y - c1.y) > 1)
            return false; //if king moves more than 1 column, invalid

        //make sure it can't move into check, still need to add check function
    }
}

bool Board::spawnPawn(Coord c) { //g
    unique_ptr<Piece> p = get_piece(c);
    if (p->type = 1 && p->colour == Colour::WHITE && c.x == 6) return true;
    if (p->type = 1 && p->colour == Colour::BLACK && c.x == 1) return true;
    return false;
}

bool Board::enPassantable(Coord c) {
    if (!((c.x == 2 && turn == Colour::WHITE) || (c.x == 5 && turn == Colour::BLACK)))
        return false; //only rows 3 and 6 (on the actual board) can be en passantable
    
    //get the piece that would be advanced
    unique_ptr<Pawn> p = make_unique<Pawn>(Colour::WHITE);
    if (turn == Colour::WHITE)
        p = unique_ptr<Pawn>(dynamic_cast<Pawn*>(get_piece(Coord(c.x - 1, c.y)).release()));
    else
        p = unique_ptr<Pawn>(dynamic_cast<Pawn*>(get_piece(Coord(c.x + 1, c.y)).release()));
        
    if (p->type != 1)
        return false; //has to be a pawn;
        
    if (p->just_double_moved == false)
        return false; //has to have just double moved
        
    return true;
}

bool Board::obstructed (Coord c1, Coord c2) { //works for Q R B

    //horizontal obstructions    

    if (c1.y == c2.y) { //if only row changes
        if (c2.x > c1.x) { //c2 is below c1
            for (int r = c1.x+1; r < c2.x; r++) {
                if (get_piece(Coord(r, c1.y))->type != 0) //if space between pieces not empty
                    return true; //then obstructed
            }
        }
        
        else { //c2 above c1
            for (int r = c1.x-1; r > c2.x; r--) {
                if (get_piece(Coord(r, c1.y))->type != 0) //if space between pieces not empty
                    return true; //then obstructed
            }
        }
    }

    //vertical obstructions

    else if (c1.x == c2.x) { //if only column changes
        if (c2.y > c1.y) { //if c2 is right of c1
            for (int c = c1.y+1; c < c2.y; c++) {
                if (get_piece(Coord(c1.x, c))->type != 0) //if space between pieces not empty
                    return true; //then obstructed
            }
        }

        else { //c2 left of c1
            for (int c = c1.y-1; c > c2.y; c--) {
                if (get_piece(Coord(c1.x, c))->type != 0) //if space between pieces not empty
                    return true; //then obstructed
            }
        }
    }

    //diagonal obstructions
    //------------------
    //dowm right
    else if (c2.x > c1.x && c1.y > c2.y) { 
        for (int r = c1.x+1, c = c1.y+1; r < c2.x, c < c2.y; r++, c++) {
            if (get_piece(Coord(r, c))->type != 0) //if space between pieces not empty
                return true; //then obstructed
        }
    }
    
    //down left
    else if (c2.x > c1.x && c1.y < c2.y) { 
        for (int r = c1.x+1, c = c1.y-1; r < c2.x, c > c2.y; r++, c--) {
            if (get_piece(Coord(r, c))->type != 0) //if space between pieces not empty
                return true; //then obstructed
        }
    }
    
    //up right
    else if (c2.x < c1.x && c1.y > c2.y) { 
        for (int r = c1.x-1, c = c1.y+1; r > c2.x, c < c2.y; r--, c++) {
            if (get_piece(Coord(r, c))->type != 0) //if space between pieces not empty
                return true; //then obstructed
        }
    }
    
    //up left
    else if (c2.x < c1.x && c1.y < c2.y) { 
        for (int r = c1.x-1, c = c1.y-1; r > c2.x, c > c2.y; r--, c--) {
            if (get_piece(Coord(r, c))->type != 0) //if space between pieces not empty
                return true; //then obstructed
        }
    }
    return false; //no obstruction
}

void Board::set_piece(Coord c, unique_ptr<Piece> &p) { b[c.x][c.y] = p; } //g

void Board::set_piece(Coord c, unique_ptr<Piece> &&p) { b[c.x][c.y] = p; } //g

unique_ptr<Piece> Board::get_piece(Coord c) { return make_unique<Piece>(b[c.x][c.y]); } //g
