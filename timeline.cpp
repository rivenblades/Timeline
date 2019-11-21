#include "timeline.h"

TimeLine::TimeLine(QWidget *parent) :
    QWidget(parent)
{
}
QColor Track::selectedColor = QColor(200,30,180);
QColor Track::selectedColorOutline = Track::selectedColor.lighter(30);
int Track::penWidth = 2;
bool Track::hasShadow = false;
float Track::thresholdShadow=0.0f;
int Track::rounded = 10;

TimeLine::TimeLine(QGraphicsView *_view, QWidget *_parent)
{
    if (_view) view = _view;
    else view = new QGraphicsView(this);
    scene = view->scene();
setMouseTracking(true);
    int xOffset =100;
    for(int i =0; i < 10; i++){
        QGraphicsItem *item = scene->addText(QString::number(i));
        item->setPos(i*xOffset,-40);
    }



    indicator = new Indicator(height());
    scene->addItem(indicator);
    indicator->setZValue(101);


    Track *track = new Track(200,QColor(Qt::cyan),scene);
    scene->addItem(track);
    track->setPos(QPointF(300,0));
}

TimeLine::~TimeLine()
{
}

void TimeLine::AddItem(QPointF pos, QRect rect, QPen pen, QBrush brush)
{

    QGraphicsItem *item = scene->addRect(rect,pen,brush);
    item->setPos(pos);
}
