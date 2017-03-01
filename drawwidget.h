#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>
#include <QtGui>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QColor>
#include <QPixmap>
#include <QPoint>
#include <QPainter>
#include <QPalette>
#include <QDateTime>
#include <QDebug>

class DrawWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawWidget(QWidget *parent = 0);
    ~DrawWidget();

    // override  mouse envent
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);

    // override paint envent
    void paintEvent(QPaintEvent *e);

    void resizeEvent(QResizeEvent *e);

    void drawPoint(const QPoint &p);
    void drawLine(const QPoint &start, const QPoint &end);

signals:

public slots:
    void clear();
    void setStyle(int style);
    void setWidth(int widths);
    void setColor(QColor color);

private:
    QPixmap *pixmap;
    QPoint startPos;
    QPoint endPos;
    int style;
    int widths;
    QColor color;
    QPainter *painter;
    QPen pen;

};

#endif // DRAWWIDGET_H
