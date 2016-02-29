#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsSvgItem>
#include <QGraphicsView>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>

#include <vector>
#include <string>

#include "graphvizpopup.h"
#include "outtextdialog.h"
#include "graphpart.h"
#include "metisoutput.h"

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
    vector<MetisOutput *> metisOuts;

    QTableWidget *tableCurrent=NULL;

    GraphPart graphPart;
    void closeEvent (QCloseEvent);
    QMessageBox msgbox;

    std::vector<string> paramsNames = {"Vertices", "Edges", "Partitions", "Partitioning", "Matching", "Initial", "Objective fun.", "Edgecut", "Comm. volume",  "Max. imbalance"};

    void export2CSV();
    void showTable();

private slots:
    void on_ButtonVisualize_released();
    void on_ButtonBrowse_released();
    void on_ButtonLoad_released();
    void on_BoxNumberOfPartitions_valueChanged(int arg1);
    void on_advancedButton_released();
    void on_basicButton_released();
    void on_recursive_bisection_released();
    void on_kway_released();
    void on_BoxInputPath_textChanged(const QString);

    void on_pushButtonExit_clicked();
    void on_pushButtonPartition_clicked();
    void on_pushButtonTextOutput_clicked();

    void on_pushButtonExport2CSV_clicked();
    void on_pushButtonPartitionOnly_clicked();
    void on_pushButtonVisualize_clicked();
    void on_BoxNumberOfPartitions_valueChanged(const QString);
    void on_pushButtonClearTable_clicked();
    void on_RadioMesh_clicked();
    void on_RadioGraph_clicked();
};

#endif // MAINWINDOW_H
