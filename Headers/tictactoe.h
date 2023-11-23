#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
public:
    TicTacToe();
    int setPlayer();
    int getPlayer();
    void setArrayVal(int row, int col);
    bool checkWinner();
    bool checkDraw();
    void setRealPlayer();
    void setBot();
    bool getPlayerType();
    void makeBotMove();
    int getBotMove() const;
    void printArray() const;
private:
    int player;
    int arrayGame[3][3];
    bool isPlayer;
    int minimax(bool isMaximizer);
    int lastBotMove;
};

#endif // TICTACTOE_H
