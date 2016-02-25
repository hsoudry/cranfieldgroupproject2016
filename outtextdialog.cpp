#include "outtextdialog.h"
#include "ui_outtextdialog.h"

OutTextDialog::OutTextDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OutTextDialog)
{
    ui->setupUi(this);
    table = new QTableWidget(2,2);
    table->show();
    table->setGeometry(0,0,this->width(),this->height());   // TODO: add resising when resizing qdialog
}

OutTextDialog::~OutTextDialog()
{
    delete ui;
}

void OutTextDialog::addData()
{
    table->setRowCount(10);
    table->setColumnCount(3);
    table->setShowGrid(true);

    //QHeaderView m_TableHeader(Qt::Horizontal, this);
    //m_TableHeader<<"#"<<"Name"<<"Text";
    //table->setHorizontalHeaderrLabels(m_TableHeader);

    table->setItem(0, 1, new QTableWidgetItem("Hello"));
}
