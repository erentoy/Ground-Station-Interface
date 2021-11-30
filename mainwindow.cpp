#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtGlobal>
#include <QRandomGenerator>
#include <qglobal.h>
#include <random>
#include "QDateTime"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <QFile>


#define MaxTime  10
#define MaxSize  25
int maxVal = MaxSize;
int minVal = 0;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitializeGraph();
    OpenCVS();


    QTimer * timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &MainWindow::addData);
    timer->start(1000);


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::InitializeGraph()
{
    series = new QLineSeries();
    series->append(0,0);

    chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Altitude");
    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).first()->setRange(0, MaxTime);
    chart->axes(Qt::Vertical).first()->setRange(0, MaxSize);
    chart->legend()->setVisible(true);
    chart->legend()->hide();
    chart->setAnimationOptions(QChart::SeriesAnimations);//AllAnimations SeriesAnimations
    chart->setTheme(QChart::ChartThemeBlueCerulean);

    QChartView *chartView = new QChartView(chart);

    chartView->setRenderHint(QPainter::Antialiasing);

    //chartView->setParent(ui->horizontalFrame);
    ui->horizontalLayout_2->addWidget(chartView);
    ui->maxVal->setText(QString::number(maxVal));
    ui->minVal->setText(QString::number(minVal));
}

void MainWindow::addData()
{
    srand(time(NULL));
    int rande = rand() % ((100 + 1) - 0 ) + 0;
    ui->lineEdit->setText(QString::number(rande));
    series->append(number, rande);
    if(series->count() >  MaxTime )
    {
        chart->scroll(chart->plotArea().width() / MaxTime, 0);
    }
    if(rande >= maxVal)
    {// büyüklüğe göre kaydırmalıyız
        chart->scroll(0, ((rande) - maxVal + 10) * chart->plotArea().height() / MaxSize);
        maxVal += (rande) - maxVal + 10;
        minVal = maxVal - 25;
        ui->maxVal->setText(QString::number(maxVal));
        ui->minVal->setText(QString::number(minVal));

        Sleep(2000);
    }
    if(rande <= minVal)
    {
        chart->scroll(0, -1 * (minVal - (rande) + 10 )  * chart->plotArea().height() / MaxSize);
        minVal -= (minVal - (rande) + 10);
        maxVal = minVal + 25;
        ui->maxVal->setText(QString::number(maxVal));
        ui->minVal->setText(QString::number(minVal));
        Sleep(2000);
    }
        number++;


}

void MainWindow::OpenCvs()
{
    QFile cvsFile;
}



