#include "drawwidget.h"

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    setMinimumSize(800,480);
    pixmap = new QPixmap(size());
    pixmap->fill(Qt::white);
    painter = new QPainter();
}

DrawWidget::~DrawWidget()
{
    delete pixmap;
}

void DrawWidget::setStyle(int style)
{
    this->style = style;
    pen.setStyle((Qt::PenStyle)style);
}

void DrawWidget::setWidth(int widths)
{
    this->widths = widths;
    pen.setWidth(widths);
}

void DrawWidget::setColor(QColor color)
{
    this->color = color;
    pen.setColor(color);
}


void DrawWidget::mousePressEvent(QMouseEvent *e)
{
    startPos = e->pos();

    drawPoint(startPos);
    int x = (startPos.x() - widths) > 0 ? (startPos.x() - widths) : 0;
    int y = (startPos.y() - widths) > 0 ? (startPos.y() - widths ): 0;
    int h = qAbs(endPos.y() - startPos.y()) + 2*widths;
    int w = qAbs(endPos.x() - startPos.x()) + 2*widths;
    update(QRegion(x, y, w, h));
}

void DrawWidget::mouseMoveEvent(QMouseEvent *e)
{

    endPos = e->pos();
    drawLine(startPos,endPos);
//    qDebug() <<endPos.y() << endPos.x();
    int x1 = qMin(startPos.x(),endPos.x()) - widths;
    int y1= qMin(startPos.y(),endPos.y()) - widths ;
    int x = x1 > 0 ? x1 : 0;
    int y = y1 > 0? y1 : 0;
    int h = qAbs(endPos.y() - startPos.y()) + 2*widths;
    int w = qAbs(endPos.x() - startPos.x()) + 2*widths;
//    qDebug() << "Height :" <<h << "Width :" << w;;
     update(QRegion(x, y, w, h));
//    update();
    startPos = endPos;
}

void DrawWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawPixmap(QPoint(0, 0), *pixmap);

}

void DrawWidget::resizeEvent(QResizeEvent *e)
{
    if(height() > pixmap->height() || width() > pixmap->width())
    {
        QPixmap *newPix = new QPixmap(size());
        newPix->fill(Qt::white);
        QPainter p(newPix);
        p.drawPixmap(QPoint(0, 0), *pixmap);
        pixmap = newPix;
    }
    QWidget::resizeEvent(e);
}

void DrawWidget::drawPoint(const QPoint &p)
{
    painter->begin(pixmap);
    painter->setPen(pen);
    painter->drawPoint(p);
    painter->end();

}

void DrawWidget::drawLine(const QPoint &start, const QPoint &end)
{

    painter->begin(pixmap);
    painter->setPen(pen);
    painter->drawLine(start,end);
    painter->end();
}

void DrawWidget::clear()
{
    QPixmap *clearPix = new QPixmap(size());
    clearPix->fill(Qt::white);
    pixmap = clearPix;
    update();

}
