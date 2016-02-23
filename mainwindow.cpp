#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setGeometry(QRect(0, 0, 900, 600));

    graphPart.setInputFileName("/home/michal/Documents/GroupProject/graphs/4elt.graph");
    graphPart.SvgPrepare();
    graphPart.setNumberOfPart(8);
    graphPart.Partition();
    graphPart.GraphColoring();

    graphPart.extractName();

    scene = new QGraphicsScene();
    item = new QGraphicsSvgItem(QString::fromStdString(graphPart.getPathColored()));
    scene->addItem(item);

    view = new QGraphicsView(this);
    view->setScene(scene);
    view->setGeometry(QRect(0, 0, 600, 600));

    // enables drag&drop
    item->setFlag(QGraphicsItem::ItemIsMovable);



    //view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



    //view->setFocusPolicy(Qt::NoFocus);
    //view->setMouseTracking(1);


}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
void MainWindow::wheelEvent(QWheelEvent *event)
{
    int delta = event->delta();

    view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    if (event->orientation() == Qt::Vertical) {
        if (delta < 0) {
            scale+=0.1;

        } else if (delta > 0) {
             scale-=0.1;
        }
         item->setScale(scale);
    }

    qDebug() << "scrolling";

    event->accept();
}
*/

void MainWindow::wheelEvent(QWheelEvent *event){

        view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        // Scale the view / do the zoom
        double scaleFactor = 1.15;
        if(event->delta() > 0) {

            // Zoom in
            view->scale(scaleFactor, scaleFactor);

        } else {
            // Zooming out
             view->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
        }


        //ui->graphicsView->setTransform(QTransform(h11, h12, h21, h22, 0, 0));
}
