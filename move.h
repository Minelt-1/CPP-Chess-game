#ifndef MOVE_H
#define MOVE_H

#include <algorithm>
#include "board.h"
#include "validStates.h"
#include <vector>
#include <cassert>
#include <cmath>

auto validMove(Board &board, int row, int col);
bool canMove(Board &board, int rowA, int colA, int rowB, int colB);

#endif
