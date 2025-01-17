#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sygskok.h"
#include "sygsin.h"
#include "sygkwad.h"
#include <iomanip>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer{new QTimer(this)}
    , serieIn{new QLineSeries()}
    , serieOut{new QLineSeries()}
    , serieE{new QLineSeries()}
    , seriePid{new QLineSeries()}
    , serieP{new QLineSeries()}
    , serieI{new QLineSeries()}
    , serieD{new QLineSeries()}
    , xAxis_{new QValueAxis()}
    , yAxis_{new QValueAxis()}
    , yAxisE{new QValueAxis()}
    , yAxisPid{new QValueAxis()}
    , yAxis__{new QValueAxis()}
    , UAR{}
    , arx_a_view{}
    , arx_b_view{}
{
    ui->setupUi(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(advance()));
    on_spinBoxInterwal_valueChanged(ui->spinBoxInterwal->value());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUpUAR() {
    UAR.setPID_k(ui->doubleSpinBoxP->value());
    UAR.setPID_tI(ui->doubleSpinBoxI->value());
    UAR.setPID_tD(ui->doubleSpinBoxD->value());
    UAR.setARX_k(ui->spinBoxARX_k->value());
    UAR.setARX_z(ui->checkBoxARZ_z->isChecked());
}

void MainWindow::on_btnStart_clicked()
{
    ui->btnStop->setEnabled(true);
    ui->btnStart->setEnabled(false);
    ui->labelStatus->setText("Włączona");
    setUpUAR();

    // ui->chartView->chart()->removeAllSeries();
    // xAxis_->setRange(0,1);
    // //ui->chartView->chart()->addAxis(xAxis_, Qt::AlignBottom);
    // yAxis_->setRange(0.0, 2.0);
    // //ui->chartView->chart()->addAxis(yAxis_, Qt::AlignLeft);
    // ui->chartView->chart()->addSeries(serieIn);
    // ui->chartView->chart()->setAxisX(xAxis_, serieIn);
    // ui->chartView->chart()->setAxisY(yAxis_, serieIn);
    // serieIn->setName("Sygnał wejściowy");
    // ui->chartView->chart()->addSeries(serieOut);
    // ui->chartView->chart()->setAxisX(xAxis_, serieOut);
    // ui->chartView->chart()->setAxisY(yAxis_, serieOut);
    // serieOut->setName("Sygnał wyjściowy");
    // //ui->chartView->chart()->legend()->hide();

    // //Uchyb E
    // ui->chartViewE->chart()->removeAllSeries();
    // xAxis_->setRange(0,1);
    // //ui->chartViewE->chart()->addAxis(xAxisE, Qt::AlignBottom);
    // yAxisE->setRange(0.0, 2.0);
    // //ui->chartViewE->chart()->addAxis(yAxisE, Qt::AlignLeft);
    // ui->chartViewE->chart()->addSeries(serieE);
    // ui->chartViewE->chart()->setAxisX(xAxis_, serieE);
    // ui->chartViewE->chart()->setAxisY(yAxisE, serieE);
    // serieE->setName("Wartość uchybu");
    // //ui->chartViewE->chart()->legend()->hide();

    // //PID
    // ui->chartViewPid->chart()->removeAllSeries();
    // xAxis_->setRange(0,1);
    // //ui->chartViewPid->chart()->addAxis(xAxisPid, Qt::AlignBottom);
    // yAxisPid->setRange(0.0, 2.0);
    // //ui->chartViewPid->chart()->addAxis(yAxisPid, Qt::AlignLeft);
    // ui->chartViewPid->chart()->addSeries(seriePid);
    // ui->chartViewPid->chart()->setAxisX(xAxis_, seriePid);
    // ui->chartViewPid->chart()->setAxisY(yAxisPid, seriePid);
    // seriePid->setName("Wartość regulatora PID");
    // //ui->chartViewPid->chart()->legend()->hide();

    // //P/I/D jako 3

    // ui->chartViewPID3->chart()->removeAllSeries();
    // xAxis_->setRange(0,1);
    // //ui->chartViewPID3->chart()->addAxis(xAxis__, Qt::AlignBottom);
    // yAxis__->setRange(0.0, 2.0);
    // //ui->chartViewPID3->chart()->addAxis(yAxis__, Qt::AlignLeft);
    // ui->chartViewPID3->chart()->addSeries(serieP);
    // ui->chartViewPID3->chart()->setAxisX(xAxis_, serieP);
    // ui->chartViewPID3->chart()->setAxisY(yAxis__, serieP);
    // seriePid->setName("Składowa P");
    // ui->chartViewPID3->chart()->addSeries(serieI);
    // ui->chartViewPID3->chart()->setAxisX(xAxis_, serieI);
    // ui->chartViewPID3->chart()->setAxisY(yAxis__, serieI);
    // seriePid->setName("Składowa I");
    // ui->chartViewPID3->chart()->addSeries(serieD);
    // ui->chartViewPID3->chart()->setAxisX(xAxis_, serieD);
    // ui->chartViewPID3->chart()->setAxisY(yAxis__, serieD);
    // seriePid->setName("Składowa D");
    // //ui->chartViewPID3->chart()->legend()->hide();

    timer->start();
}

void MainWindow::advance() {

    if(ui->groupBoxSkok->isChecked()) {
        UAR.liczSygnalSkok(ui->doubleSpinBoxSkokAmp->value(), ui->spinBoxSkokAkt->value());
//      double we = sygn.getSygn(); double wy = UAR.symulujKrok(sygn); //sygn.getKrok();  <- do zamiany
        // std::cerr << std::setprecision(3) << std::setw(4) << std::fixed << UAR.symulujKrok() << '\n';
    } else if(ui->groupBoxKwad->isChecked()) {
        UAR.liczSygnalKwad(ui->doubleSpinBoxKwadAmp->value(), ui->spinBoxKwadAkt->value(), ui->doubleSpinBoxKwadWyp->value());
        //double we = sygn.sygnal(); double wy = UAR.symulujKrok(sygn); //sygn.getKrok();  <- do zamiany
        // std::cerr << std::setprecision(3) << std::setw(4) << std::fixed << UAR.symulujKrok() << '\n';

    } else if(ui->groupBoxSin->isChecked()) {
        UAR.liczSygnalSin(ui->doubleSpinBoxSinAmp->value(), ui->spinBoxSinOkr->value());
        // double we = sygn.sygnal(); double wy = UAR.symulujKrok(sygn); //sygn.getKrok();  <- do zamiany
        // std::cerr << std::setprecision(3) << std::setw(4) << std::fixed << UAR.symulujKrok() << '\n';
    }

    // UAR.symulujKrok();

    double we = UAR.getSygn();
    double wy = UAR.symulujKrok();
    std::cerr << std::setprecision(3) << std::setw(4) << std::fixed << wy << '\n';

    double min{0.0}, max{1.0};

    if(we<min){min = we;}
    if(we>max){max = we;}
    if(wy<min){min = wy;}
    if(wy>max){max = wy;}

    serieIn->append(ui->spinBoxWidokKrokow->value(), we);
    serieOut->append(ui->spinBoxWidokKrokow->value(), wy);
    xAxis_->setRange(0,ui->spinBoxWidokKrokow->value());
    yAxis_->setRange(min,1.05*max);

    //uchyb E
    double e = UAR.getUchyb(); double minE=0.0, maxE=0.0;

    if(e<minE){minE = e;}
    if(e>maxE){maxE = e;}

    serieE->append(ui->spinBoxWidokKrokow->value(), e);
    xAxis_->setRange(0,ui->spinBoxWidokKrokow->value());
    yAxisE->setRange(minE-0.1,0.1+maxE);

    //PID
    double pid = UAR.getPID_output(); double minPid=0.0, maxPid=0.0;

    if(pid<minPid){minPid = pid;}
    if(pid>maxPid){maxPid = pid;}

    //zamienić i na krok
    seriePid->append(ui->spinBoxWidokKrokow->value(), pid);
    xAxis_->setRange(0,ui->spinBoxWidokKrokow->value());
    yAxisPid->setRange(minPid-0.1,0.1+maxPid);

    //PID3
    double p = UAR.getPID_P(); double i_ = UAR.getPID_I(); double d = UAR.getPID_D(); double minPID3=0.0, maxPID3=0.0;

    if(p<minPID3){minPID3 = p;}
    if(p>maxPID3){maxPID3 = p;}
    if(i_<minPID3){minPID3 = i_;}
    if(i_>maxPID3){maxPID3 = i_;}
    if(d<minPID3){minPID3 = d;}
    if(d>maxPID3){maxPID3 = d;}

    serieP->append(ui->spinBoxWidokKrokow->value(), p);
    serieI->append(ui->spinBoxWidokKrokow->value(), i_);
    serieD->append(ui->spinBoxWidokKrokow->value(), d);
    xAxis_->setRange(0,ui->spinBoxWidokKrokow->value());
    yAxis__->setRange(minPID3-0.1,0.1+maxPID3);

}

void MainWindow::on_groupBoxKwad_toggled(bool arg1)
{
    if(arg1) {
        ui->groupBoxSin->setChecked(false);
        ui->groupBoxSkok->setChecked(false);
    }
}

void MainWindow::on_groupBoxSin_toggled(bool arg1)
{
    if(arg1) {
        ui->groupBoxKwad->setChecked(false);
        ui->groupBoxSkok->setChecked(false);
    }
}

void MainWindow::on_groupBoxSkok_toggled(bool arg1)
{
    if(arg1) {
        ui->groupBoxKwad->setChecked(false);
        ui->groupBoxSin->setChecked(false);
    }
}

void MainWindow::on_btnARXAdd_A_clicked()
{
    UAR.addARX_a(ui->doubleSpinBoxARX_A->value());
    arx_a_view.push_back(ui->doubleSpinBoxARX_A->value());
    ui->doubleSpinBoxARX_A->clear();

    ui->lineEditARXView_A->clear();
    ui->lineEditARXView_A->insert("{ ");
    for(const double &a : arx_a_view) {
        ui->lineEditARXView_A->insert(QString::number(a));
        ui->lineEditARXView_A->insert("; ");
    }
    ui->lineEditARXView_A->insert("}");
}

void MainWindow::on_btnARXAdd_B_clicked()
{
    UAR.addARX_b(ui->doubleSpinBoxARX_B->value());
    arx_b_view.push_back(ui->doubleSpinBoxARX_B->value());
    ui->doubleSpinBoxARX_B->clear();

    ui->lineEditARXView_B->clear();
    ui->lineEditARXView_B->insert("{ ");
    for(const double &b : arx_b_view) {
        ui->lineEditARXView_B->insert(QString::number(b));
        ui->lineEditARXView_B->insert("; ");
    }
    ui->lineEditARXView_B->insert("}");
}

void MainWindow::on_btnARXClear_A_clicked()
{
    UAR.clearARX_a();
    arx_a_view.clear();
    ui->lineEditARXView_A->clear();
}

void MainWindow::on_btnARXClear_B_clicked()
{
    UAR.clearARX_b();
    arx_b_view.clear();
    ui->lineEditARXView_B->clear();
}

void MainWindow::on_btnReset_clicked()
{
    UAR.setPID_k(0.0);
    UAR.setPID_tI(0.0);
    UAR.setPID_tD(0.0);
    UAR.resetPID_I();
    UAR.resetPID_D();
    UAR.setARX_k(1);
    UAR.setARX_z(true);

    ui->groupBoxSkok->setChecked(false);
    ui->groupBoxSin->setChecked(false);
    ui->groupBoxKwad->setChecked(false);
    ui->spinBoxSkokAkt->setValue(0);
    ui->doubleSpinBoxSkokAmp->setValue(0.0);
    ui->doubleSpinBoxSinAmp->setValue(0.0);
    ui->spinBoxSinOkr->setValue(0);
    ui->spinBoxKwadAkt->setValue(0);
    ui->doubleSpinBoxKwadAmp->setValue(0.0);
    ui->doubleSpinBoxKwadWyp->setValue(0.0);

    ui->doubleSpinBoxP->setValue(0.0);
    ui->doubleSpinBoxI->setValue(0.0);
    ui->doubleSpinBoxD->setValue(0.0);

    ui->doubleSpinBoxARX_A->setValue(0.0);
    ui->doubleSpinBoxARX_B->setValue(0.0);
    ui->spinBoxARX_k->setValue(1);
    ui->checkBoxARZ_z->setCheckState(Qt::Unchecked);
    ui->lineEditARXView_A->clear();
    ui->lineEditARXView_B->clear();

    ui->spinBoxInterwal->setValue(1000);
    ui->spinBoxWidokKrokow->setValue(10);
}

void MainWindow::on_btnResetD_clicked()
{
    UAR.resetPID_D();
}

void MainWindow::on_btnResetI_clicked()
{
    UAR.resetPID_I();
}

void MainWindow::WykresWeWy(double t, double we, double wy){
    /*

    static double min, max;
    //static QLineSeries serieIn = new QLineSeries();
    //static QLineSeries serieOut = new QLineSeries();

    if(min == NULL){
        min = we;
        max = we;
        if(we==wy)max+=1.0;
        else if(wy>we)max=wy;
        else if(wy<we)min=wy;


    }else{
        if(we<min)min = we;
        if(we>max)max = we;
        if(wy<min)min = wy;
        if(wy>max)max = wy;
    }

    ui->chartView->chart()->removeAllSeries();
    static QValueAxis *xAxis_ = new QValueAxis;
    xAxis_->setRange(0,1);
    ui->chartView->chart()->addAxis(xAxis_, Qt::AlignBottom);
    static QValueAxis *yAxis_ = new QValueAxis;
    yAxis_->setMax(2.00);
    yAxis_->setMin(0.0);
    ui->chartView->chart()->addAxis(yAxis_, Qt::AlignLeft);
    ui->chartView->chart()->addSeries(serieIn);
    ui->chartView->chart()->setAxisX(xAxis_, serieIn);
    ui->chartView->chart()->setAxisY(yAxis_, serieIn);
    // ui->chartView->chart()->addSeries(serieOut);
    // ui->chartView->chart()->setAxisX(xAxis_, serieOut);
    // ui->chartView->chart()->setAxisY(yAxis_, serieOut);
    ui->chartView->chart()->legend()->hide();

    serieIn->append(t, we);
    //serieOut->append(t, wy);
    xAxis_->setRange(0,t);
    */



    //double temp69;

    //std::cerr << std::setprecision(3) << std::setw(4) << std::fixed << temp69 << '\n';
    //series1->append(i,temp69);
    //m_xAxis->setRange(0,i);
}

void MainWindow::on_btnStop_clicked()
{
    timer->stop();
    ui->btnStop->setEnabled(false);
    ui->btnStart->setEnabled(true);
    ui->labelStatus->setText("Zatrzymana");
}

void MainWindow::WykresE(double t, double e){

}

void MainWindow::WykresSterPID(double t, double pid){

}

void MainWindow::WykresPID(double t, double p, double i, double d){

}

void MainWindow::on_spinBoxInterwal_valueChanged(int arg1)
{
    timer->setInterval(arg1);
}

