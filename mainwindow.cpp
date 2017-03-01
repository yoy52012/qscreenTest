#include "mainwindow.h"
//#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
//    drawWidget = new DrawWidget();
//    setCentralWidget(drawWidget);
//    setMinimumSize(800,600);

//    drawWidget->setStyle(Qt::SolidLine);
//    drawWidget->setWidth(5);
//    drawWidget->setColor(Qt::black);

//    clearBtn = new QPushButton(this);
//    clearBtn->setText(tr("CLEAR"));
//    clearBtn->setGeometry(400, 200, 80 ,60);
//    connect(clearBtn, SIGNAL(clicked(bool)),this, SLOT(on_btn_clear_clicked()));
    screenWidget  = new QScreenTest();
    screenWidget->setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    this->setCentralWidget(screenWidget);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);


}

MainWindow::~MainWindow()
{

}

