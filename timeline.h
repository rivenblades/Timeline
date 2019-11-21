#ifndef TIMELINE_H
#define TIMELINE_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTransform>
#include <QDebug>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QPen>
#include <QBrush>
#include <QGraphicsItem>
#include <QPoint>
#include "Indicator.h"
#include "Track.h"
class TimeLine : public QWidget
{
    Q_OBJECT

public:
    explicit TimeLine(QWidget *parent = nullptr);
    TimeLine(QGraphicsView *_view, QWidget *_parent = nullptr);
    ~TimeLine();
    QGraphicsItem* ItemAt(QPointF position){return scene->itemAt(position,QTransform());}
    void AddItem(QPointF pos, QRect rect, QPen pen, QBrush brush);
    void SetFrame(int _frame){if(_frame < maxFrame)frame=_frame;}
    QGraphicsScene *scene;
    QGraphicsView *view;
//    QPoint indicatorPos;
    QGraphicsItem *indicatorItem;
    QGraphicsItem *indicatorHead;
    Indicator *indicator;

    int frame;
    int minFrame,maxFrame;
};

#endif // TIMELINE_H
