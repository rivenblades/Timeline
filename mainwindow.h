#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "timeline.h"
#include "GraphicsScene.h"
#include "GraphicsView.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QGraphicsScene *scene;
    GraphicsView *view;
    TimeLine *timeline;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
