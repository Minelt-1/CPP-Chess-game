#ifndef SEARCH_H
#define SEARCH_H

#include "../board.h"
#include "../move.h"
#include "score.h"
#include "engineValidStates.h"
#include <random>

std::pair<std::pair<int, int>, int> getPosition(Board &board, std::int16_t row, std::int16_t col);

#endif
