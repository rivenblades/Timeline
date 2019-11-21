#include "GraphicsView.h"
#include <QDebug>

void GraphicsView::mousePressEvent(QMouseEvent *event)
{
    if(!itemAt(event->pos())){
        std::cout << "Press"<<std::endl;
    }else{
        auto item = this->scene()->itemAt(event->pos(),QTransform());
//         item = static_cast<NodePin*>(item);
//         if(item){
//             emit sendMousePressEventSignal(event);
//             qDebug()<<"dwsto re malaka ";
//         }
    }
//     node_editor->mousePressEvent(event);
    QGraphicsView::mousePressEvent(event);
}

void GraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    /// WORKS!!!!!!!!!!
    auto item = this->scene()->itemAt(event->pos(),QTransform());
//     item = static_cast<NodePin*>(item);
//     if(item){
//     //            qDebug()<<item;
//         emit sendMousePressEventSignal(event);
//     }
//     node_editor->mouseMoveEvent(event);

    QGraphicsView::mouseMoveEvent(event);
}

void GraphicsView::mouseReleaseEvent(QMouseEvent *event){
    QGraphicsView::mouseReleaseEvent(event);
}

void GraphicsView::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"CLCLLCLC";
    QGraphicsView::keyPressEvent(event);
}

void GraphicsView::drawBackground(QPainter *painter, const QRectF &rect){
//    QBrush brush(QColor(240,200,150));
    QBrush brush(Qt::darkGray);
    painter->fillRect(rect,brush);
}
