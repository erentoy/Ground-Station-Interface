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
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>


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
    InitializeTelemetryTable();
    OpenCVS();

    // update graph and table
    QTimer * timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &MainWindow::AddData);
    connect(timer, &QTimer::timeout, this, &MainWindow::AddToTable);
    timer->start(1000);

    // serial port
    qDebug() << "Number of ports: " << QSerialPortInfo::availablePorts().length() << "\n";
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
        qDebug() << "Description: " << serialPortInfo.description() << "\n";
        qDebug() << "Has vendor id?: " << serialPortInfo.hasVendorIdentifier() << "\n";
        qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier() << "\n";
        qDebug() << "Has product id?: " << serialPortInfo.hasProductIdentifier() << "\n";
        qDebug() << "Product ID: " << serialPortInfo.productIdentifier() << "\n";
    }

    bool arduino_is_available = false;
    QString arduino_uno_port_name;

    //  For each available serial port
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        //  check if the serialport has both a product identifier and a vendor identifier
        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier())
        {
            //  check if the product ID and the vendor ID match those of the arduino uno
            if((serialPortInfo.productIdentifier() == arduino_uno_product_id)
                    && (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id))
            {
                arduino_is_available = true;
                arduino_uno_port_name = serialPortInfo.portName();
            }
        }
    }

    arduino = new QSerialPort(this);
    if(arduino_is_available)
    {
        if(!arduino->setBaudRate(QSerialPort::Baud9600))
            qDebug() << "error:" << arduino->errorString();
        if(!arduino->setDataBits(QSerialPort::Data8))
            qDebug() << "error:" << arduino->errorString();
        if(!arduino->setParity(QSerialPort::EvenParity))
            qDebug() << "error:" << arduino->errorString();
        if(!arduino->setFlowControl(QSerialPort::NoFlowControl))
            qDebug() << "error:" << arduino->errorString();
        if(!arduino->setStopBits(QSerialPort::OneStop))
            qDebug() << "error:" << arduino->errorString();
        connect(arduino, &QSerialPort::readyRead, this, &MainWindow::ReadPort);
        if(!arduino->open(QIODevice::ReadWrite))
            qDebug() << "error:" << arduino->errorString();
    }
    else
    {
        qDebug() << "Couldn't find the correct port for the arduino.\n";
        //QMessageBox::information(this, "Serial Port Error", "Couldn't open serial port to arduino.");
    }

}

MainWindow::~MainWindow()
{
    arduino->close();
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

void MainWindow::AddData()
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

        //Sleep(2000);
    }
    if(rande <= minVal)
    {
        chart->scroll(0, -1 * (minVal - (rande) + 10 )  * chart->plotArea().height() / MaxSize);
        minVal -= (minVal - (rande) + 10);
        maxVal = minVal + 25;
        ui->maxVal->setText(QString::number(maxVal));
        ui->minVal->setText(QString::number(minVal));
       // Sleep(2000);
    }
    number++;


}

void MainWindow::InitializeTelemetryTable()
{
    telemetryModel = new QStandardItemModel(); //2 Rows and 3 Columns

    telemetryModel->setHorizontalHeaderItem(0, new QStandardItem(QString("Year")));
    telemetryModel->setHorizontalHeaderItem(1, new QStandardItem(QString("Score")));
    telemetryModel->setHorizontalHeaderItem(2, new QStandardItem(QString("Title")));


    ui->telemetryTable->setModel(telemetryModel);
    ui->telemetryTable->setColumnWidth(2, 225);

}

void MainWindow::OpenCVS()
{
    cvsFile.setFileName("D:/deniro.csv");
    if(false == cvsFile.open((QIODevice::ReadOnly)))
    {
        qDebug() << cvsFile.errorString();
        return;
    }
    qDebug() << "File is opened!!";
    cvsFile.readLine();
    return;

}

void MainWindow::AddToTable()
{
    if(cvsFile.isOpen())
    {

        QString line = QString::fromLocal8Bit(cvsFile.readLine());
        if(line == "\n")
            return;
        QStringList lineSplitted = line.remove("\"").remove("\n").split(",");
        // qDebug() << "line is" << line << lineSplitted;
        telemetryModel->setItem(rowNumber, 0, new QStandardItem(lineSplitted.at(0)));
        telemetryModel->setItem(rowNumber, 1, new QStandardItem(lineSplitted.at(1)));
        telemetryModel->setItem(rowNumber, 2, new QStandardItem(lineSplitted.at(2)));
        rowNumber++;
        ui->telemetryTable->scrollToBottom();

    }
    else
    {
        qDebug() << "not added to table!!";
    }
}

void MainWindow::ReadPort()
{
    QString buffer;
    buffer.append(arduino->readAll());
    if (buffer.size() > 62)
    {
        qDebug() << buffer.toUtf8();
        buffer.remove(0,62);
    }
}
