#ifndef VALIDSTATES_H
#define VALIDSTATES_H

#include "board.h"

bool isBlackPiece(Board &board, int row, int col);
bool canMoveFrom(Board &board, int row, int col);
bool canMoveTo(Board &board, int row, int col);

#endif
