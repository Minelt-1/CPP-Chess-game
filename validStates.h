#ifndef VALIDSTATES_H
#define VALIDSTATES_H

#include "board.h"
#include "move.h"

bool isBlackPiece(Board &board, std::int16_t row, std::int16_t col);
bool canMoveFrom(Board &board, std::int16_t row, std::int16_t col);
bool canMoveTo(Board &board, std::int16_t row, std::int16_t col);
bool whiteIsCheck(Board &board, std::int16_t row, std::int16_t col);
bool blackIsCheck(Board &board, std::int16_t row, std::int16_t col);

#endif
