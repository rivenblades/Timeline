
#include "GraphicsScene.h"
void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit sendSceneMouseEventSignal(event);
    QGraphicsScene::mousePressEvent(event);
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    emit sendSceneMouseEventSignal(event);
    QGraphicsScene::mouseReleaseEvent(event);
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    emit sendSceneMouseEventSignal(event);
    QGraphicsScene::mouseMoveEvent(event);
}
