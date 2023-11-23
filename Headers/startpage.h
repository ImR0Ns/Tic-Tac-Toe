#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QDialog>
#include "tictactoe.h"

namespace Ui {
class StartPage;
}

class StartPage : public QDialog
{
    Q_OBJECT

public:
    explicit StartPage(QWidget *parent = nullptr);
    ~StartPage();

private slots:

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::StartPage *ui;
    //init game
    TicTacToe game; //init game at application run
};

#endif // STARTPAGE_H
