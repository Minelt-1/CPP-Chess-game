#ifndef MOVEFUN_H
#define MOVEFUN_H

#include "board.h"
#include "move.h"

void moveBlackPawn(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves);
void moveWhitePawn(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves);
void moveBlackBishop(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves);
void moveWhiteBishop(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves);
void moveBlackRock(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves);
void moveWhiteRock(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves);
void moveBlackQueen(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves);
void moveWhiteQueen(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves);
void moveBlackKing(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves);
void moveWhiteKing(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves);
void moveBlackKnight(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves);
void moveWhiteKnight(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves);

#endif
