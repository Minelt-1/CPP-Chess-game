#include "move.h"

std::vector<std::pair<int, int>> getBlackMoves(Board& board){
    std::vector<std::pair<int, int>> blackPieces;

    for (int i = 0; i < boardSizeSQ; i++){
        for (int j = 0; j < boardSizeSQ; j++){
         if(isBlackPiece(board, i, j)){
             blackPieces.push_back(std::make_pair(i, j));
         }
       }
    }

    return blackPieces;
}

std::vector<std::pair<int, int>> validMove(Board &board, std::int16_t row, std::int16_t col)
{
    // this is the vector for valid moves
    std::vector<std::pair<int, int>> validMoves;
    // If you wonder for what found variables are used. read readMe.md
    switch (board(row, col))
    {
    // Pawn
    case Piece::BP:
    {
        moveBlackPawn(board, row, col, validMoves);

        break;
    }
    case Piece::WP:
    {
        moveWhitePawn(board, row, col, validMoves);

        break;
    }
    // Bishop
    case Piece::BB:
    {
        moveBlackBishop(board, row, col, validMoves);

        break;
    }

    case Piece::WB:
    {
        moveWhiteBishop(board, row, col, validMoves);

        break;
    }

    case Piece::BR:
    {
        moveBlackRock(board, row, col, validMoves);

        break;
    }
    case Piece::WR:
    {
        moveWhiteRock(board, row, col, validMoves);

        break;
    }
    case Piece::BQ:
    {

        moveBlackQueen(board, row, col, validMoves);

        break;
    }
    case Piece::WQ:
    {
        moveWhiteQueen(board, row, col, validMoves);

        break;
    }
    case Piece::BK:
    {
        moveBlackKing(board, row, col, validMoves);

        break;
    }
    case Piece::WK:
    {
        moveWhiteKing(board, row, col, validMoves);

        break;
    }
    case Piece::BN:
    {

        moveBlackKnight(board, row, col, validMoves);

        break;
    }
    case Piece::WN:
    {
        moveWhiteKnight(board, row, col, validMoves);

        break;
    }
    case '.':
    {
        
        break;
    } 
    default:
        assert(false && "NO IMPLIMENTATION FOR THAT PIECE");
        break;
    }

    std::vector<std::pair<int, int>> mainValidMoves;

    for (int i = 0; i < validMoves.size(); i++)
    {
        if (validMoves[i].first >= 0 && validMoves[i].second >= 0)
        {
            mainValidMoves.push_back(std::make_pair(validMoves[i].first, validMoves[i].second));
        }
    }

    return mainValidMoves;
}

bool canMove(Board &board, std::int16_t rowA, std::int16_t colA, std::int16_t rowB, std::int16_t colB)
{
    // make sure we can move there, and that squere exists
     if (!(canMoveFrom(board, rowA, colA) && canMoveTo(board, rowB, colB)))
        return false;

    auto validMoves{validMove(board, rowA, colA)};

    // if stale
    if (validMoves.empty() && (board(rowA, colA) == Piece::WK || board(rowA, colA) == Piece::BK))
    {
        stale = true;
        return true;
    }

    std::cout << "\nRowB: " << rowB << '\n';
    std::cout << "ColB: " << colB << '\n';
    for (int i = 0; i < validMoves.size(); i++)
    {
        std::cout << "Array: " << validMoves[i].first << ',' << validMoves[i].second << '\n';

        if (validMoves[i].first == rowB && validMoves[i].second == colB)
        {
            return true;
        }
    }
    return false;
}

// g++-10 -std=c++20 main.cpp coloumn.cpp validStates.cpp move.cpp moveFun.cpp engine/mainEngine.cpp engine/score.cpp engine/search.cpp engine/engineValidStates.cpp
