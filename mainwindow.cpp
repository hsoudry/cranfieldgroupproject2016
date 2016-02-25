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
    ui->pushButtonPartition->setEnabled(false);
    ui->advancedoptions->setVisible(false);
    this->setFixedSize(592,300); //minimum size
    msgbox.setWindowTitle(" ");
    metisOuts.push_back(new MetisOutput("out.txt"));
    cout<<metisOuts.at(0)->GetMaxImbalance();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent)
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
            msgbox.setText("Graph is too big to visualize!");
            msgbox.exec();
        }
    }
    else
    {
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
    if(ui->RadioGraph->isChecked()) {
        if(!graphPart.SetInputType(graph)){
            msgbox.setText("Wrong type of input file!");
            msgbox.exec();
            return;
        }
    }
    else{
        if(!graphPart.SetInputType(mesh)){
            msgbox.setText("Wrong type of input file!");
            msgbox.exec();
            return;
        }
    }
    if(graphPart.isDrawable()){
        ui->statusBar->showMessage("Graph is loading...");
        graphPart.SvgPrepare();
        ui->ButtonVisualize->setEnabled(true);
        ui->pushButtonPartition->setEnabled(true);
        ui->statusBar->showMessage("");
    }
    else{
        msgbox.setText("Graph is too big to visualize! You can only prepare partitions file");
        msgbox.exec();
    }

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

void MainWindow::on_BoxInputPath_textChanged(const QString)
{
    ui->ButtonVisualize->setEnabled(false);
}

void MainWindow::on_pushButtonExit_clicked()
{
    this->close();
}

void MainWindow::on_pushButtonPartition_clicked()
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
                msgbox.setText("Graph is too big to visualize! (only partitions file was prepared)");
                msgbox.exec();
            }
        }
        else
        {
            msgbox.setText("Graph is not loaded!");
            msgbox.exec();
        }
}
