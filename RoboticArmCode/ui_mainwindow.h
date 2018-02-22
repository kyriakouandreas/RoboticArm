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
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
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
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *lbl_motoSA;
    QDial *dial_MotorSA;
    QRadioButton *rBtn_MtrSA;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbl_motorSB;
    QDial *dial_MotorSB;
    QRadioButton *rBtn_MtrSB;
    QVBoxLayout *verticalLayout_3;
    QLabel *lbl_motorElbow;
    QDial *dial_MotorElbow;
    QRadioButton *rBtn_MtrElbow;
    QVBoxLayout *verticalLayout_4;
    QLabel *lbl_motorClamp;
    QDial *dial_MotorClamp;
    QRadioButton *rBtn_MtrClaw;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QSlider *vSdr_speed;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QRadioButton *rBtn_MtrNone;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QCustomPlot *temp_graph;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QPushButton *pBtn_reset;
    QPushButton *pBtn_close;
    QPushButton *pBtn_setinitPos;
    QDoubleSpinBox *dsBox_tempLimit;
    QSpacerItem *verticalSpacer_2;
    QLabel *lbl_actualTemp;
    QLabel *lbl_actualPressure;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(580, 506);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_10 = new QVBoxLayout(centralWidget);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lbl_motoSA = new QLabel(groupBox);
        lbl_motoSA->setObjectName(QStringLiteral("lbl_motoSA"));

        verticalLayout->addWidget(lbl_motoSA);

        dial_MotorSA = new QDial(groupBox);
        dial_MotorSA->setObjectName(QStringLiteral("dial_MotorSA"));
        dial_MotorSA->setMaximum(180);
        dial_MotorSA->setSliderPosition(90);
        dial_MotorSA->setInvertedAppearance(false);
        dial_MotorSA->setInvertedControls(false);

        verticalLayout->addWidget(dial_MotorSA);

        rBtn_MtrSA = new QRadioButton(groupBox);
        rBtn_MtrSA->setObjectName(QStringLiteral("rBtn_MtrSA"));

        verticalLayout->addWidget(rBtn_MtrSA);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lbl_motorSB = new QLabel(groupBox);
        lbl_motorSB->setObjectName(QStringLiteral("lbl_motorSB"));

        verticalLayout_2->addWidget(lbl_motorSB);

        dial_MotorSB = new QDial(groupBox);
        dial_MotorSB->setObjectName(QStringLiteral("dial_MotorSB"));
        dial_MotorSB->setMaximum(180);
        dial_MotorSB->setSliderPosition(90);
        dial_MotorSB->setInvertedAppearance(false);
        dial_MotorSB->setInvertedControls(false);

        verticalLayout_2->addWidget(dial_MotorSB);

        rBtn_MtrSB = new QRadioButton(groupBox);
        rBtn_MtrSB->setObjectName(QStringLiteral("rBtn_MtrSB"));

        verticalLayout_2->addWidget(rBtn_MtrSB);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lbl_motorElbow = new QLabel(groupBox);
        lbl_motorElbow->setObjectName(QStringLiteral("lbl_motorElbow"));

        verticalLayout_3->addWidget(lbl_motorElbow);

        dial_MotorElbow = new QDial(groupBox);
        dial_MotorElbow->setObjectName(QStringLiteral("dial_MotorElbow"));
        dial_MotorElbow->setMaximum(180);
        dial_MotorElbow->setSliderPosition(90);
        dial_MotorElbow->setInvertedAppearance(false);
        dial_MotorElbow->setInvertedControls(false);

        verticalLayout_3->addWidget(dial_MotorElbow);

        rBtn_MtrElbow = new QRadioButton(groupBox);
        rBtn_MtrElbow->setObjectName(QStringLiteral("rBtn_MtrElbow"));

        verticalLayout_3->addWidget(rBtn_MtrElbow);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        lbl_motorClamp = new QLabel(groupBox);
        lbl_motorClamp->setObjectName(QStringLiteral("lbl_motorClamp"));

        verticalLayout_4->addWidget(lbl_motorClamp);

        dial_MotorClamp = new QDial(groupBox);
        dial_MotorClamp->setObjectName(QStringLiteral("dial_MotorClamp"));
        dial_MotorClamp->setMaximum(30);
        dial_MotorClamp->setValue(15);
        dial_MotorClamp->setSliderPosition(15);
        dial_MotorClamp->setInvertedAppearance(false);
        dial_MotorClamp->setInvertedControls(false);

        verticalLayout_4->addWidget(dial_MotorClamp);

        rBtn_MtrClaw = new QRadioButton(groupBox);
        rBtn_MtrClaw->setObjectName(QStringLiteral("rBtn_MtrClaw"));

        verticalLayout_4->addWidget(rBtn_MtrClaw);


        horizontalLayout->addLayout(verticalLayout_4);


        horizontalLayout_3->addLayout(horizontalLayout);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        vSdr_speed = new QSlider(groupBox);
        vSdr_speed->setObjectName(QStringLiteral("vSdr_speed"));
        vSdr_speed->setMinimum(5);
        vSdr_speed->setMaximum(15);
        vSdr_speed->setOrientation(Qt::Vertical);
        vSdr_speed->setInvertedAppearance(true);
        vSdr_speed->setInvertedControls(true);

        horizontalLayout_2->addWidget(vSdr_speed);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_5->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_5->addWidget(label_2);


        horizontalLayout_2->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_2);

        rBtn_MtrNone = new QRadioButton(groupBox);
        rBtn_MtrNone->setObjectName(QStringLiteral("rBtn_MtrNone"));
        rBtn_MtrNone->setChecked(true);

        verticalLayout_6->addWidget(rBtn_MtrNone);


        horizontalLayout_3->addLayout(verticalLayout_6);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_10->addWidget(groupBox);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        temp_graph = new QCustomPlot(centralWidget);
        temp_graph->setObjectName(QStringLiteral("temp_graph"));
        temp_graph->setMinimumSize(QSize(421, 0));

        horizontalLayout_5->addWidget(temp_graph);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_8 = new QVBoxLayout(groupBox_2);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        pBtn_reset = new QPushButton(groupBox_2);
        pBtn_reset->setObjectName(QStringLiteral("pBtn_reset"));

        verticalLayout_7->addWidget(pBtn_reset);

        pBtn_close = new QPushButton(groupBox_2);
        pBtn_close->setObjectName(QStringLiteral("pBtn_close"));

        verticalLayout_7->addWidget(pBtn_close);

        pBtn_setinitPos = new QPushButton(groupBox_2);
        pBtn_setinitPos->setObjectName(QStringLiteral("pBtn_setinitPos"));

        verticalLayout_7->addWidget(pBtn_setinitPos);

        dsBox_tempLimit = new QDoubleSpinBox(groupBox_2);
        dsBox_tempLimit->setObjectName(QStringLiteral("dsBox_tempLimit"));
        dsBox_tempLimit->setSingleStep(0.1);
        dsBox_tempLimit->setValue(50);

        verticalLayout_7->addWidget(dsBox_tempLimit);


        verticalLayout_8->addLayout(verticalLayout_7);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_2);

        lbl_actualTemp = new QLabel(groupBox_2);
        lbl_actualTemp->setObjectName(QStringLiteral("lbl_actualTemp"));

        verticalLayout_8->addWidget(lbl_actualTemp);

        lbl_actualPressure = new QLabel(groupBox_2);
        lbl_actualPressure->setObjectName(QStringLiteral("lbl_actualPressure"));

        verticalLayout_8->addWidget(lbl_actualPressure);


        verticalLayout_9->addWidget(groupBox_2);


        horizontalLayout_5->addLayout(verticalLayout_9);


        verticalLayout_10->addLayout(horizontalLayout_5);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 580, 26));
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
        groupBox->setTitle(QApplication::translate("MainWindow", "Arm Controls", Q_NULLPTR));
        lbl_motoSA->setText(QApplication::translate("MainWindow", "Shoulder A: ", Q_NULLPTR));
        rBtn_MtrSA->setText(QApplication::translate("MainWindow", "Export", Q_NULLPTR));
        lbl_motorSB->setText(QApplication::translate("MainWindow", "Shoulder B:", Q_NULLPTR));
        rBtn_MtrSB->setText(QApplication::translate("MainWindow", "Export", Q_NULLPTR));
        lbl_motorElbow->setText(QApplication::translate("MainWindow", "Elbow:", Q_NULLPTR));
        rBtn_MtrElbow->setText(QApplication::translate("MainWindow", "Export", Q_NULLPTR));
        lbl_motorClamp->setText(QApplication::translate("MainWindow", "Clamp:", Q_NULLPTR));
        rBtn_MtrClaw->setText(QApplication::translate("MainWindow", "Export", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Fast", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Slow", Q_NULLPTR));
        rBtn_MtrNone->setText(QApplication::translate("MainWindow", "None", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Actions", Q_NULLPTR));
        pBtn_reset->setText(QApplication::translate("MainWindow", "Reset", Q_NULLPTR));
        pBtn_close->setText(QApplication::translate("MainWindow", "Close", Q_NULLPTR));
        pBtn_setinitPos->setText(QApplication::translate("MainWindow", "Set Initial Pos", Q_NULLPTR));
        dsBox_tempLimit->setPrefix(QString());
        dsBox_tempLimit->setSuffix(QApplication::translate("MainWindow", "C", Q_NULLPTR));
        lbl_actualTemp->setText(QApplication::translate("MainWindow", "Temp :", Q_NULLPTR));
        lbl_actualPressure->setText(QApplication::translate("MainWindow", "Pressure :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
