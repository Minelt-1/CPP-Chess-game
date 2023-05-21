#include <iostream>
#include <string>
#include "board.h"
#include "coloumn.h"
#include "move.h"
#include "validStates.h"
#include "engine/mainEngine.h"
#include "engine/search.h"
#include "engine/score.h"
#include <cassert>

// this converts the rows into the rows of white
int rowWhite(int &row)
{
    switch (row)
    {
    case 0:
        row = 7;
        break;
    case 1:
        row = 6;
        break;
    case 2:
        row = 5;
        break;
    case 3:
        row = 4;
        break;
    case 4:
        row = 3;
        break;
    case 5:
        row = 2;
        break;
    case 6:
        row = 1;
        break;
    case 7:
        row = 0;
        break;

    default:
        break;
    }

    return row;
}

int main()
{
    Board board;
    std::cout << board;
    // THIS IS THE MAIN WHILE LOOP
    while (true)
    {
        // THIS WHILE LOOP WILL BE FOR THE PLAYER.
        while (true)
        {
            // Check if an pawn has reached the end
            for (int i = 0; i < boardSizeSQ; i++)
            {
                if (board(0, i) == Piece::WP)
                {
                    board(0, i) = Piece::WQ;
                }
            }
            std::cout << "\nEnter from what you want to move\n";
            std::cout << "\nEnter the column (H - A): ";
            char col;
            std::cin >> col;
            if (std::cin.fail())
            {
                std::cout << "Invalid input!\n";
                continue;
            }
            std::cout << "\nEnter the row (1 - 8): ";
            int row;
            std::cin >> row;
            // we go - 1 because the indexes are 0 - 7 not 1 - 8
            row = row - 1;
            if (std::cin.fail())
            {
                std::cout << "Invalid input!\n";
                continue;
            }

            std::cout << "\nEnter from to where you want to move\n";
            std::cout << "\nEnter the column (H - A): ";
            char colB;
            std::cin >> colB;
            if (std::cin.fail())
            {
                std::cout << "Invalid input!\n";
                continue;
            }
            std::cout << "\nEnter the row (1 - 8): ";
            int rowB;
            std::cin >> rowB;
            rowB = rowB - 1;

            if (std::cin.fail())
            {
                std::cout << "Invalid input!\n";
                continue;
            }

            int icolA{0};
            if (!convertColToInt(col, icolA))
            {
                std::cout << "Cant convert";
                continue;
            }

            int icolB{0};
            if (!convertColToInt(colB, icolB))
            {
                std::cout << "Cant convert";
                continue;
            }

            // this converts the rows into the rows of white
            rowWhite(row);
            rowWhite(rowB);

            std::cout << "Col: " << icolA << '\n'
                      << "Row: " << row << "\nTo col: " << icolB << "\nAnd row: " << rowB << '\n';

            if (canMove(board, row, icolA, rowB, icolB))
            {

                bool swap{true};
                // if white is in checkmate
                if (whiteIsCheck(board, board.getWhiteKingRow(), board.getWhiteKingCol()) && stale)
                {
                    // swap
                    std::swap(board(row, icolA), board(rowB, icolB));
                    // if its in check again.
                    if (whiteIsCheck(board, board.getWhiteKingRow(), board.getWhiteKingCol()))
                    {
                        // THIS SHOULD BE DIFFIRENT FOR AI
                        std::cout << "YOU LOST\n";
                        return 1;
                    }
                }
                // if white is in check
                else if (whiteIsCheck(board, board.getWhiteKingRow(), board.getWhiteKingCol()))
                {
                    // swap
                    Board cBoard = board;

                    if (cBoard(rowB, icolB) != '.')
                        cBoard(rowB, icolB) = '.';
                    std::swap(cBoard(row, icolA), cBoard(rowB, icolB));
                    // if its in check again.
                    if (whiteIsCheck(cBoard, cBoard.getWhiteKingRow(), cBoard.getWhiteKingCol()))
                    {

                        std::cout << board;
                        std::cout << "KING IS IN CHECK!";
                        swap = false;
                        std::swap(cBoard(row, icolA), cBoard(rowB, icolB));
                    }
                    else
                    {

                        if (board(rowB, icolB) != '.')
                            board(rowB, icolB) = '.';
                        std::swap(board(row, icolA), board(rowB, icolB));
                    }
                }
                if (swap)
                {
                    bool isBreak{true};
                    if (board(rowB, icolB) != '.')
                        board(rowB, icolB) = '.';

                    std::swap(board(row, icolA), board(rowB, icolB));
                    // if after we have moved our king is in check
                    if (whiteIsCheck(board, board.getWhiteKingRow(), board.getWhiteKingCol()))
                    {
                        std::cout << "PIECE IS PINNED!\n";
                        std::swap(board(row, icolA), board(rowB, icolB));
                        std::cout << board;
                        isBreak = false;
                    }

                    if (isBreak)
                        break;
                }
            }
            else
            {
                std::cout << "Invalid move!\n";
                std::cout << board;
            }
        }
        if (stale)
        {
            std::cout << "STALEMATE!\n";
            return 1;
        }

        std::cout << board;

        // WHILE LOOP FOR THE AI
        while (true)
        {
            playEngine(board);
            break;
        }

        std::cout << board;
    }

    return 0;
}
