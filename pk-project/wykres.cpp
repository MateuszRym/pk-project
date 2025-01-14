/*

//Wejście i wyjście
double min=0.0, max=0.0, we, wy;
QLineSeries *serieIn = new QLineSeries();
QLineSeries *serieOut = new QLineSeries();

ui->chartView->chart()->removeAllSeries();
static QValueAxis *xAxis_ = new QValueAxis;
xAxis_->setRange(0,1);
//ui->chartView->chart()->addAxis(xAxis_, Qt::AlignBottom);
static QValueAxis *yAxis_ = new QValueAxis;
yAxis_->setRange(0.0, 2.0);
//ui->chartView->chart()->addAxis(yAxis_, Qt::AlignLeft);
ui->chartView->chart()->addSeries(serieIn);
ui->chartView->chart()->setAxisX(xAxis_, serieIn);
ui->chartView->chart()->setAxisY(yAxis_, serieIn);
serieIn->setName("Sygnał wejściowy");
ui->chartView->chart()->addSeries(serieOut);
ui->chartView->chart()->setAxisX(xAxis_, serieOut);
ui->chartView->chart()->setAxisY(yAxis_, serieOut);
serieOut->setName("Sygnał wyjściowy");
//ui->chartView->chart()->legend()->hide();

//Uchyb E
QLineSeries *serieE = new QLineSeries();
ui->chartViewE->chart()->removeAllSeries();
static QValueAxis *xAxisE = new QValueAxis;
xAxisE->setRange(0,1);
//ui->chartViewE->chart()->addAxis(xAxisE, Qt::AlignBottom);
static QValueAxis *yAxisE = new QValueAxis;
yAxisE->setRange(0.0, 2.0);
//ui->chartViewE->chart()->addAxis(yAxisE, Qt::AlignLeft);
ui->chartViewE->chart()->addSeries(serieE);
ui->chartViewE->chart()->setAxisX(xAxisE, serieE);
ui->chartViewE->chart()->setAxisY(yAxisE, serieE);
serieE->setName("Wartość uchybu");
//ui->chartViewE->chart()->legend()->hide();

//PID
QLineSeries *seriePid = new QLineSeries();
ui->chartViewPid->chart()->removeAllSeries();
static QValueAxis *xAxisPid = new QValueAxis;
xAxisPid->setRange(0,1);
//ui->chartViewPid->chart()->addAxis(xAxisPid, Qt::AlignBottom);
static QValueAxis *yAxisPid = new QValueAxis;
yAxisPid->setRange(0.0, 2.0);
//ui->chartViewPid->chart()->addAxis(yAxisPid, Qt::AlignLeft);
ui->chartViewPid->chart()->addSeries(seriePid);
ui->chartViewPid->chart()->setAxisX(xAxisPid, seriePid);
ui->chartViewPid->chart()->setAxisY(yAxisPid, seriePid);
seriePid->setName("Wartość regulatora PID");
//ui->chartViewPid->chart()->legend()->hide();

//P/I/D jako 3
QLineSeries *serieP = new QLineSeries();
QLineSeries *serieI = new QLineSeries();
QLineSeries *serieD = new QLineSeries();

ui->chartViewPID3->chart()->removeAllSeries();
static QValueAxis *xAxis__ = new QValueAxis;
xAxis__->setRange(0,1);
//ui->chartViewPID3->chart()->addAxis(xAxis__, Qt::AlignBottom);
static QValueAxis *yAxis__ = new QValueAxis;
yAxis__->setRange(0.0, 2.0);
//ui->chartViewPID3->chart()->addAxis(yAxis__, Qt::AlignLeft);
ui->chartViewPID3->chart()->addSeries(serieP);
ui->chartViewPID3->chart()->setAxisX(xAxis__, serieP);
ui->chartViewPID3->chart()->setAxisY(yAxis__, serieP);
seriePid->setName("Składowa P");
ui->chartViewPID3->chart()->addSeries(serieI);
ui->chartViewPID3->chart()->setAxisX(xAxis__, serieI);
ui->chartViewPID3->chart()->setAxisY(yAxis__, serieI);
seriePid->setName("Składowa I");
ui->chartViewPID3->chart()->addSeries(serieD);
ui->chartViewPID3->chart()->setAxisX(xAxis__, serieD);
ui->chartViewPID3->chart()->setAxisY(yAxis__, serieD);
seriePid->setName("Składowa D");
//ui->chartViewPID3->chart()->legend()->hide();
*/




/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

/*
if(we<min){min = we;}
if(we>max){max = we;}
if(wy<min){min = wy;}
if(wy>max){max = wy;}

serieIn->append(i, we);
serieOut->append(i, wy);
xAxis_->setRange(0,i);
yAxis_->setRange(min,1.05*max);



//uchyb E
double e = UAR.getUchyb(); double minE=0.0, maxE=0.0;

if(e<minE){minE = e;}
if(e>maxE){maxE = e;}

serieE->append(i, e);
xAxisE->setRange(0,i);
yAxisE->setRange(minE-0.1,0.1+maxE);

//PID
double pid = UAR.getPID_output(); double minPid=0.0, maxPid=0.0;

if(pid<minPid){minPid = pid;}
if(pid>maxPid){maxPid = pid;}

//zamienić i na krok
seriePid->append(i, pid);
xAxisPid->setRange(0,i);
yAxisPid->setRange(minPid-0.1,0.1+maxPid);

//PID3
double p = UAR.getPID_P(); double i_ = UAR.getPID_I(); double d = UAR.getPID_D(); double minPID3=0.0, maxPID3=0.0;

if(p<minPID3){minPID3 = p;}
if(p>maxPID3){maxPID3 = p;}
if(i_<minPID3){minPID3 = i_;}
if(i_>maxPID3){maxPID3 = i_;}
if(d<minPID3){minPID3 = d;}
if(d>maxPID3){maxPID3 = d;}

serieP->append(i, p);
serieI->append(i, i_);
serieD->append(i, d);
xAxis__->setRange(0,i);
yAxis__->setRange(minPID3-0.1,0.1+maxPID3);

*/
