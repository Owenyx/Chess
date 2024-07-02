
#include "common.hpp"
#include "Board.hpp"

int main()
{
    turn = Colour::WHITE;

    clearScreen();
    Board b;
    b.print();
    cout << "\nWhite's Turn";
    bool success = false;
    while (!success)
    {
        Coord src = b.selectPiece();
        b.highlightPiece(src); //highlights the piece selected
        Coord dst = b.selectPiece();
        success = b.move(src, dst);
        cout << "Invalid move, try again\n";
    }

    //set just_double_moved to false for all opposing coloured pawns at end of EACH turn

    //change turn
    if (turn == Colour::WHITE)
        turn = Colour::BLACK;
    else 
        turn = Colour::WHITE;

    return 0;
}