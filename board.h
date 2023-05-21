#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <array>
#include <iostream>
#include <cassert>
#include <cstdint>

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
        char &operator()(std::int16_t row, std::int16_t col) { return m_board[row][col]; }

        friend std::ostream& operator<<(std::ostream& out, Board board){
            for (int i = 0; i < boardSizeSQ; i++){
                for (int j = 0; j < boardSizeSQ; j++){
                    out << board(i, j) << ' ';
                }
                out << '\n';
            }
            return out;
        }

        auto& getWhiteKing(){
            for (int i = 0; i < boardSizeSQ; i++){
                for (int j = 0; j < boardSizeSQ; j++){
                    if(m_board[i][j] == Piece::WK){
                        return m_board[i][j];
                    }
                }
            }
            assert(false && "Couldnt find king!");
        }

        std::int16_t getWhiteKingRow(){
            for (int i = 0; i < boardSizeSQ; i++){
                for (int j = 0; j < boardSizeSQ; j++){
                    if(m_board[i][j] == Piece::WK){
                        return i;
                    }
                }
            }
            assert(false && "Couldnt find king!");
        }

        
        std::int16_t getWhiteKingCol(){
            for (int i = 0; i < boardSizeSQ; i++){
                for (int j = 0; j < boardSizeSQ; j++){
                    if(m_board[i][j] == Piece::WK){
                        return j;
                    }
                }
            }
            assert(false && "Couldnt find king!");
        }

        auto& getBlackKing(){
            for (int i = 0; i < boardSizeSQ; i++){
                for (int j = 0; j < boardSizeSQ; j++){
                    if(m_board[i][j] == Piece::BK){
                        return m_board[i][j];
                    }
                }
            }
            assert(false && "Couldnt find king!");
        }

        std::int16_t getBlackKingRow(){
            for (int i = 0; i < boardSizeSQ; i++){
                for (int j = 0; j < boardSizeSQ; j++){
                    if(m_board[i][j] == Piece::BK){
                        return i;
                    }
                }
            }
            assert(false && "Couldnt find king!");
        }

        std::int16_t getBlackKingCol(){
            for (int i = 0; i < boardSizeSQ; i++){
                for (int j = 0; j < boardSizeSQ; j++){
                    if(m_board[i][j] == Piece::BK){
                        return j;
                    }
                }
            }
            assert(false && "Couldnt find king!");
        }

};

#endif
