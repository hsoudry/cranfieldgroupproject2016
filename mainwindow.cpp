#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->RadioGraph->setChecked(true);
    ui->ButtonLoad->setEnabled(false);
    ui->ButtonVisualize->setEnabled(false);
    ui->advancedoptions->setVisible(false);

    /*

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
    if(graphPart.GraphIsLoaded()){
        if(graphPart.isDrawable()){
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
        else
        {
            QMessageBox msgbox;
            msgbox.setText("Graph is too big to visualize!");
            msgbox.exec();
        }
    }
    else
    {
        QMessageBox msgbox;
        msgbox.setText("Graph is not loaded!");
        msgbox.exec();
    }
}

void MainWindow::on_ButtonBrowse_released()
{
    QString file1Name = QFileDialog::getOpenFileName(this,
                                                     tr("Open graph file"), "/home", tr("Graph (*.graph *.mesh)"));
    ui->BoxInputPath->setText(file1Name);
    if (!file1Name.isEmpty()) ui->ButtonLoad->setEnabled(true);


}

void MainWindow::on_ButtonLoad_released()
{

    graphPart.setInputFileName(ui->BoxInputPath->text().toStdString());
    if(!ui->RadioGraph->isChecked()) graphPart.mesh2graph();
    if(graphPart.isDrawable()){
        graphPart.SvgPrepare();
        ui->ButtonVisualize->setEnabled(true);
    }
    else{
        QMessageBox msgbox;
        msgbox.setText("Graph is too big to visualize! You can only prepare partitions file");
        msgbox.exec();
    }

}

void MainWindow::on_ButtonsOkCancel_accepted()
{
    if(graphPart.GraphIsLoaded()){

        graphPart.Partition();
        graphPart.GraphColoring();
        if(graphPart.isDrawable()){
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
        else
        {
            QMessageBox msgbox;
            msgbox.setText("Graph is too big to visualize! (only partitions file was prepared)");
            msgbox.exec();
        }
    }
    else
    {
        QMessageBox msgbox;
        msgbox.setText("Graph is not loaded!");
        msgbox.exec();
    }
}

void MainWindow::on_ButtonsOkCancel_rejected()
{
    this->close();
}

void MainWindow::on_BoxNumberOfPartitions_valueChanged(int arg1)
{
    graphPart.setNumberOfPart(arg1);
}


void MainWindow::on_advancedButton_released()
{
    ui->advancedoptions->setVisible(true);

}
