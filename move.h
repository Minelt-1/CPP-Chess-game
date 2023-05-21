#ifndef MOVE_H
#define MOVE_H

#include <algorithm>
#include "board.h"
#include "validStates.h"
#include "moveFun.h"
#include <vector>
#include <cassert>
#include <cmath>

// stalemate
inline bool stale{false};

std::vector<std::pair<int, int>> getBlackMoves(Board &board);
std::vector<std::pair<int, int>> validMove(Board &board, std::int16_t row, std::int16_t col);
bool canMove(Board &board, std::int16_t rowA, std::int16_t colA, std::int16_t rowB, std::int16_t colB);

#endif
