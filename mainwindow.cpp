#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QMessageBox>
#include <QTimer>
#include "tictactoe.h"
#include "startpage.h"
#include <iostream>

// declaring functions
void addTextDeleteButton(QGridLayout *gridLayout, QPushButton *button, TicTacToe& game, int positionForArray);

// Initialize the static pointer
MainWindow* MainWindow::mainWindowInstance = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set the window title
    setWindowTitle("Tic-Tac-Toe");

    // Set the minimum size for the window
    setMinimumSize(750, 550);

    connect(this, &MainWindow::switchToStartPage, this, &MainWindow::switchToStartPageSlot);

    // Set the static pointer to the current MainWindow instance
    mainWindowInstance = this;

}

MainWindow::~MainWindow()
{
    delete ui;
}

//buttons
void MainWindow::on_pushButton_clicked()
{
    addTextDeleteButton(ui->gridLayout, ui->pushButton, game, 0);
}

void MainWindow::on_pushButton_2_clicked()
{
    addTextDeleteButton(ui->gridLayout, ui->pushButton_2, game, 1);
}

void MainWindow::on_pushButton_3_clicked()
{
    addTextDeleteButton(ui->gridLayout, ui->pushButton_3, game, 2);
}

void MainWindow::on_pushButton_4_clicked()
{
    addTextDeleteButton(ui->gridLayout, ui->pushButton_4, game, 3);
}

void MainWindow::on_pushButton_5_clicked()
{
   addTextDeleteButton(ui->gridLayout, ui->pushButton_5, game, 4);
}

void MainWindow::on_pushButton_6_clicked()
{
    addTextDeleteButton(ui->gridLayout, ui->pushButton_6, game, 5);
}

void MainWindow::on_pushButton_7_clicked()
{
    addTextDeleteButton(ui->gridLayout, ui->pushButton_7, game, 6);
}

void MainWindow::on_pushButton_8_clicked()
{
    addTextDeleteButton(ui->gridLayout, ui->pushButton_8, game, 7);
}

void MainWindow::on_pushButton_9_clicked()
{
    addTextDeleteButton(ui->gridLayout, ui->pushButton_9, game, 8);
}




//defining functions
void addTextDeleteButton(QGridLayout *gridLayout, QPushButton *button, TicTacToe& game, int positionForArray)
{
    int index = gridLayout->indexOf(button);

    if (index != -1) {
        int row, column, rowSpan, columnSpan, firstIndexArr;
        QLabel *label;
        gridLayout->getItemPosition(index, &row, &column, &rowSpan, &columnSpan);

        firstIndexArr = (positionForArray >= 0 && positionForArray <= 2) ? 0 :
                                (positionForArray >= 3 && positionForArray <= 5) ? 1 :
                                (positionForArray >= 6 && positionForArray <= 8) ? 2 :
                                -1;

        //what to choose between
        if(game.getPlayer() == 0) {
            label = new QLabel("X", button->parentWidget());
        } else {
            label = new QLabel("O", button->parentWidget());
        }

        // Set the maximum font size
        QFont font = label->font();
        font.setPointSize(90);
        label->setFont(font);

        //std::cout<< firstIndexArr << " " << positionForArray % 3 <<std::endl;
        game.setArrayVal(firstIndexArr, positionForArray % 3);

        game.setPlayer(); // change between the players

        label->setAlignment(Qt::AlignCenter);

        gridLayout->removeWidget(button);
        gridLayout->addWidget(label, row, column, rowSpan, columnSpan);

        // delete button after
        delete button;

        //check winner
        if(game.checkWinner()){
            char playerWhoWon = game.getPlayer() == 1 ? 'X' : 'O';
            QMessageBox::information(nullptr, "Winner", "Player " + QString(playerWhoWon) + " won");

            delete label;

            // Emit the signal using the MainWindow instance
            emit MainWindow::mainWindowInstance->switchToStartPage();
        } else {
            if (game.checkDraw()) {
                QMessageBox::information(nullptr, "Draw", "The game is a draw!");

                // Emit the signal using the MainWindow instance
                emit MainWindow::mainWindowInstance->switchToStartPage();
            }
        }

        //remember: delete heap memory of label to avoid memory leak.

    }
}

void MainWindow::switchToStartPageSlot()
{
    // Close the current MainWindow instance
    this->close();

    // Show the StartPage window
    StartPage* startPage = new StartPage();
    startPage->show();
}
