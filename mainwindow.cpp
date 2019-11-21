#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene= new QGraphicsScene();
    view = new GraphicsView(scene);
    scene->setSceneRect(360,0, 360, 180);
//    view->scale(1,-1);
    timeline = new TimeLine(view);

view->setInteractive(true);
    view->setMouseTracking(true);
view->setFocus();
    int outlineSize = 3;

    QColor red(255,0,0);
    QColor reddimmed(red.red()-80,red.green(),red.blue());

    QColor purple(255, 51, 153);
    QColor purpledimmed(153, 0, 77);

    QColor green(102, 255, 102);
    QColor greendimmed(51, 204, 51);

    QColor blue(51, 102, 255);
    QColor bluedimmed(0, 51, 204);

    QColor orange(255, 153, 51);
    QColor orangedimmed(255, 102, 0);

    QPen penPurple(purple,outlineSize);
    penPurple.setCapStyle(Qt::RoundCap);

    QPen penGreen(green,outlineSize);
    penGreen.setCapStyle(Qt::RoundCap);

    QPen penBlue(blue,outlineSize);
    penBlue.setCapStyle(Qt::RoundCap);

    QPen penOrange(orange,outlineSize);
    penOrange.setCapStyle(Qt::RoundCap);

    QBrush brushPurple(purpledimmed);
    QBrush brushGreen(greendimmed);
    QBrush brushBlue(bluedimmed);
    QBrush brushOrange(orangedimmed);

    QBrush brush(reddimmed);
    QPen pen(red,outlineSize);

    pen.setCapStyle(Qt::RoundCap);
    timeline->AddItem(QPointF(0,0), QRect(0,0,240,30), pen, brush);


    timeline->AddItem(QPointF(0,0), QRect(0,0,240,30), penPurple, brushPurple);
    timeline->AddItem(QPointF(60,35), QRect(0,0,40,30), penGreen, brushGreen);
    timeline->AddItem(QPointF(60+50,35*2), QRect(0,0,100,30), penBlue, brushBlue);
    timeline->AddItem(QPointF(60+100,35*3), QRect(0,0,340,30), penOrange, brushOrange);
    setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}
