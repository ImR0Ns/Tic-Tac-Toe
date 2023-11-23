#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QMessageBox>
#include <QTimer>
#include "tictactoe.h"
#include "startpage.h"
#include <iostream>
#include <sstream>
#include <map>

// Initialize the static pointer
MainWindow* MainWindow::mainWindowInstance = nullptr;

MainWindow::MainWindow(TicTacToe& game, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), game(game) //construct the game
{
    ui->setupUi(this);

    // Set the window title
    setWindowTitle("Tic-Tac-Toe");

    // Set the minimum size for the window
    setMinimumSize(750, 550);

    connect(this, &MainWindow::switchToStartPage, this, &MainWindow::switchToStartPageSlot);

    // Set the static pointer to the current MainWindow instance
    mainWindowInstance = this;

    // Add buttons to the map when the MainWindow is created
    addButtonToMap(0, ui->pushButton);
    addButtonToMap(1, ui->pushButton_2);
    addButtonToMap(2, ui->pushButton_3);
    addButtonToMap(3, ui->pushButton_4);
    addButtonToMap(4, ui->pushButton_5);
    addButtonToMap(5, ui->pushButton_6);
    addButtonToMap(6, ui->pushButton_7);
    addButtonToMap(7, ui->pushButton_8);
    addButtonToMap(8, ui->pushButton_9);


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
void MainWindow::addTextDeleteButton(QGridLayout *gridLayout, QPushButton *button, TicTacToe& game, int positionForArray)
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

        if(!game.getPlayerType()){
            //make the move
            game.makeBotMove();
            //get the move
            int botMove = game.getBotMove();
            //change back the player (X)
            game.setPlayer();

            game.printArray();

            QPushButton* buttonTwo  = getButtonFromMap(botMove);
            index = gridLayout->indexOf(buttonTwo);

            if (buttonTwo) {

                gridLayout->getItemPosition(index, &row, &column, &rowSpan, &columnSpan);

                // Create a label for the bot move
                QLabel* label = new QLabel("O", buttonTwo->parentWidget());
                QFont font = label->font();

                font.setPointSize(90);
                label->setFont(font);
                label->setAlignment(Qt::AlignCenter);

                // Remove the button from the layout and delete it
                ui->gridLayout->removeWidget(buttonTwo);

                // Add the label to the layout
                ui->gridLayout->addWidget(label, row, column, rowSpan, columnSpan);
                delete buttonTwo;
            }

        }




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

void MainWindow::addButtonToMap(int index, QPushButton *button)
{
    buttonMap[index] = button;
}

QPushButton* MainWindow::getButtonFromMap(int botMove)
{
    // Get the button from the map based on botMove
    return buttonMap.value(botMove, nullptr);
}

