#include "moveFun.h"

void moveBlackPawn(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves){
      // push the next row
        validMoves.push_back(std::make_pair<int, int>(row + 1, col + 0));
        // if theres something in the next row then pop
        if (board(row + 1, col) != '.')
        {
            validMoves.pop_back();
        }

        // push the next next row
        if(row == 1)
        validMoves.push_back(std::make_pair<int, int>(row + 2, col + 0));

        // if theres something in the next next row then pop
        if(row == 1){
        if (board(row + 2, col) != '.')
        {
            validMoves.pop_back();
        }}

        // check whether there is a black piece in the right diagonal position
        if (!isBlackPiece(board, row + 1, col + 1) && board(row + 1, col + 1) != '.')
        {
            validMoves.push_back(std::make_pair<int, int>(row + 1, col + 1));
        }

        // check whether there is a black piece in the left diagonal position
        if (!isBlackPiece(board, row + 1, col - 1) && board(row + 1, col - 1) != '.')
        {
            validMoves.push_back(std::make_pair<int, int>(row + 1, col - 1));
        }
}

void moveWhitePawn(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves){

        // push the next row
        validMoves.push_back(std::make_pair<int, int>(row - 1, col + 1 - 1));
        // if theres something in the next row then pop
        if (board(row - 1, col) != '.')
        {
            validMoves.pop_back();
        }

        // push the next next row
        if(row == 6)
        validMoves.push_back(std::make_pair<int, int>(row - 2, col + 1 - 1));

        // if theres something in the next next row then pop
        if(row == 6){
        if (board(row - 2, col) != '.')
        {
            validMoves.pop_back();
        }}

        // check whether there is a black piece in the right diagonal position
        if (isBlackPiece(board, row - 1, col + 1))
        {
            validMoves.push_back(std::make_pair<int, int>(row - 1, col + 1));
        }

        // check whether there is a black piece in the left diagonal position
        if (isBlackPiece(board, row - 1, col - 1))
        {
            validMoves.push_back(std::make_pair<int, int>(row - 1, col - 1));
        }
}
void moveBlackBishop(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves){
     int foundA{0};
        int foundB{0};
        int foundC{0};
        int foundD{0};

        // this is the variable that will be representing which squere is being validated
        int currentSquere{1};

        // calcualte how many rows are down the latter
        int rowDown{boardSizeSQ - row};

        for (int i = 0; i < rowDown; i++)
        {
            // For the right diagonal
            if (!isBlackPiece(board, row - currentSquere, col + currentSquere) && board(row - currentSquere, col + currentSquere) != '.' && foundA == 0)
            {
                validMoves.push_back(std::make_pair<int, int>(row - currentSquere, col + currentSquere));
                foundA++;
            }

            if (!isBlackPiece(board, row - currentSquere, col - currentSquere) && board(row - currentSquere, col - currentSquere) != '.' && foundB == 0)
            {
                validMoves.push_back(std::make_pair<int, int>(row - currentSquere, col - currentSquere));
                foundB++;
            }

            if (isBlackPiece(board, row - currentSquere, col + currentSquere) && board(row - currentSquere, col + currentSquere) != '.')
                foundC++;

            if (isBlackPiece(board, row - currentSquere, col - currentSquere) && board(row - currentSquere, col - currentSquere) != '.')
                foundD++;

            if (board(row - currentSquere, col + currentSquere) == '.' && foundC == 0)
            {
                validMoves.push_back(std::make_pair<int, int>(row - currentSquere, col + currentSquere));
            }

            if (board(row - currentSquere, col - currentSquere) == '.' && foundD == 0)
            {
                validMoves.push_back(std::make_pair<int, int>(row - currentSquere, col - currentSquere));
            }
            currentSquere++;
        }

        int rowUp{row};
        // Reset current squere
        currentSquere = 1;

        // reset the founds

        foundA = 0;
        foundB = 0;
        foundD = 0;
        foundC = 0;

        // for loop how many times the rowup is
        for (int i = 0; i < rowUp; i++)
        {

            if (!isBlackPiece(board, row + currentSquere, col + currentSquere) && board(row + currentSquere, col + currentSquere) != '.' && foundA == 0)
            {
                validMoves.push_back(std::make_pair<int, int>(row + currentSquere, col + currentSquere));
                foundA++;
            }

            if (!isBlackPiece(board, row + currentSquere, col - currentSquere) && board(row + currentSquere, col - currentSquere) != '.' && foundB == 0)
            {
                validMoves.push_back(std::make_pair<int, int>(row + currentSquere, col - currentSquere));
                foundB++;
            }

            if (isBlackPiece(board, row + currentSquere, col + currentSquere) && board(row + currentSquere, col + currentSquere) != '.')
                foundC++;

            if (isBlackPiece(board, row + currentSquere, col - currentSquere) && board(row + currentSquere, col - currentSquere) != '.')
                foundD++;

            if (board(row + currentSquere, col + currentSquere) == '.' && foundC == 0)
            {
                validMoves.push_back(std::make_pair<int, int>(row + currentSquere, col + currentSquere));
            }

            if (board(row + currentSquere, col - currentSquere) == '.' && foundD == 0)
            {
                validMoves.push_back(std::make_pair<int, int>(row + currentSquere, col - currentSquere));
            }

            currentSquere++;
        }
}
void moveWhiteBishop(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves){
     int foundA{0};
        int foundB{0};
        int foundC{0};
        int foundD{0};

        // this is the variable that will be representing which squere is being validated
        int currentSquere{1};

        // calcualte how many rows are down the latter
        int rowDown{boardSizeSQ - row};

        for (int i = 0; i < rowDown; i++)
        {
            // For the right diagonal
            if (isBlackPiece(board, row + currentSquere, col + currentSquere) && foundA == 0)
            {
                validMoves.push_back(std::make_pair<int, int>(row + currentSquere, col + currentSquere));
                foundA++;
            }

            if (isBlackPiece(board, row + currentSquere, col - currentSquere) && foundB == 0)
            {
                validMoves.push_back(std::make_pair<int, int>(row + currentSquere, col - currentSquere));
                foundB++;
            }

            if (!isBlackPiece(board, row + currentSquere, col + currentSquere) && board(row + currentSquere, col + currentSquere) != '.')
                foundC++;

            if (!isBlackPiece(board, row + currentSquere, col - currentSquere) && board(row + currentSquere, col - currentSquere) != '.')
                foundD++;

            if (board(row + currentSquere, col + currentSquere) == '.' && foundC == 0)
            {
                validMoves.push_back(std::make_pair<int, int>(row + currentSquere, col + currentSquere));
            }

            if (board(row + currentSquere, col - currentSquere) == '.' && foundD == 0)
            {
                validMoves.push_back(std::make_pair<int, int>(row + currentSquere, col - currentSquere));
            }
            currentSquere++;
        }

        int rowUp{row};
        // Reset current squere
        currentSquere = 1;

        // reset the founds

        foundA = 0;
        foundB = 0;
        foundD = 0;
        foundC = 0;

        // for loop how many times the rowup is
        for (int i = 0; i < rowUp; i++)
        {

            if (isBlackPiece(board, row - currentSquere, col + currentSquere) && foundA == 0)
            {
                validMoves.push_back(std::make_pair<int, int>(row - currentSquere, col + currentSquere));
                foundA++;
            }

            if (isBlackPiece(board, row - currentSquere, col - currentSquere) && foundB == 0)
            {
                validMoves.push_back(std::make_pair<int, int>(row - currentSquere, col - currentSquere));
                foundB++;
            }

            if (!isBlackPiece(board, row - currentSquere, col + currentSquere) && board(row - currentSquere, col + currentSquere) != '.')
                foundC++;

            if (!isBlackPiece(board, row - currentSquere, col - currentSquere) && board(row - currentSquere, col - currentSquere) != '.')
                foundD++;

            if (board(row - currentSquere, col + currentSquere) == '.' && foundC == 0)
            {
                validMoves.push_back(std::make_pair<int, int>(row - currentSquere, col + currentSquere));
            }

            if (board(row - currentSquere, col - currentSquere) == '.' && foundD == 0)
            {
                validMoves.push_back(std::make_pair<int, int>(row - currentSquere, col - currentSquere));
            }

            currentSquere++;
        }
}
void moveBlackRock(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves){
    for (int i = col - 1; i >= 0; i--)
        {
            if ((isBlackPiece(board, row, i) || !isBlackPiece(board, row, i)) && board(row, i) != '.')
            {
                validMoves.push_back(std::make_pair<int, int>(row + 0, i + 0));
                break;
            }

            validMoves.push_back(std::make_pair<int, int>(row + 0, i + 0));
        }

        for (int i = col + 1; i < boardSizeSQ; i++)
        {
            if ((isBlackPiece(board, row, i) || !isBlackPiece(board, row, i)) && board(row, i) != '.')
            {
                validMoves.push_back(std::make_pair<int, int>(row + 0, i + 0));
                break;
            }

            validMoves.push_back(std::make_pair<int, int>(row + 0, i + 0));
        }

        int foundA{0};
        int foundB{0};

        // push the same col of all rows
        for (int i = 0; i < boardSizeSQ; i++)
        {

            if (!isBlackPiece(board, row - (i + 1), col) && board(row - (i + 1), col) != '.' && foundA == 0)
            {
                validMoves.push_back(std::make_pair<int, int>(row - (i + 1), col + 0));
                foundA++;
            }

            if (!isBlackPiece(board, row + (i + 1), col) && board(row + (i + 1), col) != '.' && foundB == 0)
            {
                validMoves.push_back(std::make_pair<int, int>(row + (i + 1), col + 0));
                foundB++;
            }

            if (isBlackPiece(board, row + (i + 1), col) && board(row + (i + 1), col) != '.')
            {
                foundB++;
            }

            if (isBlackPiece(board, row - (i + 1), col) && board(row - (i + 1), col) != '.')
            {
                foundA++;
            }

            if (board(row - (i + 1), col) == '.' && foundA == 0)
                validMoves.push_back(std::make_pair<int, int>(row - (i + 1), col + 0));

            if (board(row + (i + 1), col) == '.' && foundB == 0)
                validMoves.push_back(std::make_pair<int, int>(row + (i + 1), col + 0));
        }

}
void moveWhiteRock(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves){
    for (int i = col - 1; i >= 0; i--)
        {
            if ((isBlackPiece(board, row, i) || !isBlackPiece(board, row, i)) && board(row, i) != '.')
            {
                validMoves.push_back(std::make_pair<int, int>(row + 0, i + 0));
                break;
            }

            validMoves.push_back(std::make_pair<int, int>(row + 0, i + 0));
        }

        for (int i = col + 1; i < boardSizeSQ; i++)
        {
            if ((isBlackPiece(board, row, i) || !isBlackPiece(board, row, i)) && board(row, i) != '.')
            {
                validMoves.push_back(std::make_pair<int, int>(row + 0, i + 0));
                break;
            }

            validMoves.push_back(std::make_pair<int, int>(row + 0, i + 0));
        }

        int foundA{0};
        int foundB{0};

        // push the same col of all rows
        for (int i = 0; i < boardSizeSQ; i++)
        {

            if (isBlackPiece(board, row + (i + 1), col) && foundA == 0)
            {
                validMoves.push_back(std::make_pair<int, int>(row + (i + 1), col + 0));
                foundA++;
            }

            if (isBlackPiece(board, row - (i + 1), col) && foundB == 0)
            {
                validMoves.push_back(std::make_pair<int, int>(row - (i + 1), col + 0));
                foundB++;
            }

            if (!isBlackPiece(board, row - (i + 1), col) && board(row - (i + 1), col) != '.')
            {
                foundB++;
            }

            if (!isBlackPiece(board, row + (i + 1), col) && board(row + (i + 1), col) != '.')
            {
                foundA++;
            }

            if (board(row + (i + 1), col) == '.' && foundA == 0)
                validMoves.push_back(std::make_pair<int, int>(row + (i + 1), col + 0));

            if (board(row - (i + 1), col) == '.' && foundB == 0)
                validMoves.push_back(std::make_pair<int, int>(row - (i + 1), col + 0));
        }
}
void moveBlackQueen(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves){
     moveBlackRock(board, row, col, validMoves);
     moveBlackBishop(board, row, col, validMoves);
}
void moveWhiteQueen(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves){
     moveWhiteRock(board, row, col, validMoves);
     moveWhiteBishop(board, row, col, validMoves);
}
void moveBlackKing(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves){
      std::vector<std::vector<std::pair<int, int>>> opponentValidMoves;
        //for loop through black pieces
        for (int i = 0; i < boardSizeSQ; i++){
            for (int j = 0; j < boardSizeSQ; j++){
                //if its an black pawn
                if(board(i, j) == Piece::WP){
                    std::vector<std::pair<int, int>> pawnValidMoves;
                    //push back row + 1
                    pawnValidMoves.push_back(std::make_pair(i - 1, j - 1));
                    //right
                    pawnValidMoves.push_back(std::make_pair(i - 1, j + 1));
                    opponentValidMoves.push_back(pawnValidMoves);
                } // if its a black piece but not an white king(to avoid infinite recusion)

                else if (!isBlackPiece(board,i, j) && board(i, j) != '.' && board(i, j) && board(i, j)){
                    opponentValidMoves.push_back(validMove(board, i, j));
                }
            }
        }

        //UP
        bool up{true};

        for (int i = 0; i < opponentValidMoves.size(); i++){
            for (int j = 0; j < opponentValidMoves[i].size(); j++){
            if(opponentValidMoves[i][j].first == row - 1 && opponentValidMoves[i][j].second == col)
                    up = false;
            }
        }

        if(up && (!isBlackPiece(board ,row - 1, col) || board(row - 1, col) == '.')){
            validMoves.push_back(std::make_pair(row - 1, col));
        }

        //DOWN
        bool down{true};

        for (int i = 0; i < opponentValidMoves.size(); i++){
            for (int j = 0; j < opponentValidMoves[i].size(); j++){
            if(opponentValidMoves[i][j].first == row + 1 && opponentValidMoves[i][j].second == col)
                    down = false;
            }
        }

        if(down && (!isBlackPiece(board ,row + 1, col) || board(row + 1, col) == '.')){
            validMoves.push_back(std::make_pair(row + 1, col));
        }

        //LEFT

         bool left{true};

        for (int i = 0; i < opponentValidMoves.size(); i++){
            for (int j = 0; j < opponentValidMoves[i].size(); j++){
            if(opponentValidMoves[i][j].first == row && opponentValidMoves[i][j].second == col - 1)
                    left = false;
            }
        }

        if(left && (!isBlackPiece(board ,row, col - 1) || board(row, col - 1) == '.')){
            validMoves.push_back(std::make_pair(row, col - 1));
        }

        bool upLeft{true};

        for (int i = 0; i < opponentValidMoves.size(); i++){
            for (int j = 0; j < opponentValidMoves[i].size(); j++){
            if(opponentValidMoves[i][j].first == row - 1 && opponentValidMoves[i][j].second == col - 1)
                    upLeft = false;
            }
        }

        if(upLeft && (!isBlackPiece(board ,row - 1, col - 1) || board(row - 1, col - 1) == '.')){
            validMoves.push_back(std::make_pair(row - 1, col - 1));
        }

        bool downLeft{true};

        for (int i = 0; i < opponentValidMoves.size(); i++){
            for (int j = 0; j < opponentValidMoves[i].size(); j++){
            if(opponentValidMoves[i][j].first == row + 1 && opponentValidMoves[i][j].second == col - 1)
                    downLeft = false;
            }
        }

        if(downLeft && (!isBlackPiece(board ,row + 1, col - 1) || board(row + 1, col - 1) == '.')){
            validMoves.push_back(std::make_pair(row + 1, col - 1));
        }

        //right

        bool right{true};

        for (int i = 0; i < opponentValidMoves.size(); i++){
            for (int j = 0; j < opponentValidMoves[i].size(); j++){
            if(opponentValidMoves[i][j].first == row && opponentValidMoves[i][j].second == col + 1)
                    right = false;
            }
        }

        if(right && (!isBlackPiece(board ,row, col + 1) || board(row, col + 1) == '.')){
            validMoves.push_back(std::make_pair(row, col + 1));
        }

        bool upRight{true};

        for (int i = 0; i < opponentValidMoves.size(); i++){
            for (int j = 0; j < opponentValidMoves[i].size(); j++){
            if(opponentValidMoves[i][j].first == row - 1 && opponentValidMoves[i][j].second == col + 1)
                    upRight = false;
            }
        }

        if(upRight && (!isBlackPiece(board ,row - 1, col + 1) || board(row - 1, col + 1) == '.')){
            validMoves.push_back(std::make_pair(row - 1, col + 1));
        }

        bool downRight{true};

        for (int i = 0; i < opponentValidMoves.size(); i++){
            for (int j = 0; j < opponentValidMoves[i].size(); j++){
            if(opponentValidMoves[i][j].first == row + 1 && opponentValidMoves[i][j].second == col + 1)
                    downRight = false;
            }
        }

        if(downRight && (!isBlackPiece(board ,row + 1, col + 1) || board(row + 1, col + 1) == '.')){
            validMoves.push_back(std::make_pair(row + 1, col + 1));
        }

}
void moveWhiteKing(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves){
     std::vector<std::vector<std::pair<int, int>>> opponentValidMoves;
        //for loop through black pieces
        for (int i = 0; i < boardSizeSQ; i++){
            for (int j = 0; j < boardSizeSQ; j++){
                //if its an black pawn
                if(board(i, j) == Piece::BP){
                    std::vector<std::pair<int, int>> pawnValidMoves;
                    //push back row + 1
                    pawnValidMoves.push_back(std::make_pair(i + 1, j - 1));
                    //right
                    pawnValidMoves.push_back(std::make_pair(i + 1, j + 1));
                    opponentValidMoves.push_back(pawnValidMoves);
                } // if its a black piece but not an black king(to avoid infinite recusion)
                else if (isBlackPiece(board,i, j) && board(i, j) != '.' && board(i, j) != Piece::BK){
                    opponentValidMoves.push_back(validMove(board, i, j));
                }
            }
        }

        //UP
        bool up{true};

        for (int i = 0; i < opponentValidMoves.size(); i++){
            for (int j = 0; j < opponentValidMoves[i].size(); j++){
            if(opponentValidMoves[i][j].first == row - 1 && opponentValidMoves[i][j].second == col)
                    up = false;
            }
        }

        if(up && (isBlackPiece(board ,row - 1, col) || board(row - 1, col) == '.')){
            validMoves.push_back(std::make_pair(row - 1, col));
        }

        //DOWN
        bool down{true};

        for (int i = 0; i < opponentValidMoves.size(); i++){
            for (int j = 0; j < opponentValidMoves[i].size(); j++){
            if(opponentValidMoves[i][j].first == row + 1 && opponentValidMoves[i][j].second == col)
                    down = false;
            }
        }

        if(down && (isBlackPiece(board ,row + 1, col) || board(row + 1, col) == '.')){
            validMoves.push_back(std::make_pair(row + 1, col));
        }

        //LEFT

         bool left{true};

        for (int i = 0; i < opponentValidMoves.size(); i++){
            for (int j = 0; j < opponentValidMoves[i].size(); j++){
            if(opponentValidMoves[i][j].first == row && opponentValidMoves[i][j].second == col - 1)
                    left = false;
            }
        }

        if(left && (isBlackPiece(board ,row, col - 1) || board(row, col - 1) == '.')){
            validMoves.push_back(std::make_pair(row, col - 1));
        }

        bool upLeft{true};

        for (int i = 0; i < opponentValidMoves.size(); i++){
            for (int j = 0; j < opponentValidMoves[i].size(); j++){
            if(opponentValidMoves[i][j].first == row - 1 && opponentValidMoves[i][j].second == col - 1)
                    upLeft = false;
            }
        }

        if(upLeft && (isBlackPiece(board ,row - 1, col - 1) || board(row - 1, col - 1) == '.')){
            validMoves.push_back(std::make_pair(row - 1, col - 1));
        }

        bool downLeft{true};

        for (int i = 0; i < opponentValidMoves.size(); i++){
            for (int j = 0; j < opponentValidMoves[i].size(); j++){
            if(opponentValidMoves[i][j].first == row + 1 && opponentValidMoves[i][j].second == col - 1)
                    downLeft = false;
            }
        }

        if(downLeft && (isBlackPiece(board ,row + 1, col - 1) || board(row + 1, col - 1) == '.')){
            validMoves.push_back(std::make_pair(row + 1, col - 1));
        }

        //right

        bool right{true};

        for (int i = 0; i < opponentValidMoves.size(); i++){
            for (int j = 0; j < opponentValidMoves[i].size(); j++){
            if(opponentValidMoves[i][j].first == row && opponentValidMoves[i][j].second == col + 1)
                    right = false;
            }
        }

        if(right && (isBlackPiece(board ,row, col + 1) || board(row, col + 1) == '.')){
            validMoves.push_back(std::make_pair(row, col + 1));
        }

        bool upRight{true};

        for (int i = 0; i < opponentValidMoves.size(); i++){
            for (int j = 0; j < opponentValidMoves[i].size(); j++){
            if(opponentValidMoves[i][j].first == row - 1 && opponentValidMoves[i][j].second == col + 1)
                    upRight = false;
            }
        }

        if(upRight && (isBlackPiece(board ,row - 1, col + 1) || board(row - 1, col + 1) == '.')){
            validMoves.push_back(std::make_pair(row - 1, col + 1));
        }

        bool downRight{true};

        for (int i = 0; i < opponentValidMoves.size(); i++){
            for (int j = 0; j < opponentValidMoves[i].size(); j++){
            if(opponentValidMoves[i][j].first == row + 1 && opponentValidMoves[i][j].second == col + 1)
                    downRight = false;
            }
        }

        if(downRight && (isBlackPiece(board ,row + 1, col + 1) || board(row + 1, col + 1) == '.')){
            validMoves.push_back(std::make_pair(row + 1, col + 1));
        }

       
}
void moveBlackKnight(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves){

        if (board(row + 1, col - 2) == '.' || !isBlackPiece(board, row + 1, col - 2))
            validMoves.push_back(std::make_pair<int, int>(row + 1, col - 2));

        if (board(row + 1, col + 2) == '.' || !isBlackPiece(board, row + 1, col + 2))
            validMoves.push_back(std::make_pair<int, int>(row + 1, col + 2));

        if (board(row + 2, col - 1) == '.' || !isBlackPiece(board, row + 2, col - 1))
            validMoves.push_back(std::make_pair<int, int>(row + 2, col - 1));

        if (board(row + 2, col + 1) == '.' || !isBlackPiece(board, row + 2, col + 1))
            validMoves.push_back(std::make_pair<int, int>(row + 2, col + 1));

        if (board(row - 1, col - 2) == '.' || !isBlackPiece(board, row - 1, col - 2))
            validMoves.push_back(std::make_pair<int, int>(row - 1, col - 2));

        if (board(row - 1, col + 2) == '.' || !isBlackPiece(board, row - 1, col + 2))
            validMoves.push_back(std::make_pair<int, int>(row - 1, col + 2));

        if (board(row - 2, col - 1) == '.' || !isBlackPiece(board, row - 2, col - 1))
            validMoves.push_back(std::make_pair<int, int>(row - 2, col - 1));

        if (board(row - 2, col + 1) == '.' || !isBlackPiece(board, row - 2, col + 1))
            validMoves.push_back(std::make_pair<int, int>(row - 2, col + 1));


}
void moveWhiteKnight(Board& board, std::int16_t row, std::int16_t col, std::vector<std::pair<int, int>>& validMoves){
       if (board(row - 1, col - 2) == '.' || isBlackPiece(board, row - 1, col - 2))
            validMoves.push_back(std::make_pair<int, int>(row - 1, col - 2));

        if (board(row - 1, col + 2) == '.' || isBlackPiece(board, row - 1, col + 2))
            validMoves.push_back(std::make_pair<int, int>(row - 1, col + 2));

        if (board(row - 2, col - 1) == '.' || isBlackPiece(board, row - 2, col - 1))
            validMoves.push_back(std::make_pair<int, int>(row - 2, col - 1));

        if (board(row - 2, col + 1) == '.' || isBlackPiece(board, row - 2, col + 1))
            validMoves.push_back(std::make_pair<int, int>(row - 2, col + 1));

        if (board(row + 1, col - 2) == '.' || isBlackPiece(board, row + 1, col - 2))
            validMoves.push_back(std::make_pair<int, int>(row + 1, col - 2));

        if (board(row + 1, col + 2) == '.' || isBlackPiece(board, row + 1, col + 2))
            validMoves.push_back(std::make_pair<int, int>(row + 1, col + 2));

        if (board(row + 2, col - 1) == '.' || isBlackPiece(board, row + 2, col - 1))
            validMoves.push_back(std::make_pair<int, int>(row + 2, col - 1));

        if (board(row + 2, col + 1) == '.' || isBlackPiece(board, row + 2, col + 1))
            validMoves.push_back(std::make_pair<int, int>(row + 2, col + 1));

}
