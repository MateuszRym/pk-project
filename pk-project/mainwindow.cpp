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
    , krok{0}
    , arx_a_view{}
    , arx_b_view{}
    , uar_wy_x{}
    , uar_wy_y{}
{
    ui->setupUi(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(advance()));
    on_spinBoxInterwal_valueChanged(ui->spinBoxInterwal->value());
    ui->graphUAR->addGraph();
    ui->graphUAR->yAxis->setLabel("WY");
    ui->graphUAR->xAxis->setLabel("Krok");
    ui->graphUAR->yAxis->setRange(0.0, 1.0);
    ui->graphUAR->xAxis->setRange(0.0, 10.0);
    ui->graphUAR->graph(0)->setAntialiased(true);
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
    ui->graphUAR->xAxis->setRange(0.0, ui->spinBoxWidokKrokow->value());
    setUpUAR();

    timer->start();
}

void MainWindow::advance() {

    if (ui->groupBoxSkok->isChecked()) {
        UAR.liczSygnalSkok(ui->doubleSpinBoxSkokAmp->value(), ui->spinBoxSkokAkt->value());

    } else if (ui->groupBoxKwad->isChecked()) {
        UAR.liczSygnalKwad(ui->doubleSpinBoxKwadAmp->value(), ui->spinBoxKwadAkt->value(), ui->doubleSpinBoxKwadWyp->value());

    } else if (ui->groupBoxSin->isChecked()) {
        UAR.liczSygnalSin(ui->doubleSpinBoxSinAmp->value(), ui->spinBoxSinOkr->value());
    }

    double wy = UAR.symulujKrok();
    krok++;
    std::cerr << wy << '\n';
    uar_wy_y.push_back(wy);
    uar_wy_x.push_back(krok);

    ui->graphUAR->graph(0)->setData(uar_wy_x, uar_wy_y);
    // ui->graphUAR->rescaleAxes();
    if (krok > ui->spinBoxWidokKrokow->value())
        ui->graphUAR->xAxis->moveRange(1.0);
    ui->graphUAR->graph(0)->rescaleValueAxis(false, true);
    ui->graphUAR->replot();
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

void MainWindow::on_btnStop_clicked()
{
    timer->stop();
    ui->btnStop->setEnabled(false);
    ui->btnStart->setEnabled(true);
    ui->labelStatus->setText("Zatrzymana");
}

void MainWindow::on_spinBoxInterwal_valueChanged(int arg1)
{
    timer->setInterval(arg1);
}


void MainWindow::on_spinBoxWidokKrokow_valueChanged(int arg1)
{
    if (krok <= ui->spinBoxWidokKrokow->value()) {
        ui->graphUAR->xAxis->setRange(0.0, ui->spinBoxWidokKrokow->value());
    }
    else {
        ui->graphUAR->xAxis->setRange(krok - ui->spinBoxWidokKrokow->value(), krok);
    }
}

