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
private:
    int player;
    int arrayGame[3][3];
};

#endif // TICTACTOE_H
