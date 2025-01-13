#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "symulacja.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setUpUAR();

private slots:
    void on_btnStart_clicked();
    void on_groupBoxKwad_toggled(bool arg1);
    void on_groupBoxSin_toggled(bool arg1);
    void on_groupBoxSkok_toggled(bool arg1);
    void on_btnARXAdd_A_clicked();
    void on_btnARXAdd_B_clicked();
    void on_btnARXClear_A_clicked();
    void on_btnARXClear_B_clicked();
    void on_btnReset_clicked();
    void on_btnResetD_clicked();
    void on_btnResetI_clicked();

private:
    Ui::MainWindow *ui;
    Symulacja UAR;
    std::vector<double> arx_a_view;
    std::vector<double> arx_b_view;
};
#endif // MAINWINDOW_H
