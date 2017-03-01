#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "qscreentest.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

private:
     QScreenTest *screenWidget;

    //Ui::MainWindow *ui;
//    DrawWidget *drawWidget;

//    QPushButton *clearBtn;
};

#endif // MAINWINDOW_H
