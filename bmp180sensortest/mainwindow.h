#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCoreApplication>
#include <QtGui>
#include <QString>
#include <QThread>
#include <QMutex>
#include <QTimer>
#include <QTime>
#include <stdlib.h>
#include <stdint.h>
#include "bmp180.h"

#define LED 7

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_start_clicked();

    void on_btn_stop_clicked();

    void on_btn_clean_clicked();

    void on_btn_close_clicked();

    void on_timeOut();

private:
    Ui::MainWindow *ui;
    QTimer rate;
    Qbmp180* bmp180sensor;
    QTime time;
};

#endif // MAINWINDOW_H
