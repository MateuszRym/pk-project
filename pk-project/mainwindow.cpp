#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , UAR{}
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnStart_clicked()
{
    if(ui->groupBoxSkok->isChecked()) {
        // symulacja z sygnalem skok
    } else if(ui->groupBoxKwad->isChecked()) {
        // symulacja z sygnalem prostokatnym
    } else if(ui->groupBoxSin->isChecked()) {
        // symulacja z sygnalem sinus
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
