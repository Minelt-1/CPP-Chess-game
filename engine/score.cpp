#include "score.h"

int getScore(Board &board, std::int16_t row, std::int16_t col){
    switch (board(row, col))
    {
    case '.': return 0;
    case Piece::WP: return 10; 
    case Piece::WB: return 30;
    case Piece::WN: return 30;
    case Piece::WR: return 50;
    case Piece::WQ: return 130;
    case Piece::WK: return 900;
    case Piece::BP: return -10; 
    case Piece::BB: return -30;
    case Piece::BN: return -30;
    case Piece::BR: return -50;
    case Piece::BQ: return -130;
    case Piece::BK: return -900;
    
    
    }

    assert(false && "Not supposed to happend");
}
