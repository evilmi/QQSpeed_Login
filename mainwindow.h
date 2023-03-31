
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>

#include "MoveWgt.h"
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

    //设置窗口随意移动
    Move_Wgt

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void sleep(unsigned int msec);

    void Login();

private:
    Ui::MainWindow *ui;
    QWebEngineView *my_web;
};

#endif // MAINWINDOW_H
