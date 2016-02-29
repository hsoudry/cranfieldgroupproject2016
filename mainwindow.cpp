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
    ui->pushButtonTextOutput->setEnabled(false);
    ui->pushButtonExport2CSV->setEnabled(false);
    ui->pushButtonPartitionOnly->setEnabled(false);
    ui->pushButtonVisualize->setEnabled(false);
    ui->radioButtonM2GDual->setEnabled(false);
    ui->radioButtonM2GNodal->setEnabled(false);
    ui->advancedoptions->setVisible(false);
    this->setFixedSize(592,380); //minimum size
    msgbox.setWindowTitle(" ");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent)
{
    if(tableCurrent) delete tableCurrent;
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
    if (!ui->BoxInputPath->text().isEmpty())
    {
        graphPart.setInputFileName(ui->BoxInputPath->text().toStdString());
        if(ui->RadioGraph->isChecked()) {
            if(!graphPart.SetInputType(graph)){
                msgbox.setText("Wrong type of input file!");
                msgbox.exec();
                ui->pushButtonVisualize->setEnabled(false);
                ui->pushButtonPartition->setEnabled(false);
                ui->pushButtonPartitionOnly->setEnabled(false);
                return;
            }
        }
        else{
            Mesh2GraphType m2g;
            if(ui->radioButtonM2GDual->isChecked())
                m2g = dual;
            if(ui->radioButtonM2GNodal->isChecked())
                m2g = nodal;

            if(!graphPart.SetInputType(mesh, m2g)){
                msgbox.setText("Wrong type of input file!");
                msgbox.exec();
                ui->pushButtonVisualize->setEnabled(false);
                ui->pushButtonPartition->setEnabled(false);
                ui->pushButtonPartitionOnly->setEnabled(false);
                return;
            }
        }
        if(graphPart.isDrawable()){
            ui->statusBar->showMessage("Loading the graph (please wait) ...");
            graphPart.SvgPrepare();
            ui->ButtonVisualize->setEnabled(true);
            ui->pushButtonPartition->setEnabled(true);
            ui->pushButtonPartitionOnly->setEnabled(true);
            ui->statusBar->showMessage("");
        }
        else{
            msgbox.setText("Graph is too big to visualize! You can only prepare partitions file");
            msgbox.exec();

            ui->pushButtonPartitionOnly->setEnabled(true);
        }
        ui->pushButtonVisualize->setEnabled(false);
        //ui->pushButtonPartition->setEnabled(false);
        //ui->pushButtonPartitionOnly->setEnabled(false);
    }
    else{
        msgbox.setText("No file path chosen!");
        msgbox.exec();
    }
}

void MainWindow::on_BoxNumberOfPartitions_valueChanged(int arg1)
{
    graphPart.setNumberOfPart(arg1);
}

void MainWindow::on_advancedButton_released()
{
    this->setFixedSize(592,492);
    ui->greedy->setVisible(false);
    ui->random_bisection->setVisible(false);
    ui->initial->setVisible(false);
    ui->advancedoptions->setVisible(true);
}

void MainWindow::on_basicButton_released()
{
    ui->advancedoptions->setVisible(false);
    this->setFixedSize(592,380); // minimum size
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
        metisOuts.push_back(new MetisOutput(graphPart.Partition(),graphPart.extractName()));

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
            ui->pushButtonVisualize->setEnabled(true);
        }
        else
        {
            msgbox.setText("Graph is too big to visualize! (only partitions file was prepared)");
            msgbox.exec();
        }
        ui->pushButtonTextOutput->setEnabled(true);
    }
    else
    {
        msgbox.setText("Graph is not loaded!");
        msgbox.exec();
    }
}

void MainWindow::on_pushButtonTextOutput_clicked()
{
    showTable();
}

void MainWindow::showTable()
{
    if(tableCurrent != NULL) delete tableCurrent;
    tableCurrent = new QTableWidget(paramsNames.size()+1,metisOuts.size());
    tableCurrent->setWindowTitle("Result comparison");
    tableCurrent->show();

    int sizeExtend = tableCurrent->columnCount();
    sizeExtend *= 100;

    tableCurrent->setGeometry(30,30,150+sizeExtend,380);

    QStringList m_TableHeaderV;
    m_TableHeaderV << "Name";
    for(int i = 0; i<paramsNames.size(); i++)
    {
        m_TableHeaderV << QString::fromStdString(paramsNames[i]);
    }
    tableCurrent->setVerticalHeaderLabels(m_TableHeaderV);

    for(int j = 0; j<metisOuts.size(); j++)
    {
        QTableWidgetItem *tableItem_y10 = new QTableWidgetItem(QString::fromStdString(metisOuts[j]->GetName()));
        tableCurrent->setItem(0, j, tableItem_y10);

        QTableWidgetItem *tableItem_y0 = new QTableWidgetItem(QString::number(metisOuts[j]->GetNoOfVertices()));
        tableCurrent->setItem(1, j, tableItem_y0);
        QTableWidgetItem *tableItem_y1 = new QTableWidgetItem(QString::number(metisOuts[j]->GetNoOfEdges()));
        tableCurrent->setItem(2, j, tableItem_y1);
        QTableWidgetItem *tableItem_y2 = new QTableWidgetItem(QString::number(metisOuts[j]->GetNoOfParts()));
        tableCurrent->setItem(3, j, tableItem_y2);
        QTableWidgetItem *tableItem_y3 = new QTableWidgetItem(QString::number(metisOuts[j]->GetEdgeCut()));
        tableCurrent->setItem(8, j, tableItem_y3);
        QTableWidgetItem *tableItem_y4 = new QTableWidgetItem(QString::number(metisOuts[j]->GetCommunicationVol()));
        tableCurrent->setItem(9, j, tableItem_y4);
        QTableWidgetItem *tableItem_y5 = new QTableWidgetItem(QString::number((metisOuts[j]->GetMaxImbalance()-1)*100)+"%");
        tableCurrent->setItem(10, j, tableItem_y5);
        QTableWidgetItem *tableItem_y6 = new QTableWidgetItem(QString::fromStdString(metisOuts[j]->GetPtype()));
        tableCurrent->setItem(4, j, tableItem_y6);
        QTableWidgetItem *tableItem_y7 = new QTableWidgetItem(QString::fromStdString(metisOuts[j]->GetObjtype()));
        tableCurrent->setItem(5, j, tableItem_y7);
        QTableWidgetItem *tableItem_y8 = new QTableWidgetItem(QString::fromStdString(metisOuts[j]->GetCtype()));
        tableCurrent->setItem(6, j, tableItem_y8);
        QTableWidgetItem *tableItem_y9 = new QTableWidgetItem(QString::fromStdString(metisOuts[j]->GetIptype()));
        tableCurrent->setItem(7, j, tableItem_y9);

        tableItem_y0->setFlags(tableItem_y0->flags() ^ Qt::ItemIsEditable);
        tableItem_y1->setFlags(tableItem_y1->flags() ^ Qt::ItemIsEditable);
        tableItem_y2->setFlags(tableItem_y2->flags() ^ Qt::ItemIsEditable);
        tableItem_y3->setFlags(tableItem_y3->flags() ^ Qt::ItemIsEditable);
        tableItem_y4->setFlags(tableItem_y4->flags() ^ Qt::ItemIsEditable);
        tableItem_y5->setFlags(tableItem_y5->flags() ^ Qt::ItemIsEditable);
        tableItem_y6->setFlags(tableItem_y6->flags() ^ Qt::ItemIsEditable);
        tableItem_y7->setFlags(tableItem_y7->flags() ^ Qt::ItemIsEditable);
        tableItem_y8->setFlags(tableItem_y8->flags() ^ Qt::ItemIsEditable);
        tableItem_y9->setFlags(tableItem_y9->flags() ^ Qt::ItemIsEditable);
    }
    ui->pushButtonExport2CSV->setEnabled(true);
}

void MainWindow::export2CSV()
{
    if(tableCurrent->item(0,0) !=0 )
    {
        QDateTime dateTime = QDateTime::currentDateTime();
        string path = "history_" + dateTime.toString(Qt::ISODate).toStdString() + ".csv";

        QFile f( QString::fromStdString(path) );

        if (f.open(QFile::WriteOnly | QFile::Truncate))
        {

            QTextStream data( &f );
            QStringList strList;

            for( int r = 0; r < tableCurrent->rowCount(); ++r )
            {
                strList.clear();
                strList << "\" " + tableCurrent->verticalHeaderItem(r)->text() + "\" ";  //data(Qt::DisplayRole).toString()
                for( int c = 0; c < tableCurrent->columnCount(); ++c )
                {
                    strList << "\" " + tableCurrent->item( r, c )->text() + "\" ";
                }
                data << strList.join( ";" )+"\n";
            }
            f.close();
        }
    }
    else
    {
        msgbox.setText("No data in the table!");
        msgbox.exec();
    }
}

void MainWindow::on_pushButtonExport2CSV_clicked()
{
    export2CSV();
}

void MainWindow::on_pushButtonPartitionOnly_clicked()
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
        metisOuts.push_back(new MetisOutput(graphPart.Partition(),graphPart.extractName()));

        graphPart.GraphColoring();

        ui->pushButtonTextOutput->setEnabled(true);
        ui->pushButtonVisualize->setEnabled(true);
    }
    else
    {
        msgbox.setText("Graph is not loaded!");
        msgbox.exec();
    }
}

void MainWindow::on_pushButtonVisualize_clicked()
{
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
        msgbox.setText("Graph is too big to visualize!");
        msgbox.exec();
    }
}

void MainWindow::on_BoxNumberOfPartitions_valueChanged(const QString)
{
    ui->pushButtonVisualize->setEnabled(false);
}

void MainWindow::on_pushButtonClearTable_clicked()
{
    if(tableCurrent != NULL) tableCurrent->clearContents();

    for(int i = 0; i<metisOuts.size(); ++i)
    {
        delete metisOuts.at(i);
    }

    metisOuts.clear();

}

void MainWindow::on_RadioMesh_clicked()
{
    ui->radioButtonM2GDual->setEnabled(true);
    ui->radioButtonM2GNodal->setEnabled(true);
    ui->radioButtonM2GDual->setChecked(true);
}

void MainWindow::on_RadioGraph_clicked()
{
    ui->radioButtonM2GDual->setEnabled(false);
    ui->radioButtonM2GNodal->setEnabled(false);
}
