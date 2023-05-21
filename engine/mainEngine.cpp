#include "mainEngine.h"

/*
HAVE 6 GLOBAL VARIABLES:
SCORE, TIMES, ROWA, COLA, ROWB, COLB
FOR LOOP THROUGH THE BOARD
IF ITS A BLACK PIECE AND NOT AN EMPTY SQUERE{
    GET POSITION
    IF POSITION TIMES IS LOWER AND IF POSITION SCORE IS LOWER{
        TIMES = POSITION TIMES
        SCORE = POSITION SCORE
        ROWA = I
        COLA = J
        ROWB = POSITION A
        COLB = POSITION B
    }
}

SWAP THE BOARD(ROWA, COLA) WITH BOARD(ROWB, COLB)
*/

void playEngine(Board &board)
{
    int score{-10}, rowA{0}, colA{0}, rowB{0}, colB{0};
    for (int i = 0; i < boardSizeSQ; i++)
    {
        for (int j = 0; j < boardSizeSQ; j++)
        {
            if (isBlackPiece(board, i, j) && board(i, j) != '.')
            {
                auto pos = getPosition(board, i, j);
                std::cout << "GOING THROUGH: " << board(i, j) << '\n';
                if (pos.second > score)
                {
                    std::cout << "FOUMD: " << score << " It Was: " << pos.second << '\n';
                    int cScore = score;
                    int cRowA = rowA;
                    int cRowB = rowB;
                    int cColA = colA;
                    int cColB = colB;
                    score = pos.second;
                    rowA = i;
                    colA = j;
                    rowB = pos.first.first;
                    colB = pos.first.second;

                    if ((board(i, j) == Piece::BP && board(pos.first.first, pos.first.second) != '.'))
                    {
                        if (board(pos.first.first, pos.first.second) == board(i + 1, j) || board(pos.first.first, pos.first.second) == board(i + 1, j))
                        {
                            score = cScore;
                            rowA = cRowA;
                            rowB = cRowB;
                            colA = cColA;
                            colB = cColB;
                        }
                    }
                    std::cout << rowA << ',' << colA << ',' << rowB << ',' << colB << '\n';
                }
            }
        }
    }

    // if none of them can take any piece then pick a random move
    if (score == 0)
    {
        while(true){
        auto blackPieces = getBlackMoves(board);

        std::random_device rd{};
        std::seed_seq seed{rd(), rd(), rd(), rd()};
        std::mt19937 random{seed};
        std::uniform_int_distribution<> uid{0, static_cast<int>(blackPieces.size() - 1)};
        int index = uid(random);

        auto pos = getPosition(board, blackPieces[index].first, blackPieces[index].second);
    
        score = pos.second;
        rowA = blackPieces[index].first;
        colA = blackPieces[index].second;
        rowB = pos.first.first;
        colB = pos.first.second;
        if(pos.second >= 0){
                break;
        }
        }
    }

    if (board(rowB, colB))
        board(rowB, colB) = '.';

    std::swap(board(rowA, colA), board(rowB, colB));
}
