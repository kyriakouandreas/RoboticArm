#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Servos Init
    servoi2c = new ServoController(SERCONT_ADDRESS, MODE_EXTND);
    servoi2c->addMotor(ui->sBox_addrSA->value(), 90, 0, 180);
    servoi2c->addMotor(ui->sBox_addrSB->value(), 90, 0, 180);
    servoi2c->addMotor(ui->sBox_addrE->value(),90, 0, 180);
    servoi2c->addMotor(ui->sBox_addrC->value(),0,0,35);//OPEN,BETWEEN 0 and 35 degrees

    //Sensor thread Init
    sensorThread = new SensorThread();
    time = QTime::currentTime();
    connect(sensorThread,SIGNAL(sensevalues(float,int)),this,SLOT(on_valuesread(float,int)));
    sensorThread->setParent(this);
    sensorThread->start();

    //Buttons Thread
    btnThread = new ButtonsThread(0,0,servoi2c);
    connect(btnThread,SIGNAL(keyrelease(int)),this,SLOT(on_keyrelease(int)));
    connect(btnThread,SIGNAL(updatePos(int)),this,SLOT(on_updatepos(int)));
    btnThread->setParent(this);

    //Setting the Graph
    ui->temp_graph->addGraph();
    ui->temp_graph->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
    ui->temp_graph->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
    ui->temp_graph->xAxis->setLabel("time(sec)");
    ui->temp_graph->yAxis->setLabel("T(C)");


}

MainWindow::~MainWindow()
{
    delete ui;    
    delete servoi2c;
    delete sensorThread;
    delete btnThread;
}

void MainWindow::on_pBtn_reset_clicked()
{
    //Reset Actions
    time = QTime::currentTime();
}

void MainWindow::on_pBtn_close_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pBtn_setinitPos_clicked()
{

}

void MainWindow::on_dial_MotorClamp_valueChanged(int value)
{
    main_mutex.lock();
    servoi2c->motorPos(ui->sBox_addrC->value(),value);
    main_mutex.unlock();
}

void MainWindow::on_dial_MotorElbow_valueChanged(int value)
{
    main_mutex.lock();
    servoi2c->motorPos(ui->sBox_addrE->value(),value);
    main_mutex.unlock();
}

void MainWindow::on_dial_MotorSB_valueChanged(int value)
{
    main_mutex.lock();
    servoi2c->motorPos(ui->sBox_addrSB->value(),value);
    main_mutex.unlock();
}

void MainWindow::on_dial_MotorSA_valueChanged(int value)
{
    main_mutex.lock();
    servoi2c->motorPos(ui->sBox_addrSA->value(),value);
    main_mutex.unlock();
}

void MainWindow::on_vSdr_speed_valueChanged(int value)
{

}

void MainWindow::on_keyrelease(){
    btnThread->wait();
    btnThread->terminate();
}

void MainWindow::on_updatepos(int p){
    if(!(ui->sBox_addrSA->isEnabled())){
        ui->dial_MotorSA->setValue(p);
    }
    if(!(ui->sBox_addrSB->isEnabled())){
        ui->dial_MotorSB->setValue(p);
    }
    if(!(ui->sBox_addrE->isEnabled())){
        ui->dial_MotorElbow->setValue(p);
    }
    if(!(ui->sBox_addrC->isEnabled())){
        ui->dial_MotorClamp->setValue(p);
    }
}

void MainWindow::on_valuesread(float _t, int _p){
    double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds

    //Temperature Control
    if(_t > ui->dsBox_tempLimit->value()){
        ui->temp_graph->graph(0)->setPen(QPen(Qt::red)); // line color blue for first graph
        ui->temp_graph->graph(0)->setBrush(QBrush(QColor(255, 0, 0, 20)));
        //resetPositionISR();
       /* ui->dial_motorA->setValue(RESET_POS);
        ui->dial_motorA->setEnabled(FALSE);
        //Asking is Thread active to ended too
        if(ui->cBox_motorA->isChecked()){
            btnThread->setBtnFlag(FALSE);
        }
        ui->cBox_motorA->setChecked(FALSE);
        ui->cBox_motorA->setEnabled(FALSE);*/
    }
    else{
      /*  if(!ui->dial_motorA->isEnabled()){
            ui->dial_motorA->setEnabled(TRUE);
            ui->cBox_motorA->setEnabled(TRUE);
            ui->temp_graph->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
            ui->temp_graph->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));

        }*/
    }

    ui->temp_graph->graph(0)->addData(key, _t);
    ui->temp_graph->graph(0)->removeDataBefore(key - 15);

    ui->temp_graph->rescaleAxes();
    ui->temp_graph->xAxis->setRange(key, 15, Qt::AlignRight);
    ui->temp_graph->yAxis->setRangeLower(0);

    ui->temp_graph->replot();

    ui->lbl_actualPressure->setText("Pressure : "+QString::number(_p/100)+" hPa");
    ui->lbl_actualTemp->setText("Temperature : "+QString::number(_t)+" C");

}


void MainWindow::on_rBtn_MtrSA_clicked()
{
    if(ui->rBtn_MtrSA->isChecked()){
        btnThread->setBtnFlag(TRUE);
        btnThread->setPosAddress(ui->dial_MotorSA->value(),ui->sBox_addrSA->value());

        ui->sBox_addrSA->setEnabled(FALSE);
        ui->sBox_addrSB->setEnabled(TRUE);
        ui->sBox_addrE->setEnabled(TRUE);
        ui->sBox_addrC->setEnabled(TRUE);

        if(!btnThread->isRunning())
            btnThread->start();
    }
}

void MainWindow::on_rBtn_MtrSB_clicked()
{
    if(ui->rBtn_MtrSB->isChecked()){
        btnThread->setBtnFlag(TRUE);
        btnThread->setPosAddress(ui->dial_MotorSB->value(),ui->sBox_addrSB->value());

        ui->sBox_addrSA->setEnabled(TRUE);
        ui->sBox_addrSB->setEnabled(FALSE);
        ui->sBox_addrE->setEnabled(TRUE);
        ui->sBox_addrC->setEnabled(TRUE);

        if(!btnThread->isRunning())
            btnThread->start();
    }
}

void MainWindow::on_rBtn_MtrElbow_clicked()
{
    if(ui->rBtn_MtrElbow->isChecked()){
        btnThread->setBtnFlag(TRUE);
        btnThread->setPosAddress(ui->dial_MotorElbow->value(),ui->sBox_addrE->value());

        ui->sBox_addrSA->setEnabled(TRUE);
        ui->sBox_addrSB->setEnabled(TRUE);
        ui->sBox_addrE->setEnabled(FALSE);
        ui->sBox_addrC->setEnabled(TRUE);

        if(!btnThread->isRunning())
            btnThread->start();
    }
}

void MainWindow::on_rBtn_MtrClaw_clicked()
{
    if(ui->rBtn_MtrClaw->isChecked()){
        btnThread->setBtnFlag(TRUE);
        btnThread->setPosAddress(ui->dial_MotorClamp->value(),ui->sBox_addrC->value());

        ui->sBox_addrSA->setEnabled(TRUE);
        ui->sBox_addrSB->setEnabled(TRUE);
        ui->sBox_addrE->setEnabled(TRUE);
        ui->sBox_addrC->setEnabled(FALSE);

        if(!btnThread->isRunning())
            btnThread->start();
    }
}

void MainWindow::on_rBtn_MtrNone_clicked()
{
    if(ui->rBtn_MtrNone->isChecked()){
        btnThread->setBtnFlag(FALSE);

        ui->sBox_addrSA->setEnabled(TRUE);
        ui->sBox_addrSB->setEnabled(TRUE);
        ui->sBox_addrE->setEnabled(TRUE);
        ui->sBox_addrC->setEnabled(TRUE);
    }
}

void MainWindow::on_vSdr_speed_sliderMoved(int position)
{
    btnThread->setmspeed(position);
}
