#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <array>
#include <iostream>

inline constexpr int boardSize{64};
inline constexpr int boardSizeSQ{8};

class Board{
    private:
        std::array<std::array<char, boardSizeSQ>, boardSizeSQ> m_board = {
            {
                {Piece::BR, Piece::BN, Piece::BB, Piece::BQ, Piece::BK, Piece::BB, Piece::BN, Piece::BR},
                {Piece::BP, Piece::BP, Piece::BP, Piece::BP, Piece::BP, Piece::BP, Piece::BP, Piece::BP},
                {'.', '.', '.', '.', '.', '.', '.', '.'},
                {'.', '.', '.', '.', '.', '.', '.', '.'},
                {'.', '.', '.', '.', '.', '.', '.', '.'},
                {'.', '.', '.', '.', '.', '.', '.', '.'},
                {Piece::WP, Piece::WP, Piece::WP, Piece::WP, Piece::WP, Piece::WP, Piece::WP, Piece::WP},
                {Piece::WR, Piece::WN, Piece::WB, Piece::WQ, Piece::WK, Piece::WB, Piece::WN, Piece::WR}
            }
        };

    public:
        char &operator()(int row, int col) { return m_board[row][col]; }

        friend std::ostream& operator<<(std::ostream& out, Board board){
            for (int i = 0; i < boardSizeSQ; i++){
                for (int j = 0; j < boardSizeSQ; j++){
                    out << board(i, j) << ' ';
                }
                out << '\n';
            }
            return out;
        }
};

#endif
