
#include "validStates.h"

bool whiteIsCheck(Board &board, std::int16_t row, std::int16_t col){
    std::vector<std::vector<std::pair<int, int>>> opponentValidMoves;
        //for loop through black pieces
        for (int i = 0; i < boardSizeSQ; i++){
            for (int j = 0; j < boardSizeSQ; j++){
                //if its an black pawn
                if(board(i, j) == Piece::BP){
                    std::vector<std::pair<int, int>> pawnValidMoves;
                    //push back row + 1
                    pawnValidMoves.push_back(std::make_pair(i - 1, j - 1));
                    //right
                    pawnValidMoves.push_back(std::make_pair(i - 1, j + 1));
                    opponentValidMoves.push_back(pawnValidMoves);
                } // if its a black piece but not an black king(to avoid infinite recusion)
                else if (isBlackPiece(board,i, j) && board(i, j) != '.' && board(i, j) != Piece::BK){
                    opponentValidMoves.push_back(validMove(board, i, j));
                }
            }
        }

        for (int i = 0; i < opponentValidMoves.size(); i++){
            for (int j = 0; j < opponentValidMoves[i].size(); j++){
                if(opponentValidMoves[i][j].first == row && opponentValidMoves[i][j].second == col)
                    return true;
            }
        }

        return false;
}

bool blackIsCheck(Board &board, std::int16_t row, std::int16_t col){
    std::vector<std::vector<std::pair<int, int>>> opponentValidMoves;
        //for loop through black pieces
        for (int i = 0; i < boardSizeSQ; i++){
            for (int j = 0; j < boardSizeSQ; j++){
                //if its an white pawn
                if(board(i, j) == Piece::WP){
                    std::vector<std::pair<int, int>> pawnValidMoves;
                    //push back row + 1
                    pawnValidMoves.push_back(std::make_pair(i + 1, j - 1));
                    //right
                    pawnValidMoves.push_back(std::make_pair(i + 1, j + 1));
                    opponentValidMoves.push_back(pawnValidMoves);
                } // if its a white piece but not an black king(to avoid infinite recusion)
                else if (!isBlackPiece(board,i, j) && board(i, j) != '.' && board(i, j) != Piece::WK){
                    opponentValidMoves.push_back(validMove(board, i, j));
                }
            }
        }

        for (int i = 0; i < opponentValidMoves.size(); i++){
            for (int j = 0; j < opponentValidMoves[i].size(); j++){
                if(opponentValidMoves[i][j].first == row && opponentValidMoves[i][j].second == col)
                    return true;
            }
        }

        return false;
}

bool isBlackPiece(Board &board, std::int16_t row, std::int16_t col)
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

bool canMoveFrom(Board &board, std::int16_t row, std::int16_t col)
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
bool canMoveTo(Board &board, std::int16_t row, std::int16_t col)
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
