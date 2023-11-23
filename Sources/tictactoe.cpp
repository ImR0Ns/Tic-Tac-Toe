#include "tictactoe.h"
#include <iostream>
#include <limits>

TicTacToe::TicTacToe()
    : player(0),
    arrayGame{{-1, -1, -1},
              {-1, -1, -1},
              {-1, -1, -1}},
    isPlayer(true)// constructor initializer list
{

}

int TicTacToe::setPlayer() {
    return player == 0 ? player = 1 : player = 0;
}

int TicTacToe::getPlayer() {
    return player;
}

void TicTacToe::setArrayVal(int row, int col) {
    arrayGame[row][col] = player;
}

bool TicTacToe::checkWinner() {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (arrayGame[i][0] == arrayGame[i][1] && arrayGame[i][1] == arrayGame[i][2] && arrayGame[i][0] != -1) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; ++j) {
        if (arrayGame[0][j] == arrayGame[1][j] && arrayGame[1][j] == arrayGame[2][j] && arrayGame[0][j] != -1) {
            return true;
        }
    }

    // Check diagonals
    if ((arrayGame[0][0] == arrayGame[1][1] && arrayGame[1][1] == arrayGame[2][2] && arrayGame[0][0] != -1) ||
        (arrayGame[0][2] == arrayGame[1][1] && arrayGame[1][1] == arrayGame[2][0] && arrayGame[0][2] != -1)) {
        return true;
    }

    return false; // No winner yet
}

bool TicTacToe::checkDraw() {
    // Check if all positions are filled
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (arrayGame[i][j] == -1) {
                // If any position is empty, the game is not a draw
                return false;
            }
        }
    }

    // All positions are filled, it's a draw
    return true;
}

void TicTacToe::setRealPlayer() {
    isPlayer = true;
}

void TicTacToe::setBot() {
    isPlayer = false;
}

bool TicTacToe::getPlayerType() {
    return isPlayer;
}

int TicTacToe::getBotMove() const {
    return lastBotMove;
}

void TicTacToe::makeBotMove() {
    // Check if it's the bot's turn
    if (!isPlayer) {
        // Initialize bestMove with invalid values
        int bestMoveRow = -1;
        int bestMoveCol = -1;
        int bestScore = -std::numeric_limits<int>::max(); // Negative infinity

        // Loop through all empty cells and find the best move using Minimax
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (arrayGame[i][j] == -1) {
                    // Try this move
                    arrayGame[i][j] = player;

                    // Calculate the score for this move using Minimax
                    int score = minimax(false);

                    // Undo the move
                    arrayGame[i][j] = -1;

                    // Update bestMove if this move is better
                    if (score > bestScore) {
                        bestScore = score;
                        bestMoveRow = i;
                        bestMoveCol = j;
                    }
                }
            }
        }

        // Store the best move
        lastBotMove = bestMoveRow * 3 + bestMoveCol;

        // Make the best move
        if (bestMoveRow != -1 && bestMoveCol != -1) {
            arrayGame[bestMoveRow][bestMoveCol] = player;
        }
    }
}

int TicTacToe::minimax(bool isMaximizer) {
    // Check if the game is over
    if (checkWinner()) {
        return isMaximizer ? -1 : 1;
    }

    if (checkDraw()) {
        return 0;
    }

    // Initialize the bestScore based on the role (maximizer or minimizer)
    int bestScore = isMaximizer ? -std::numeric_limits<int>::max() : std::numeric_limits<int>::max();

    // Loop through all empty cells
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (arrayGame[i][j] == -1) {
                // Try this move
                arrayGame[i][j] = isMaximizer ? player : (1 - player);

                // Recursively calculate the score
                int score = minimax(!isMaximizer);

                // Undo the move
                arrayGame[i][j] = -1;

                // Update the bestScore based on the role
                if (isMaximizer) {
                    bestScore = std::max(bestScore, score);
                } else {
                    bestScore = std::min(bestScore, score);
                }
            }
        }
    }

    return bestScore;
}

void TicTacToe::printArray() const
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << arrayGame[i][j];
            if (j < 2) {
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
        if (i < 2) {
            std::cout << "---------" << std::endl;
        }
    }
    std::cout << std::endl;
}
