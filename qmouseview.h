#ifndef QMOUSEVIEW_H
#define QMOUSEVIEW_H

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QApplication>
#include <QRubberBand>
#include <QPointF>
#include <QDebug>

class QMouseView : public QGraphicsView
{ Q_OBJECT

public:
    QMouseView(QWidget* parent = 0);
    ~QMouseView();

    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void wheelEvent(QWheelEvent *e);
    QPointF MapToImage(QPointF p);
    QPointF ImageToMap(QPointF p);

    QRubberBand *rubberBand;
    int pixelSize;
    double upperLeftX;
    double upperLeftY;
    double lowerRightX;
    double lowerRightY;

    //void paintEvent(QPaintEvent *e);

signals:
    void emitNowPos(QPointF p);
    void emitWheel(double d);

};

#endif // QMOUSEVIEW_H
