#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsSvgItem>
#include <QGraphicsView>
#include <QWheelEvent>
#include <QDebug>

#include "graphpart.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QGraphicsView *view;
    QGraphicsSvgItem *item;
    QGraphicsScene *scene;

    GraphPart graphPart;

    void wheelEvent(QWheelEvent *event);
    float scale=1.0;

public slots:
};

#endif // MAINWINDOW_H
