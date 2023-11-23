#include "startpage.h"
#include "ui_startpage.h"
#include "mainwindow.h"
#include <iostream>

StartPage::StartPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartPage)
{
    ui->setupUi(this);
    // Set the window title
    setWindowTitle("Tic-Tac-Toe");

    // Set the minimum size for the window
    setMinimumSize(750, 550);

}

StartPage::~StartPage()
{
    //std::cout<<"test";
    delete ui;
}

void StartPage::on_pushButton_3_clicked()
{
    close(); // close app and calling destructor.
}


void StartPage::on_pushButton_clicked()
{
    game.setRealPlayer();
    // Create an instance of MainWindow
    MainWindow *mainWindow = new MainWindow(game); //give the game that we init in startpage.h to work

    // Show the MainWindow
    mainWindow->show();

    // Close the StartPage
    close();
}


void StartPage::on_pushButton_2_clicked()
{
    game.setBot();
    // Create an instance of MainWindow
    MainWindow *mainWindow = new MainWindow(game); //give the game that we init in startpage.h to work

    // Show the MainWindow
    mainWindow->show();

    // Close the StartPage
    close();
}

