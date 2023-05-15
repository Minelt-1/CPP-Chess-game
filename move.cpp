#include "move.h"

auto validMove(Board &board, int row, int col){
    std::vector<std::pair<int, int>> validMoves;

    switch (board(row, col))
    {
    //Pawn
    case Piece::BP:
    case Piece::WP:
        //push the next row
        validMoves.push_back(std::make_pair<int, int>(row - 1, col + 1 - 1));
        // if theres something in the next row then pop
        if(board(row - 1, col) != '.'){
            validMoves.pop_back();
        }
        // push the next next row
        validMoves.push_back(std::make_pair<int, int>(row - 2, col + 1 - 1));
        // if theres something in the next next row then pop
        if(board(row - 2, col) != '.'){
            validMoves.pop_back();
        }

        //check whether there is a black piece in the right diagonal position
        if(isBlackPiece(board, row - 1, col + 1)){
            validMoves.push_back(std::make_pair<int, int>(row - 1, col + 1));
        }

        //check whether there is a black piece in the left diagonal position
        if(isBlackPiece(board, row - 1, col - 1)){
            validMoves.push_back(std::make_pair<int, int>(row - 1, col - 1));
        }

        break;
    default:
    assert(false && "???!");
    break;
    }

    return validMoves;
}

bool canMove(Board &board, int rowA, int colA, int rowB, int colB){
    // make sure we can move there, and that squere exists
    
    if(!(canMoveFrom(board, rowA, colA) && canMoveTo(board, rowB, colB)))
    return false;

    auto validMoves{validMove(board, rowA, colA)};
    const int size = {sizeof(validMoves) / sizeof(validMoves[0])};
    std::cout << "\nRowB: " << rowB << '\n';
    std::cout << "ColB: " << colB << '\n';
    for (int i = 0; i < size; i++)
    {
        std::cout << "Array: " << validMoves[i].first << ',' << validMoves[i].second << '\n';

        if(validMoves[i].first == rowB && validMoves[i].second == colB)
        {
            return true;
        }
    }
    return false;
}

// g++-10 -std=c++20 main.cpp coloumn.cpp validStates.cpp move.cpp
