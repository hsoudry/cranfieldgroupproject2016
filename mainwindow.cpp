#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

/*
    graphPart.setInputFileName("../../graphs/4elt.graph");
    graphPart.SvgPrepare();
    graphPart.setNumberOfPart(8);
    graphPart.Partition();
    graphPart.GraphColoring();

    graphPart.extractName();
*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    if(item) delete item;
    if (scene) delete scene;
    if (view) delete view;
}

void MainWindow::on_ButtonVisualize_released()
{
    if(item) delete item;
    if (scene) delete scene;
    if (view) delete view;
    scene = new QGraphicsScene();
    item = new QGraphicsSvgItem(QString::fromStdString(graphPart.getPathUncolored()));
    scene->addItem(item);

    view = new GraphVizPopUp();
    view->setScene(scene);
    view->setGeometry(QRect(this->width()+100,this->y(), 600, 600));
    view->show();

    // enables drag&drop
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void MainWindow::on_ButtonBrowse_released()
{

}

void MainWindow::on_ButtonLoad_released()
{

}

void MainWindow::on_ButtonsOkCancel_accepted()
{
    if(item) delete item;
    if (scene) delete scene;
    if (view) delete view;
    scene = new QGraphicsScene();
    item = new QGraphicsSvgItem(QString::fromStdString(graphPart.getPathColored()));
    scene->addItem(item);

    view = new GraphVizPopUp();
    view->setScene(scene);
    view->setGeometry(QRect(this->width()+100,this->y(), 600, 600));
    view->show();
    // enables drag&drop
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void MainWindow::on_ButtonsOkCancel_rejected()
{
    this->close();
}

void MainWindow::on_BoxNumberOfPartitions_valueChanged(int arg1)
{
    graphPart.setNumberOfPart(arg1);
}
