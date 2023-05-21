#include "search.h"

std::pair<std::pair<int, int>, int> getPosition(Board &board, std::int16_t row, std::int16_t col)
{
    auto validMoves = filter(validMove(board, row, col), board);
    std::pair<int, int> bestMove;
    int maxScore{-1};
    if(validMoves.empty()){
        return std::make_pair(bestMove, maxScore);
    }

    for (auto move : validMoves)
    {

        int score = getScore(board, move.first, move.second);

        if (score > maxScore)
        {
            maxScore = score;
            bestMove = std::make_pair(move.first, move.second);
        }
    }
    // if it didnt find any pick a random move
    if (maxScore == 0)
    {
         std::random_device rd{};
         std::seed_seq seed{rd(), rd(), rd(), rd()};
         std::mt19937 random{seed};
         std::uniform_int_distribution<> uid{0, static_cast<int>(validMoves.size() - 1)};
         int index = uid(random);

         bestMove = std::make_pair(validMoves[index].first, validMoves[index].second);
    }

    std::cout << "getPosition(): currentMove: " << maxScore << " BestMove: " << bestMove.first << ',' << bestMove.second << '\n';
    return std::make_pair(bestMove, maxScore);
}
