#include "engineValidStates.h"

bool EcanMoveFrom(Board &board, std::int16_t row, std::int16_t col)
{
    // if row or col are negative or out of bounds
    if (col < 0 || row < 0 || col >= boardSizeSQ || row >= boardSizeSQ)
        return false;
    

    // in this program the player will always be playing with the white pieces
    // if we are trying to move an empty squere, or an white piece
    if (board(row, col) == '.' || !isBlackPiece(board, row, col))
        return false;
    

    return true;
}

bool EcanMoveTo(Board &board, std::int16_t row, std::int16_t col)
{

    if(board(row, col) == '.')
       return true;
    // if row or col are negative or out of bounds
    if (col < 0 || row < 0 || col >= boardSizeSQ || row >= boardSizeSQ)
        return false;
    

    if (isBlackPiece(board, row, col)){
        return false;
    }

    return true;
}


std::vector<std::pair<int, int>> filter(std::vector<std::pair<int, int>> validMoves, Board& board){
    std::vector<std::pair<int, int>> mainValidMoves;

    for (int i = 0; i < validMoves.size(); i++)
    {
        if (validMoves[i].first >= 0 && validMoves[i].second >= 0 && validMoves[i].first < boardSizeSQ && validMoves[i].second < boardSizeSQ && EcanMoveTo(board, validMoves[i].first, validMoves[i].second))
        {
            mainValidMoves.push_back(std::make_pair(validMoves[i].first, validMoves[i].second));
        }
    }

    return mainValidMoves;
}
