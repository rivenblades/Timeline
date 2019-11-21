#include "Indicator.h"

Indicator::Indicator(float height):QGraphicsItem ()
{
    pen = QPen(Qt::black,2);
    brush = QBrush(Qt::RoundCap);
    brush.setColor(QColor("#50f"));
    points<<QPointF(-10,0)
         <<QPointF(10,20)
        <<QPointF(10,-10)
       <<QPointF(-10,-10);
    setHeight(height);
   setAcceptHoverEvents(true);
   this->setAcceptDrops(true);

   setFlag(QGraphicsItem::ItemIsMovable);
         setFlag(QGraphicsItem::ItemIsFocusable);
setFlag(ItemSendsGeometryChanges);
         //    setFlags(ItemIsMovable);

    //line.setLine(0,0,0,);
}

QSizeF Indicator::calculateSize()const
{
    float minX = points[0].x();
    float minY = points[0].y();
    float maxX = points[0].x();
    float maxY = points[0].y();
    for(QPointF point : points){
        if (point.x() < minX){
            minX = point.x();
        }
        if (point.y() < minY){
            minY = point.y();
        }
        if (point.x() > maxX){
            maxX = point.x();
        }
        if (point.y() > maxY){
            maxY = point.y();
        }
    }
    return QSizeF(maxX-minX,line.p2().y());
}

QRectF Indicator::boundingRect() const
{
    QSizeF size = this->calculateSize();
    return QRectF(-10,-10,size.width(),size.height());
}

void Indicator::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setPen(pen);
    painter->drawLine(line);
    painter->setBrush(brush);
    //painter->translate(-boundingRect().width()/2,0);
    painter->drawPolygon(points);
    //painter->translate(boundingRect().width()/2,0);
//    QBrush b(Qt::red);
//    painter->setBrush(b);
//    painter->drawRect(boundingRect());
}

void Indicator::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress){
        pressed = true;
        qDebug()<<"press";
    }else if(event->type() == QEvent::MouseButtonRelease){
        pressed = false;
        qDebug()<<"release";
    }


    QGraphicsItem::mousePressEvent(event);
    update();
}

void Indicator::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF pos = event->scenePos();
    qDebug()<<"move";
    if(pressed){


        this->setPos(pos.x(),y());
    }
    QGraphicsItem::mouseMoveEvent(event);
update();
}

void Indicator::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    pressed = false;
    qDebug()<<event->scenePos();
    QGraphicsItem::mouseReleaseEvent(event);
update();
}

void Indicator::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
//qDebug()<<"hover enter";


}

void Indicator::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
//qDebug()<<"hover move";

//    if(pressed){

//        QPointF pos = event->scenePos();
//        qDebug()<<pos;
//        this->setPos(pos.x(),y());
//    }
}

void Indicator::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
//qDebug()<<"hover leave";
    //    pressed=false;
}

QVariant Indicator::itemChange(GraphicsItemChange change, const QVariant &value)
{

    if (change == ItemPositionChange && scene()) {
        // value is the new position.
        QPointF newPos = value.toPointF();
        newPos.setY(y());
        if(newPos.x() < 0){
            newPos.setX(0);
        }
//        newPos = qBound(QPointF(0,0),newPos,QPointF(10000,0));
        return newPos;
    }
    return QGraphicsItem::itemChange(change, value);
}
