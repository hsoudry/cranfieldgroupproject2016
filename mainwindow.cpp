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
    this->setFixedSize(592,300); //minimum size

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
        ui->statusBar->showMessage("Graph is being loaded...");
        graphPart.SvgPrepare();
        ui->ButtonVisualize->setEnabled(true);
        ui->statusBar->showMessage("");
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
        if(ui->advancedButton->isChecked()){
            string MetisOptions="";
            if (ui->kway->isChecked()) MetisOptions+="-ptype=kway ";
            if (ui->recursive_bisection->isChecked()) MetisOptions+="-ptype=rb ";
            if (ui->sorted->isChecked()) MetisOptions+="-ctype=shem ";
            if (ui->random_matching->isChecked()) MetisOptions+="-ctype=rm ";
            if (ui->greedy->isChecked()) MetisOptions+="-iptype=grow ";
            if (ui->random_bisection->isChecked()) MetisOptions+="-iptype=random ";
            if (ui->edge_cut->isChecked()) MetisOptions+="-objtype=cut ";
            if (ui->communication->isChecked()) MetisOptions+="-objtype=vol ";
            graphPart.addMetisParameters(MetisOptions);
        }
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
    this->setFixedSize(592,464);
    ui->greedy->setVisible(false);
    ui->random_bisection->setVisible(false);
    ui->initial->setVisible(false);
    ui->advancedoptions->setVisible(true);

}

void MainWindow::on_basicButton_released()
{
    ui->advancedoptions->setVisible(false);
    this->setFixedSize(592,300); // minimum size
}

void MainWindow::on_recursive_bisection_released()
{

    ui->greedy->setVisible(true);
    ui->random_bisection->setVisible(true);
    ui->initial->setVisible(true);
    ui->edge_cut->setVisible(false);
    ui->communication->setVisible(false);
    ui->minimization->setVisible(false);
}

void MainWindow::on_kway_released()
{
    ui->greedy->setVisible(false);
    ui->random_bisection->setVisible(false);
    ui->initial->setVisible(false);
    ui->edge_cut->setVisible(true);
    ui->communication->setVisible(true);
    ui->minimization->setVisible(true);
}
