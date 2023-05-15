
#include "validStates.h"

bool isBlackPiece(Board &board, int row, int col)
{
    // NOTE: '.' falls into false. 
    switch (board(row, col))
    {
    case Piece::BB:
    case Piece::BN:
    case Piece::BP:
    case Piece::BQ:
    case Piece::BK:
    case Piece::BR:
        return true;
    }
    return false;
}

bool canMoveFrom(Board &board, int row, int col)
{
    // if row or col are negative or out of bounds
    if (col < 0 || row < 0 || col >= boardSizeSQ || row >= boardSizeSQ)
        return false;
    

    // in this program the player will always be playing with the white pieces
    // if we are trying to move an empty squere, or an black piece
    if (board(row, col) == '.' || isBlackPiece(board, row, col))
        return false;
    

    return true;
}
bool canMoveTo(Board &board, int row, int col)
{

    if(board(row, col) == '.')
       return true;
    // if row or col are negative or out of bounds
    if (col < 0 || row < 0 || col >= boardSizeSQ || row >= boardSizeSQ)
        return false;
    

    if (!isBlackPiece(board, row, col)){
        std::cout << "Cant move to a WHITE PIECE\n";
        return false;
    }
    

    return true;
}
