#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (wiringPiSetup() == -1){
           QMessageBox::information(this,"Error conf gpio","The gpio could not be configured");
           QApplication::quit();}

    pinMode(LED, OUTPUT);

    bmp180sensor = new Qbmp180();
    rate.setInterval(500);
    connect(&rate,SIGNAL(timeout()),this,SLOT(on_timeOut()));

    //Setting the Graph
    ui->temp_graph->addGraph();
    ui->temp_graph->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
    ui->temp_graph->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue

}

MainWindow::~MainWindow()
{
    delete ui;
    delete bmp180sensor;
}

void MainWindow::on_timeOut(){    
    double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds

//Ask for the variables
    float t = bmp180sensor->read_temperature();
    int p = bmp180sensor->read_pressure();

    ui->temp_graph->graph(0)->addData(key, t);
    ui->temp_graph->graph(0)->removeDataBefore(key - 15);

    ui->temp_graph->rescaleAxes();
    ui->temp_graph->xAxis->setRange(key, 15, Qt::AlignRight);
    ui->temp_graph->yAxis->setRangeLower(0);

    ui->temp_graph->replot();

    ui->lbl_pressure->setText("P : "+QString::number(p/100)+" hPa");
//    ui->listWidget->addItem("t + "+QString::number(rate.interval())+" : "+QString::number(t)+" C - "+QString::number(p)+" Pa");
    digitalWrite(LED, 1);
    delay(90);
    digitalWrite(LED, 0);
}

void MainWindow::on_btn_start_clicked()
{
    rate.start(ui->spinBox_rate->value());
    ui->spinBox_rate->setEnabled(FALSE);
    time = QTime::currentTime();
}

void MainWindow::on_btn_stop_clicked()
{
    rate.stop();
    ui->spinBox_rate->setEnabled(TRUE);
}

void MainWindow::on_btn_clean_clicked()
{
    ui->temp_graph->graph(0)->clearData();
    ui->temp_graph->replot();
}

void MainWindow::on_btn_close_clicked()
{
    QApplication::quit();
}
