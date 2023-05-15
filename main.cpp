#include <iostream>
#include <string>
#include "board.h"
#include "coloumn.h"
#include "move.h"
#include "validStates.h"
#include <cassert>

//                     CHESS GAME
//
// 1   MAKE AN NAMESPACE OF PIECES AND THE CHARACTERS | FINISHED
// 2   MAKE AN BOARD CLASS | FINISHED
// 3   ON MAIN ASK THE USER WHERE TO MOVE | FINISHED
// 4   THE USER IS GOING TO ENTER FIRST THE COLOUMNS (THE FIRST(H - A) OR THE SECOND(A - H)) | FINISHED
// 5   THE USER IS GOING TO ENTET THE ROWS (THE FIRST(1 - 8) OR THE SECOND(8 - 1)) | FINISHED
// 6   CONVERT THE COLUMNS TO INT | FINISHED
// 7   AFTER THAT MAKE A FUNCTION THAT CHECKS WHETHER THE FIRST INPUT IS CORRECT | FINISHED
// 8   MAKE ANOTHER FUNCTION THAT CHECK THE SECOND INPUT | FINISHED
// 9   AFTER THAT. CHECK WHAT PEICE IS THE FIRST INPUT. BASED OM THAT CHECK WHETHER THE SECOND IS AGAIN VALID | ...
// 10  IF ALL OF THESE ARE VALID THEN SWAP THE ELEMENTS
// 11  THEN MAKE A FUNCTION THAT SEARCHES THROUGH THE ELEMENTS TO FIND THE KING AFTER THAT CHECK WHETHER KING IS IN CHECKMATE
// 12  AFTER WE HAVE SWAPED THEN REPEAT THE STEPS


// this converts the rows into the rows of white
int rowWhite(int& row){
    switch (row)
    {
    case 0: row = 7; break;
    case 1: row = 6; break;
    case 2: row = 5; break;
    case 3: row = 4; break;
    case 4: row = 3; break;
    case 5: row = 2; break;
    case 6: row = 1; break;
    case 7: row = 0; break;

    default: break;
    }

    return row;
}

int main(){
    Board board;
    std::cout << board;
    while (true)
    {
        //Check if an pawn has reached the end
        for (int i = 0; i < boardSizeSQ; i++){
            if(board(0, i) == Piece::WP){
                board(0, i) = Piece::WQ;
            }
        }
            std::cout << "\nEnter from what you want to move\n";
        std::cout << "\nEnter the column (H - A): ";
        char col;
        std::cin >> col;
        if(std::cin.fail()){
            std::cout << "Invalid input!\n";
            continue;
        }
        std::cout << "\nEnter the row (1 - 8): ";
        int row;
        std::cin >> row;
        // we go - 1 because the indexes are 0 - 7 not 1 - 8
        row = row - 1;
        if (std::cin.fail())
        {
            std::cout << "Invalid input!\n";
            continue;
        }

        std::cout << "\nEnter from to where you want to move\n";
        std::cout << "\nEnter the column (H - A): ";
        char colB;
        std::cin >> colB;
        if(std::cin.fail()){
            std::cout << "Invalid input!\n";
            continue;
        }
        std::cout << "\nEnter the row (1 - 8): ";
        int rowB;
        std::cin >> rowB;
        rowB = rowB - 1;
        
        if(std::cin.fail()){
            std::cout << "Invalid input!\n";
            continue;
        }

        int icolA{0};
        if(!convertColToInt(col, icolA)){
            std::cout << "Cant convert";
            continue;
        }


        int icolB{0};
        if(!convertColToInt(colB, icolB)){
            std::cout << "Cant convert";
            continue;
        }

        // this converts the rows into the rows of white
        rowWhite(row);
        rowWhite(rowB);

        std::cout << "Col: " << icolA << '\n'
                  << "Row: " << row << "\nTo col: " << icolB << "\nAnd row: " << rowB << '\n';

        if(canMove(board, row, icolA, rowB, icolB)){

            if(isBlackPiece(board, rowB, icolB))
                board(rowB, icolB) = '.';

            std::swap(board(row, icolA), board(rowB, icolB));
        }
        else
        {
            std::cout << "Invalid move!\n";
        }

        std::cout << board;
    }
    return 0;
}
