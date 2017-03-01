#ifndef QSCREENTEST_H
#define QSCREENTEST_H

#include <QWidget>
#include <QPushButton>

#include "drawwidget.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 480

#define CLEAR_BTN_X 200
#define CLEAR_BTN_Y 413
#define QUIT_BTN_X 500
#define QUIT_BTN_Y 413

#define TOUCH_AREA_WIDTH  80
#define TOUCH_AREA_HEIGHT  80

# define BUTTON_WIDTH 80
# define BYTTON_HEIGHT 60

class QScreenTest : public QWidget
{
    Q_OBJECT
public:
    explicit QScreenTest(QWidget *parent = 0);

protected:
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    int mCurTaskIndex;

    DrawWidget *drawWidget;

    QPushButton *clearBtn;
    QPushButton *quitBtn;

    QPushButton* addButton(const QRect &rect, const QString &text, const char *objName = NULL, QWidget *parent = NULL);
signals:

public slots:
    void on_btn_clear_clicked();
    void on_btn_quit_clicked();


};

#endif // QSCREENTEST_H
