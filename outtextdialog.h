#ifndef OUTTEXTDIALOG_H
#define OUTTEXTDIALOG_H

#include <QDialog>
#include <QTableWidget>

namespace Ui {
class OutTextDialog;
}

class OutTextDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OutTextDialog(QWidget *parent = 0);
    ~OutTextDialog();

    void addData();
private:
    Ui::OutTextDialog *ui;
    QTableWidget *table;
};

#endif // OUTTEXTDIALOG_H
