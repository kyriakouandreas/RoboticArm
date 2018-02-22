/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QCustomPlot *temp_graph;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbl_pressure;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpinBox *spinBox_rate;
    QPushButton *btn_start;
    QPushButton *btn_stop;
    QPushButton *btn_clean;
    QPushButton *btn_close;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(481, 416);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        temp_graph = new QCustomPlot(centralWidget);
        temp_graph->setObjectName(QStringLiteral("temp_graph"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(temp_graph->sizePolicy().hasHeightForWidth());
        temp_graph->setSizePolicy(sizePolicy);
        temp_graph->setMinimumSize(QSize(461, 231));

        verticalLayout_3->addWidget(temp_graph);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lbl_pressure = new QLabel(centralWidget);
        lbl_pressure->setObjectName(QStringLiteral("lbl_pressure"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lbl_pressure->sizePolicy().hasHeightForWidth());
        lbl_pressure->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(lbl_pressure);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label);

        spinBox_rate = new QSpinBox(centralWidget);
        spinBox_rate->setObjectName(QStringLiteral("spinBox_rate"));
        spinBox_rate->setMinimum(100);
        spinBox_rate->setMaximum(5000);
        spinBox_rate->setValue(500);

        verticalLayout->addWidget(spinBox_rate);


        horizontalLayout->addLayout(verticalLayout);

        btn_start = new QPushButton(centralWidget);
        btn_start->setObjectName(QStringLiteral("btn_start"));

        horizontalLayout->addWidget(btn_start);

        btn_stop = new QPushButton(centralWidget);
        btn_stop->setObjectName(QStringLiteral("btn_stop"));

        horizontalLayout->addWidget(btn_stop);

        btn_clean = new QPushButton(centralWidget);
        btn_clean->setObjectName(QStringLiteral("btn_clean"));

        horizontalLayout->addWidget(btn_clean);

        btn_close = new QPushButton(centralWidget);
        btn_close->setObjectName(QStringLiteral("btn_close"));

        horizontalLayout->addWidget(btn_close);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 481, 26));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        lbl_pressure->setText(QApplication::translate("MainWindow", "P: ", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Sample Rate:  ", Q_NULLPTR));
        spinBox_rate->setSuffix(QApplication::translate("MainWindow", "ms", Q_NULLPTR));
        btn_start->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        btn_stop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        btn_clean->setText(QApplication::translate("MainWindow", "Clean", Q_NULLPTR));
        btn_close->setText(QApplication::translate("MainWindow", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
