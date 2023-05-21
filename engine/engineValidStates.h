#ifndef EVALID_H
#define EVALID_H

#include "mainEngine.h"

std::vector<std::pair<int, int>> filter(std::vector<std::pair<int, int>> validMoves, Board &board);
bool EcanMoveFrom(Board &board, std::int16_t row, std::int16_t col);
bool EcanMoveTo(Board &board, std::int16_t row, std::int16_t col);

#endif
