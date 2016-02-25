#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsSvgItem>
#include <QGraphicsView>
#include <QDebug>
#include "graphvizpopup.h"
#include "outtextdialog.h"
#include "graphpart.h"
#include <QFileDialog>
#include <QMessageBox>
#include <vector>
#include <string>
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
    QTableWidget *tableComparison=NULL;

    GraphPart graphPart;
    void closeEvent (QCloseEvent);
    QMessageBox msgbox;

    std::vector<string> paramsNames = {"Vertices", "Edges", "Parts", "Edgecut", "Communicationvol", "Max imbalance"};

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

    void on_pushButtonCompareResults_clicked();
};

#endif // MAINWINDOW_H
