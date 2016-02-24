#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsSvgItem>
#include <QGraphicsView>
#include <QDebug>
#include "graphvizpopup.h"
#include "graphpart.h"
#include <QFileDialog>
#include <QMessageBox>
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

    GraphVizPopUp *view=NULL;
    QGraphicsSvgItem *item=NULL;
    QGraphicsScene *scene=NULL;

    GraphPart graphPart;
    void closeEvent (QCloseEvent *e);


private slots:
    void on_ButtonVisualize_released();
    void on_ButtonBrowse_released();
    void on_ButtonLoad_released();
    void on_ButtonsOkCancel_accepted();
    void on_ButtonsOkCancel_rejected();
    void on_BoxNumberOfPartitions_valueChanged(int arg1);
    void on_advancedButton_released();
};

#endif // MAINWINDOW_H
