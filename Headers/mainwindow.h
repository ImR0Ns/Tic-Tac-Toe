#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QGridLayout>
#include "qpushbutton.h"
#include "tictactoe.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(TicTacToe& game, QWidget *parent = nullptr); // add to const the game
    ~MainWindow();
    static MainWindow* mainWindowInstance;
    void addTextDeleteButton(QGridLayout *gridLayout, QPushButton *button, TicTacToe& game, int positionForArray);
    void addButtonToMap(int index, QPushButton *button);
    QPushButton* getButtonFromMap(int botMove);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
    TicTacToe& game; // the mainwindow get the adress of game by ref
    void switchToStartPageSlot();
    QMap<int, QPushButton*> buttonMap;

signals:
    void switchToStartPage();
};

#endif // MAINWINDOW_H
