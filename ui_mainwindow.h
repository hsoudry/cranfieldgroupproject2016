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
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSpinBox *BoxNumberOfPartitions;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *basicButton;
    QRadioButton *advancedButton;
    QGroupBox *advancedoptions;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_8;
    QLabel *partitionning;
    QSpacerItem *horizontalSpacer_7;
    QRadioButton *kway;
    QSpacerItem *horizontalSpacer_14;
    QRadioButton *recursive_bisection;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_5;
    QLabel *matching;
    QSpacerItem *horizontalSpacer_8;
    QRadioButton *sorted;
    QSpacerItem *horizontalSpacer_15;
    QRadioButton *random_matching;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *InitialPartitioningLayout;
    QLabel *initial;
    QSpacerItem *horizontalSpacer_9;
    QRadioButton *greedy;
    QSpacerItem *horizontalSpacer_16;
    QRadioButton *random_bisection;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_9;
    QLabel *minimization;
    QSpacerItem *horizontalSpacer_6;
    QRadioButton *edge_cut;
    QSpacerItem *horizontalSpacer_17;
    QRadioButton *communication;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_5;
    QDialogButtonBox *ButtonsOkCancel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup_5;
    QButtonGroup *buttonGroup_2;
    QButtonGroup *buttonGroup_3;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_4;
    QButtonGroup *buttonGroup_6;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(592, 464);
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
        buttonGroup_6 = new QButtonGroup(MainWindow);
        buttonGroup_6->setObjectName(QStringLiteral("buttonGroup_6"));
        buttonGroup_6->addButton(RadioGraph);
        RadioGraph->setObjectName(QStringLiteral("RadioGraph"));
        RadioGraph->setChecked(true);

        horizontalLayout->addWidget(RadioGraph);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        RadioMesh = new QRadioButton(groupBox);
        buttonGroup_6->addButton(RadioMesh);
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
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
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
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(label);

        horizontalSpacer = new QSpacerItem(220, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

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

        horizontalSpacer_2 = new QSpacerItem(120, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        basicButton = new QRadioButton(groupBox_3);
        buttonGroup_5 = new QButtonGroup(MainWindow);
        buttonGroup_5->setObjectName(QStringLiteral("buttonGroup_5"));
        buttonGroup_5->addButton(basicButton);
        basicButton->setObjectName(QStringLiteral("basicButton"));
        basicButton->setChecked(true);

        horizontalLayout_7->addWidget(basicButton);

        advancedButton = new QRadioButton(groupBox_3);
        buttonGroup_5->addButton(advancedButton);
        advancedButton->setObjectName(QStringLiteral("advancedButton"));

        horizontalLayout_7->addWidget(advancedButton);


        verticalLayout_4->addLayout(horizontalLayout_7);


        verticalLayout_7->addLayout(verticalLayout_4);

        advancedoptions = new QGroupBox(groupBox_3);
        advancedoptions->setObjectName(QStringLiteral("advancedoptions"));
        advancedoptions->setEnabled(true);
        gridLayout_3 = new QGridLayout(advancedoptions);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        partitionning = new QLabel(advancedoptions);
        partitionning->setObjectName(QStringLiteral("partitionning"));

        horizontalLayout_8->addWidget(partitionning);

        horizontalSpacer_7 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);

        kway = new QRadioButton(advancedoptions);
        buttonGroup_3 = new QButtonGroup(MainWindow);
        buttonGroup_3->setObjectName(QStringLiteral("buttonGroup_3"));
        buttonGroup_3->addButton(kway);
        kway->setObjectName(QStringLiteral("kway"));
        kway->setChecked(true);

        horizontalLayout_8->addWidget(kway);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_14);

        recursive_bisection = new QRadioButton(advancedoptions);
        buttonGroup_3->addButton(recursive_bisection);
        recursive_bisection->setObjectName(QStringLiteral("recursive_bisection"));

        horizontalLayout_8->addWidget(recursive_bisection);

        horizontalSpacer_10 = new QSpacerItem(0, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        matching = new QLabel(advancedoptions);
        matching->setObjectName(QStringLiteral("matching"));
        matching->setEnabled(true);
        sizePolicy.setHeightForWidth(matching->sizePolicy().hasHeightForWidth());
        matching->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(matching);

        horizontalSpacer_8 = new QSpacerItem(76, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);

        sorted = new QRadioButton(advancedoptions);
        buttonGroup_2 = new QButtonGroup(MainWindow);
        buttonGroup_2->setObjectName(QStringLiteral("buttonGroup_2"));
        buttonGroup_2->addButton(sorted);
        sorted->setObjectName(QStringLiteral("sorted"));
        sorted->setChecked(true);

        horizontalLayout_5->addWidget(sorted);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_15);

        random_matching = new QRadioButton(advancedoptions);
        buttonGroup_2->addButton(random_matching);
        random_matching->setObjectName(QStringLiteral("random_matching"));

        horizontalLayout_5->addWidget(random_matching);

        horizontalSpacer_11 = new QSpacerItem(104, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);


        verticalLayout->addLayout(horizontalLayout_5);

        InitialPartitioningLayout = new QHBoxLayout();
        InitialPartitioningLayout->setSpacing(6);
        InitialPartitioningLayout->setObjectName(QStringLiteral("InitialPartitioningLayout"));
        initial = new QLabel(advancedoptions);
        initial->setObjectName(QStringLiteral("initial"));
        sizePolicy.setHeightForWidth(initial->sizePolicy().hasHeightForWidth());
        initial->setSizePolicy(sizePolicy);

        InitialPartitioningLayout->addWidget(initial);

        horizontalSpacer_9 = new QSpacerItem(9, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        InitialPartitioningLayout->addItem(horizontalSpacer_9);

        greedy = new QRadioButton(advancedoptions);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(greedy);
        greedy->setObjectName(QStringLiteral("greedy"));
        greedy->setChecked(true);

        InitialPartitioningLayout->addWidget(greedy);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        InitialPartitioningLayout->addItem(horizontalSpacer_16);

        random_bisection = new QRadioButton(advancedoptions);
        buttonGroup->addButton(random_bisection);
        random_bisection->setObjectName(QStringLiteral("random_bisection"));

        InitialPartitioningLayout->addWidget(random_bisection);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        InitialPartitioningLayout->addItem(horizontalSpacer_12);


        verticalLayout->addLayout(InitialPartitioningLayout);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        minimization = new QLabel(advancedoptions);
        minimization->setObjectName(QStringLiteral("minimization"));

        horizontalLayout_9->addWidget(minimization);

        horizontalSpacer_6 = new QSpacerItem(78, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);

        edge_cut = new QRadioButton(advancedoptions);
        buttonGroup_4 = new QButtonGroup(MainWindow);
        buttonGroup_4->setObjectName(QStringLiteral("buttonGroup_4"));
        buttonGroup_4->addButton(edge_cut);
        edge_cut->setObjectName(QStringLiteral("edge_cut"));
        edge_cut->setChecked(true);

        horizontalLayout_9->addWidget(edge_cut);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_17);

        communication = new QRadioButton(advancedoptions);
        buttonGroup_4->addButton(communication);
        communication->setObjectName(QStringLiteral("communication"));

        horizontalLayout_9->addWidget(communication);

        horizontalSpacer_13 = new QSpacerItem(0, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_13);


        verticalLayout->addLayout(horizontalLayout_9);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 1);


        verticalLayout_7->addWidget(advancedoptions);


        verticalLayout_5->addLayout(verticalLayout_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_5);

        ButtonsOkCancel = new QDialogButtonBox(groupBox_3);
        ButtonsOkCancel->setObjectName(QStringLiteral("ButtonsOkCancel"));
        ButtonsOkCancel->setOrientation(Qt::Horizontal);
        ButtonsOkCancel->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_10->addWidget(ButtonsOkCancel);


        verticalLayout_5->addLayout(horizontalLayout_10);


        gridLayout_5->addLayout(verticalLayout_5, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox_3);


        gridLayout_4->addLayout(verticalLayout_3, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 592, 25));
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
        label->setText(QApplication::translate("MainWindow", "Number of partitions :", 0));
        basicButton->setText(QApplication::translate("MainWindow", "Basic partitionning", 0));
        advancedButton->setText(QApplication::translate("MainWindow", "Advanced partitionning", 0));
        advancedoptions->setTitle(QString());
        partitionning->setText(QApplication::translate("MainWindow", "Partitionning :", 0));
        kway->setText(QApplication::translate("MainWindow", "k-way partitionning", 0));
        recursive_bisection->setText(QApplication::translate("MainWindow", "Recursive bisectionning", 0));
        matching->setText(QApplication::translate("MainWindow", "Matching :", 0));
        sorted->setText(QApplication::translate("MainWindow", "Sorted heavy-edge", 0));
        random_matching->setText(QApplication::translate("MainWindow", "Random", 0));
        initial->setText(QApplication::translate("MainWindow", "Initial partitionning :", 0));
        greedy->setText(QApplication::translate("MainWindow", "Greedy", 0));
        random_bisection->setText(QApplication::translate("MainWindow", "Random bisection", 0));
        minimization->setText(QApplication::translate("MainWindow", "Minimize :", 0));
        edge_cut->setText(QApplication::translate("MainWindow", "Edge-cut", 0));
        communication->setText(QApplication::translate("MainWindow", "Communication volume", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
