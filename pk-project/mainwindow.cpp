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


    timer->start();
}

void MainWindow::advance() {
    //~~~~~~~~~~~~~~~~~~zamienić i na krok w pętlach, oraz czytać wartość kroku poprzez sygn.getKrok();~~~~~~~~~~~~~~~~~~~~~~~~

    // //Wejście i wyjście
    // double min=0.0, max=0.0, we, wy;
    // QLineSeries *serieIn = new QLineSeries();
    // QLineSeries *serieOut = new QLineSeries();

    // ui->chartView->chart()->removeAllSeries();
    // static QValueAxis *xAxis_ = new QValueAxis;
    // xAxis_->setRange(0,1);
    // //ui->chartView->chart()->addAxis(xAxis_, Qt::AlignBottom);
    // static QValueAxis *yAxis_ = new QValueAxis;
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
    // QLineSeries *serieE = new QLineSeries();
    // ui->chartViewE->chart()->removeAllSeries();
    // static QValueAxis *xAxisE = new QValueAxis;
    // xAxisE->setRange(0,1);
    // //ui->chartViewE->chart()->addAxis(xAxisE, Qt::AlignBottom);
    // static QValueAxis *yAxisE = new QValueAxis;
    // yAxisE->setRange(0.0, 2.0);
    // //ui->chartViewE->chart()->addAxis(yAxisE, Qt::AlignLeft);
    // ui->chartViewE->chart()->addSeries(serieE);
    // ui->chartViewE->chart()->setAxisX(xAxisE, serieE);
    // ui->chartViewE->chart()->setAxisY(yAxisE, serieE);
    // serieE->setName("Wartość uchybu");
    // //ui->chartViewE->chart()->legend()->hide();

    // //PID
    // QLineSeries *seriePid = new QLineSeries();
    // ui->chartViewPid->chart()->removeAllSeries();
    // static QValueAxis *xAxisPid = new QValueAxis;
    // xAxisPid->setRange(0,1);
    // //ui->chartViewPid->chart()->addAxis(xAxisPid, Qt::AlignBottom);
    // static QValueAxis *yAxisPid = new QValueAxis;
    // yAxisPid->setRange(0.0, 2.0);
    // //ui->chartViewPid->chart()->addAxis(yAxisPid, Qt::AlignLeft);
    // ui->chartViewPid->chart()->addSeries(seriePid);
    // ui->chartViewPid->chart()->setAxisX(xAxisPid, seriePid);
    // ui->chartViewPid->chart()->setAxisY(yAxisPid, seriePid);
    // seriePid->setName("Wartość regulatora PID");
    // //ui->chartViewPid->chart()->legend()->hide();

    // //P/I/D jako 3
    // QLineSeries *serieP = new QLineSeries();
    // QLineSeries *serieI = new QLineSeries();
    // QLineSeries *serieD = new QLineSeries();

    // ui->chartViewPID3->chart()->removeAllSeries();
    // static QValueAxis *xAxis__ = new QValueAxis;
    // xAxis__->setRange(0,1);
    // //ui->chartViewPID3->chart()->addAxis(xAxis__, Qt::AlignBottom);
    // static QValueAxis *yAxis__ = new QValueAxis;
    // yAxis__->setRange(0.0, 2.0);
    // //ui->chartViewPID3->chart()->addAxis(yAxis__, Qt::AlignLeft);
    // ui->chartViewPID3->chart()->addSeries(serieP);
    // ui->chartViewPID3->chart()->setAxisX(xAxis__, serieP);
    // ui->chartViewPID3->chart()->setAxisY(yAxis__, serieP);
    // seriePid->setName("Składowa P");
    // ui->chartViewPID3->chart()->addSeries(serieI);
    // ui->chartViewPID3->chart()->setAxisX(xAxis__, serieI);
    // ui->chartViewPID3->chart()->setAxisY(yAxis__, serieI);
    // seriePid->setName("Składowa I");
    // ui->chartViewPID3->chart()->addSeries(serieD);
    // ui->chartViewPID3->chart()->setAxisX(xAxis__, serieD);
    // ui->chartViewPID3->chart()->setAxisY(yAxis__, serieD);
    // seriePid->setName("Składowa D");
    // //ui->chartViewPID3->chart()->legend()->hide();


    if(ui->groupBoxSkok->isChecked()) {
        SygSkok sygn{ ui->doubleSpinBoxSkokAmp->value(), ui->spinBoxSkokAkt->value() };
        setUpUAR();
        for (int i = 0; i < 30; i++) {      // 30 kroków dla testu
            double we = sygn.getSygn(); double wy = UAR.symulujKrok(sygn); //sygn.getKrok();  <- do zamiany
            std::cerr << std::setprecision(3) << std::setw(4) << std::fixed << wy << '\n';
        }
    } else if(ui->groupBoxKwad->isChecked()) {
        SygKwad sygn{ ui->doubleSpinBoxKwadAmp->value(), ui->doubleSpinBoxKwadWyp->value(), ui->spinBoxKwadAkt->value() };
        setUpUAR();

        for (int i = 0; i < 30; i++) {      // 30 kroków dla testu
            double we = sygn.sygnal(); double wy = UAR.symulujKrok(sygn); //sygn.getKrok();  <- do zamiany
            //std::cerr << std::setprecision(3) << std::setw(4) << std::fixed << wy << '\n';

        }
    } else if(ui->groupBoxSin->isChecked()) {
        SygSin sygn{ ui->doubleSpinBoxSinAmp->value(), ui->spinBoxSinOkr->value() };
        setUpUAR();

        for (int i = 0; i < 30; i++) {      // 30 kroków dla testu
            double we = sygn.sygnal(); double wy = UAR.symulujKrok(sygn); //sygn.getKrok();  <- do zamiany
            //std::cerr << std::setprecision(3) << std::setw(4) << std::fixed << wy << '\n';

        }
    }

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

