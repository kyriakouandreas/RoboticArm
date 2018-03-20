#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Temp counter init
    high_state = 0;

    //Servos Init
    servoi2c = new ServoController(SERCONT_ADDRESS, MODE_EXTND);
    servoi2c->addMotor(ui->sBox_addrSA->value(), 90, 0, 180);
    servoi2c->addMotor(ui->sBox_addrSB->value(), 90, 0, 180);
    servoi2c->addMotor(ui->sBox_addrE->value(),90, 0, 180);
    servoi2c->addMotor(ui->sBox_addrC->value(),90,CLAMP_LOW_LIMIT,CLAMP_HIGH_LIMIT);

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

    //Initial Position Config (if possible let posibility from file)
    initPos[CLAMP] = CLAMP_POS;
    initPos[ELBOW] = ELBOW_POS;
    initPos[SHOULDER_A] = SHOULDER_A_POS;
    initPos[SHOULDER_B] = SHOULDER_B_POS;

    g_initPos[CLAMP] = CLAMP_POS;
    g_initPos[ELBOW] = ELBOW_POS;
    g_initPos[SHOULDER_A] = SHOULDER_A_POS;
    g_initPos[SHOULDER_B] = SHOULDER_B_POS;

    g_motorAddr[CLAMP] = ui->sBox_addrC->value();
    g_motorAddr[ELBOW] = ui->sBox_addrE->value();
    g_motorAddr[SHOULDER_A] = ui->sBox_addrSA->value();
    g_motorAddr[SHOULDER_B] = ui->sBox_addrSB->value();

    //Gpio inits
    if (wiringPiSetup() == -1){
           QMessageBox::information(this,"Error conf gpio","The gpio could not be configured");
           QApplication::quit();
    }
    pinMode(LED_RED, OUTPUT);
    digitalWrite(LED_RED, 0);

    wiringPiISR(RESET_BUTTON, INT_EDGE_RISING, &resetPositionISR);
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
    resetActions();
    setDials(false);
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
    if(ui->sBox_addrC->isEnabled()){
    main_mutex.lock();
    servoi2c->motorPos(ui->sBox_addrC->value(),value);
    main_mutex.unlock();
    }
}

void MainWindow::on_dial_MotorElbow_valueChanged(int value)
{
    if(ui->sBox_addrE->isEnabled()){
    main_mutex.lock();
    servoi2c->motorPos(ui->sBox_addrE->value(),value);
    main_mutex.unlock();
    }
}

void MainWindow::on_dial_MotorSB_valueChanged(int value)
{
    if(ui->sBox_addrSB->isEnabled()){
    main_mutex.lock();
    servoi2c->motorPos(ui->sBox_addrSB->value(),value);
    main_mutex.unlock();
    }
}

void MainWindow::on_dial_MotorSA_valueChanged(int value)
{
    if(ui->sBox_addrSA->isEnabled()){
    main_mutex.lock();
    servoi2c->motorPos(ui->sBox_addrSA->value(),value);
    main_mutex.unlock();
    }
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
        high_state++;
        if(high_state == ALARM_TEMP_COUNT){
            ui->temp_graph->graph(0)->setPen(QPen(Qt::red)); // line color blue for first graph
            ui->temp_graph->graph(0)->setBrush(QBrush(QColor(255, 0, 0, 20)));
            //resetPositionISR();
            resetActions();
            setDials(false);
            digitalWrite(LED_RED, 1);
        }
    }
    else{
        ui->temp_graph->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
        ui->temp_graph->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));

        high_state = 0; //reset real alarm counting

        if(!(ui->dial_MotorSA->isEnabled() && ui->dial_MotorSB->isEnabled())){
            setDials(true);
            digitalWrite(LED_RED, 0);
        }
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

void MainWindow::resetActions(){

    ui->dial_MotorClamp->setValue(initPos[CLAMP]);
    delay(5);//To not throw the sample
    ui->dial_MotorElbow->setValue(initPos[ELBOW]);
    ui->dial_MotorSB->setValue(initPos[SHOULDER_B]);
    ui->dial_MotorSA->setValue(initPos[SHOULDER_A]);

    //Asking is Thread active to ended too
    if(!ui->rBtn_MtrNone->isChecked()){
        btnThread->setBtnFlag(false);
        ui->rBtn_MtrNone->setChecked(true);
    }
}

void MainWindow::setDials(bool state){
    ui->dial_MotorClamp->setEnabled(state);
    ui->dial_MotorElbow->setEnabled(state);
    ui->dial_MotorSB->setEnabled(state);
    ui->dial_MotorSA->setEnabled(state);
}

void resetPositionISR(){
    ServoController resetServo(SERCONT_ADDRESS,MODE_EXTND);
    resetServo.addMotor(g_motorAddr[CLAMP], g_initPos[CLAMP], CLAMP_LOW_LIMIT, CLAMP_HIGH_LIMIT);
    resetServo.addMotor(g_motorAddr[ELBOW], g_initPos[ELBOW], 0, 180);
    resetServo.addMotor(g_motorAddr[SHOULDER_B], g_initPos[SHOULDER_B], 0, 180);
    resetServo.addMotor(g_motorAddr[SHOULDER_B], g_initPos[SHOULDER_A], 0, 180);


    //QApplication::quit();
}

void MainWindow::on_sBox_addrSA_valueChanged(int arg1)
{
    g_motorAddr[SHOULDER_A] = arg1;
}

void MainWindow::on_sBox_addrSB_valueChanged(int arg1)
{
    g_motorAddr[SHOULDER_B] = arg1;
}

void MainWindow::on_sBox_addrE_valueChanged(int arg1)
{
    g_motorAddr[ELBOW] = arg1;
}

void MainWindow::on_sBox_addrC_valueChanged(int arg1)
{
    g_motorAddr[CLAMP] = arg1;
}
