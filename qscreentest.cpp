#include "qscreentest.h"

QScreenTest::QScreenTest(QWidget *parent) :
    QWidget(parent),
    mCurTaskIndex(0)
{

    drawWidget = new DrawWidget(this);
    drawWidget->setStyle(Qt::SolidLine);
    drawWidget->setWidth(2);
    drawWidget->setColor(Qt::black);

    clearBtn = addButton(QRect(CLEAR_BTN_X, CLEAR_BTN_Y, BUTTON_WIDTH, BYTTON_HEIGHT), tr("Clear"));
    connect(clearBtn, SIGNAL(clicked(bool)), this, SLOT(on_btn_clear_clicked()));
    quitBtn = addButton(QRect(QUIT_BTN_X, QUIT_BTN_Y, BUTTON_WIDTH, BYTTON_HEIGHT), tr("Quit"));
    connect(quitBtn, SIGNAL(clicked(bool)), this, SLOT(on_btn_quit_clicked()));

    drawWidget->hide();
    clearBtn->hide();
    quitBtn->hide();


}

void QScreenTest::mouseReleaseEvent(QMouseEvent *event)
{
    switch (mCurTaskIndex) {
    case 0:
    {
        QRect r(0, 0, TOUCH_AREA_WIDTH, TOUCH_AREA_HEIGHT);
        if (!r.contains(event->x(), event->y()))
            return;
    }
        break;

    case 1:
    {
        QRect r(width() - TOUCH_AREA_WIDTH, 0, TOUCH_AREA_WIDTH, TOUCH_AREA_HEIGHT);
        if (!r.contains(event->x(), event->y()))
            return;
    }
        break;

    case 2:
    {
        QRect r(width() - TOUCH_AREA_WIDTH, height() - TOUCH_AREA_HEIGHT, TOUCH_AREA_WIDTH, TOUCH_AREA_HEIGHT);
        if (!r.contains(event->x(), event->y()))
            return;
    }
        break;

    case 3:
    {
        QRect r(0, height() - TOUCH_AREA_HEIGHT, TOUCH_AREA_WIDTH, TOUCH_AREA_HEIGHT);
        if (!r.contains(event->x(), event->y()))
            return;
    }
        break;

    case 4:
    {
        QRect r((width() - TOUCH_AREA_WIDTH) / 2, (height() - TOUCH_AREA_HEIGHT) / 2, TOUCH_AREA_WIDTH, TOUCH_AREA_HEIGHT);
        if (!r.contains(event->x(), event->y()))
            return;
    }
        break;

    }
    mCurTaskIndex++;
    update();
    if (mCurTaskIndex >= 5)
    {
        drawWidget->show();
        clearBtn->show();
        quitBtn->show();

    }

}

void QScreenTest::paintEvent(QPaintEvent *event)
{
    QColor color;
    switch (mCurTaskIndex)
    {
    case 0:
        color = Qt::red;
        break;

    case 1:
        color = Qt::green;
        break;

    case 2:
        color = Qt::blue;
        break;

    case 3:
        color = Qt::white;
        break;

    case 4:
        color = Qt::black;
        break;

    default:
        return;
    }

    QPainter painter(this);
    QBrush brush(color);
    painter.setBrush(brush);
    painter.drawRect(0, 0, width(), height());
}

QPushButton *QScreenTest::addButton(const QRect &rect, const QString &text, const char *objName, QWidget *parent)
{
    if (parent == NULL)
    {
        parent = this;
    }
    QPushButton *btn = new QPushButton(parent);
    btn->setGeometry(rect);
    //    QPixmap pixmap(image);
    //    btn->setIcon(QIcon(pixmap));
    //    btn->setIconSize(pixmap.size());
    btn->setText(text);

    if(objName != NULL)
    {
        btn->setObjectName((QString(objName)));
    }

    return btn;
}

void QScreenTest::on_btn_clear_clicked()
{
    drawWidget->clear();
}

void QScreenTest::on_btn_quit_clicked()
{
    exit(0);
}



