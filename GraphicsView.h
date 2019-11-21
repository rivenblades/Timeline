#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <iostream>
#include <QDebug>

class GraphicsView:public QGraphicsView{
Q_OBJECT
public:
    GraphicsView(QGraphicsScene *scene):QGraphicsView(scene){}
    
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;

signals:
    void sendMousePressEventSignal(QMouseEvent *event);
    void sendMouseMoveEventSignal(QMouseEvent *event);
    void sendMouseReleaseEventSignal(QMouseEvent *event);

    // QWidget interface
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;

    // QGraphicsView interface
protected:
    virtual void drawBackground(QPainter *painter, const QRectF &rect) override;
};
#endif //GraphicsView.h
