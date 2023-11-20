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
    delete ui;
}

void StartPage::on_pushButton_clicked()
{
    close(); // close app
}

void StartPage::on_pushButton_3_clicked()
{
    // Create an instance of MainWindow
    MainWindow *mainWindow = new MainWindow();

    // Show the MainWindow
    mainWindow->show();

    // Close the StartPage (optional)
    close();

    connect(mainWindow, &MainWindow::destroyed, mainWindow, &QObject::deleteLater);
}

