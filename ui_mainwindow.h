/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *BoxInputPath;
    QPushButton *ButtonBrowse;
    QHBoxLayout *horizontalLayout;
    QRadioButton *RadioGraph;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *RadioMesh;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *ButtonLoad;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPushButton *ButtonVisualize;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSpinBox *BoxNumberOfPartitions;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *radioButton;
    QRadioButton *advancedButton;
    QGroupBox *advancedoptions;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_9;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_3;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *radioButton_10;
    QRadioButton *radioButton_8;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_4;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_5;
    QDialogButtonBox *ButtonsOkCancel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(624, 476);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setAutoFillBackground(false);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        BoxInputPath = new QLineEdit(groupBox);
        BoxInputPath->setObjectName(QStringLiteral("BoxInputPath"));

        horizontalLayout_6->addWidget(BoxInputPath);

        ButtonBrowse = new QPushButton(groupBox);
        ButtonBrowse->setObjectName(QStringLiteral("ButtonBrowse"));

        horizontalLayout_6->addWidget(ButtonBrowse);


        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        RadioGraph = new QRadioButton(groupBox);
        RadioGraph->setObjectName(QStringLiteral("RadioGraph"));
        RadioGraph->setChecked(true);

        horizontalLayout->addWidget(RadioGraph);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        RadioMesh = new QRadioButton(groupBox);
        RadioMesh->setObjectName(QStringLiteral("RadioMesh"));

        horizontalLayout->addWidget(RadioMesh);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        ButtonLoad = new QPushButton(groupBox);
        ButtonLoad->setObjectName(QStringLiteral("ButtonLoad"));

        horizontalLayout->addWidget(ButtonLoad);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        horizontalLayout_3->addWidget(groupBox);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        ButtonVisualize = new QPushButton(groupBox_2);
        ButtonVisualize->setObjectName(QStringLiteral("ButtonVisualize"));

        gridLayout_2->addWidget(ButtonVisualize, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_2);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setFlat(false);
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(label);

        horizontalSpacer = new QSpacerItem(220, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        BoxNumberOfPartitions = new QSpinBox(groupBox_3);
        BoxNumberOfPartitions->setObjectName(QStringLiteral("BoxNumberOfPartitions"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(BoxNumberOfPartitions->sizePolicy().hasHeightForWidth());
        BoxNumberOfPartitions->setSizePolicy(sizePolicy1);
        BoxNumberOfPartitions->setMinimum(2);
        BoxNumberOfPartitions->setMaximum(999);

        horizontalLayout_4->addWidget(BoxNumberOfPartitions);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_7->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        radioButton = new QRadioButton(groupBox_3);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(true);

        horizontalLayout_7->addWidget(radioButton);

        advancedButton = new QRadioButton(groupBox_3);
        advancedButton->setObjectName(QStringLiteral("advancedButton"));

        horizontalLayout_7->addWidget(advancedButton);


        verticalLayout_7->addLayout(horizontalLayout_7);


        verticalLayout_5->addLayout(verticalLayout_7);

        advancedoptions = new QGroupBox(groupBox_3);
        advancedoptions->setObjectName(QStringLiteral("advancedoptions"));
        advancedoptions->setEnabled(true);
        gridLayout_3 = new QGridLayout(advancedoptions);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(advancedoptions);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(label_5);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);


        verticalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_4 = new QLabel(advancedoptions);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setEnabled(true);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(label_4);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);


        verticalLayout_6->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_3 = new QLabel(advancedoptions);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_9->addWidget(label_3);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_7);


        verticalLayout_6->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_2 = new QLabel(advancedoptions);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_10->addWidget(label_2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_6);


        verticalLayout_6->addLayout(horizontalLayout_10);


        horizontalLayout_12->addLayout(verticalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButton_9 = new QRadioButton(advancedoptions);
        radioButton_9->setObjectName(QStringLiteral("radioButton_9"));

        verticalLayout->addWidget(radioButton_9);

        radioButton_7 = new QRadioButton(advancedoptions);
        radioButton_7->setObjectName(QStringLiteral("radioButton_7"));

        verticalLayout->addWidget(radioButton_7);

        radioButton_5 = new QRadioButton(advancedoptions);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));

        verticalLayout->addWidget(radioButton_5);

        radioButton_3 = new QRadioButton(advancedoptions);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout->addWidget(radioButton_3);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        radioButton_10 = new QRadioButton(advancedoptions);
        radioButton_10->setObjectName(QStringLiteral("radioButton_10"));

        verticalLayout_4->addWidget(radioButton_10);

        radioButton_8 = new QRadioButton(advancedoptions);
        radioButton_8->setObjectName(QStringLiteral("radioButton_8"));

        verticalLayout_4->addWidget(radioButton_8);

        radioButton_6 = new QRadioButton(advancedoptions);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));

        verticalLayout_4->addWidget(radioButton_6);

        radioButton_4 = new QRadioButton(advancedoptions);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        verticalLayout_4->addWidget(radioButton_4);


        horizontalLayout_2->addLayout(verticalLayout_4);


        horizontalLayout_12->addLayout(horizontalLayout_2);


        gridLayout_3->addLayout(horizontalLayout_12, 0, 0, 1, 1);


        verticalLayout_5->addWidget(advancedoptions);


        gridLayout_5->addLayout(verticalLayout_5, 0, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_5);

        ButtonsOkCancel = new QDialogButtonBox(groupBox_3);
        ButtonsOkCancel->setObjectName(QStringLiteral("ButtonsOkCancel"));
        ButtonsOkCancel->setOrientation(Qt::Horizontal);
        ButtonsOkCancel->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_11->addWidget(ButtonsOkCancel);


        gridLayout_5->addLayout(horizontalLayout_11, 1, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox_3);


        gridLayout_4->addLayout(verticalLayout_3, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 624, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "GraphPart", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Step 1", 0));
        ButtonBrowse->setText(QApplication::translate("MainWindow", "Browse", 0));
        RadioGraph->setText(QApplication::translate("MainWindow", "Graph", 0));
        RadioMesh->setText(QApplication::translate("MainWindow", "Mesh", 0));
        ButtonLoad->setText(QApplication::translate("MainWindow", "Load", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Step 2", 0));
        ButtonVisualize->setText(QApplication::translate("MainWindow", "Visualize", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Step 3", 0));
        label->setText(QApplication::translate("MainWindow", "Number of partitions", 0));
        radioButton->setText(QApplication::translate("MainWindow", "Basic", 0));
        advancedButton->setText(QApplication::translate("MainWindow", "Advanced", 0));
        advancedoptions->setTitle(QString());
        label_5->setText(QApplication::translate("MainWindow", "Initial partitionning :", 0));
        label_4->setText(QApplication::translate("MainWindow", "Matching :", 0));
        label_3->setText(QApplication::translate("MainWindow", "Partitionning :", 0));
        label_2->setText(QApplication::translate("MainWindow", "Minimize :", 0));
        radioButton_9->setText(QApplication::translate("MainWindow", "Greedy", 0));
        radioButton_7->setText(QApplication::translate("MainWindow", "Random", 0));
        radioButton_5->setText(QApplication::translate("MainWindow", "Recursive bisectionning", 0));
        radioButton_3->setText(QApplication::translate("MainWindow", "Edge-cut", 0));
        radioButton_10->setText(QApplication::translate("MainWindow", "Sorted heavy-edge", 0));
        radioButton_8->setText(QApplication::translate("MainWindow", "Sorted heavy-edge", 0));
        radioButton_6->setText(QApplication::translate("MainWindow", "k-way partitionning", 0));
        radioButton_4->setText(QApplication::translate("MainWindow", "Communication volume", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
