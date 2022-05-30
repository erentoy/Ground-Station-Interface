#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtGlobal>
#include <QtCharts>
#include <QRandomGenerator>
#include <random>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <QFile>
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QPixmap>
#include <QPalette>
#include <QAbstractItemView>
#include <QBoxLayout>

#ifdef _WIN32
#include <windows.h>
#endif

#define MaxTime  10
#define MaxSize  25
int maxVal = MaxSize;
int minVal = 0;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    ui->turksatLogo->setPixmap(QPixmap("D:/Projects/Interface/resources/tLogo.png").scaled(ui->turksatLogo->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->opsatLogo->setPixmap(QPixmap("D:/Projects/Interface/resources/dik.png").scaled(ui->opsatLogo->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->simulation->setPixmap(QPixmap("D:/Projects/Interface/resources/genel2.jpeg").scaled(ui->simulation->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));

    CreateVideoPlayer();
    InitializeTelemetryTable();
    CreateStateTable();
    InitializeAltitudeGraph();
    OpenCVS();

    // update graph and table
    QTimer * timer = new QTimer;
    //connect(timer, &QTimer::timeout, this, &MainWindow::AddData);
    //connect(timer, &QTimer::timeout, this, &MainWindow::AddToTable);
    timer->start(1000);



}

MainWindow::~MainWindow()
{
    arduino->close();
    delete ui;
}
void MainWindow::InitializeAltitudeGraph()
{
    altitudeSeries = new QLineSeries();

    altitudeChart = new QChart();
    altitudeChart->addSeries(altitudeSeries);
    altitudeChart->setTitle("GPS Altitude (deg)");
    altitudeChart->createDefaultAxes();
    altitudeChart->axes(Qt::Horizontal).first()->setRange(0, MaxTime);
    altitudeChart->axes(Qt::Vertical).first()->setRange(840, 900);
    altitudeChart->legend()->setVisible(true);
    altitudeChart->legend()->hide();
    altitudeChart->setAnimationOptions(QChart::SeriesAnimations);//AllAnimations SeriesAnimations
    altitudeChart->setTheme(QChart::ChartThemeBlueCerulean);

    //! 2 yol var (grafikler için)
    //! 1. arayzüde qchartview oluştur hepsi için sonra içine ataaa
    //! 2. tab alanı oluştur widgetin layoutuna ekleme yap diğer graflari

    // 1. yontem
    // ui->graphicsView->setChart(altitudeChart);

    // 2. yontem
    QChartView *chartView = new QChartView(altitudeChart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QGridLayout* graphsLayout = new QGridLayout();
    graphsLayout->addWidget(chartView, 1, 0); // insertwidget
    qDebug() <<ui->graphicsTabWidget->widget(0)->objectName();
    ui->graphicsTabWidget->widget(1)->setLayout(graphsLayout);
    //ui->graphicsTabWidget->widget(0)->layout()->addWidget(chartView);

    // lets add other graphs
    //2
    QLineSeries *laltitudeSeries = new QLineSeries();
    QChart *laltitudeChart = new QChart();
    laltitudeChart->addSeries(laltitudeSeries);
    laltitudeChart->setTitle("GPS Latitude (m)");
    laltitudeChart->createDefaultAxes();
    laltitudeChart->axes(Qt::Horizontal).first()->setRange(0, MaxTime);
    laltitudeChart->axes(Qt::Vertical).first()->setRange(200, 320);
    laltitudeChart->legend()->setVisible(true);
    laltitudeChart->legend()->hide();
    laltitudeChart->setAnimationOptions(QChart::SeriesAnimations);//AllAnimations SeriesAnimations
    laltitudeChart->setTheme(QChart::ChartThemeBlueCerulean);

    QChartView *chartView2 = new QChartView(laltitudeChart);
    chartView2->setRenderHint(QPainter::Antialiasing);
    graphsLayout->addWidget(chartView2, 1, 1);

    //3
    QLineSeries *longitudeSeries = new QLineSeries();
    QChart *longitudeChart = new QChart();
    longitudeChart->addSeries(longitudeSeries);
    longitudeChart->setTitle("GPS Longitude (deg)");
    longitudeChart->createDefaultAxes();
    longitudeChart->axes(Qt::Horizontal).first()->setRange(0, MaxTime);
    longitudeChart->axes(Qt::Vertical).first()->setRange(50, 55);
    longitudeChart->legend()->setVisible(true);
    longitudeChart->legend()->hide();
    longitudeChart->setAnimationOptions(QChart::SeriesAnimations);//AllAnimations SeriesAnimations
    longitudeChart->setTheme(QChart::ChartThemeBlueCerulean);

    QChartView *chartView6 = new QChartView(longitudeChart);
    chartView6->setRenderHint(QPainter::Antialiasing);
    graphsLayout->addWidget(chartView6, 1,2);


    // 4
    QLineSeries *pressureSeries = new QLineSeries();
    QChart *pressureChart = new QChart();
    pressureChart->addSeries(pressureSeries);
    pressureChart->setTitle("Pressure (Pa)");
    pressureChart->createDefaultAxes();
    pressureChart->axes(Qt::Horizontal).first()->setRange(0, MaxTime);
    pressureChart->axes(Qt::Vertical).first()->setRange(6, 10);
    pressureChart->legend()->setVisible(true);
    pressureChart->legend()->hide();
    pressureChart->setAnimationOptions(QChart::SeriesAnimations);//AllAnimations SeriesAnimations
    pressureChart->setTheme(QChart::ChartThemeBlueCerulean);

    QChartView *chartView3 = new QChartView(pressureChart);
    chartView3->setRenderHint(QPainter::Antialiasing);
    graphsLayout->addWidget(chartView3, 2, 0);

    // 5
    QLineSeries *temperatureSeries = new QLineSeries();
    QChart *temperatureChart = new QChart();
    temperatureChart->addSeries(temperatureSeries);
    temperatureChart->setTitle("Temperature (°C) ");
    temperatureChart->createDefaultAxes();
    temperatureChart->axes(Qt::Horizontal).first()->setRange(0, MaxTime);
    temperatureChart->axes(Qt::Vertical).first()->setRange(15, 25);
    temperatureChart->legend()->setVisible(true);
    temperatureChart->legend()->hide();
    temperatureChart->setAnimationOptions(QChart::SeriesAnimations);//AllAnimations SeriesAnimations
    temperatureChart->setTheme(QChart::ChartThemeBlueCerulean);

//    QChartView *chartView4 = new QChartView(pressureChart);
//    chartView4->setRenderHint(QPainter::Antialiasing);
//    ui->graphicsTabWidget->widget(0)->layout()->addWidget(chartView4);
     ui->temperatureGraph->setChart(temperatureChart);

    // 6
    QLineSeries *voltageSeries = new QLineSeries();
    QChart *voltageChart = new QChart();
    voltageChart->addSeries(voltageSeries);
    voltageChart->setTitle("Voltage (V)");
    voltageChart->createDefaultAxes();
    voltageChart->axes(Qt::Horizontal).first()->setRange(0, MaxTime);
    voltageChart->axes(Qt::Vertical).first()->setRange(6, 11);
    voltageChart->legend()->setVisible(true);
    voltageChart->legend()->hide();
    voltageChart->setAnimationOptions(QChart::SeriesAnimations);//AllAnimations SeriesAnimations
    voltageChart->setTheme(QChart::ChartThemeBlueCerulean);

//    QChartView *chartView5 = new QChartView(pressureChart);
//    chartView5->setRenderHint(QPainter::Antialiasing);
//    ui->graphicsTabWidget->widget(0)->layout()->addWidget(chartView5);

    ui->voltageGraph->setChart(voltageChart);

    // 7
    QLineSeries *altDifSeries = new QLineSeries();
    QChart *altDifChart = new QChart();
    altDifChart->addSeries(altDifSeries);
    altDifChart->setTitle("Altitude Difference (m)");
    altDifChart->createDefaultAxes();
    altDifChart->axes(Qt::Horizontal).first()->setRange(0, MaxTime);
    altDifChart->axes(Qt::Vertical).first()->setRange(0, 35);
    altDifChart->legend()->setVisible(true);
    altDifChart->legend()->hide();
    altDifChart->setAnimationOptions(QChart::SeriesAnimations);//AllAnimations SeriesAnimations
    altDifChart->setTheme(QChart::ChartThemeBlueCerulean);

//    QChartView *chartView7 = new QChartView(pressureChart);
//    chartView7->setRenderHint(QPainter::Antialiasing);
//    ui->graphicsTabWidget->widget(0)->layout()->addWidget(chartView7);

    ui->distanceGraph->setChart(altDifChart);

    // 8
    QLineSeries *speedSeries = new QLineSeries();
    QChart *speedChart = new QChart();
    speedChart->addSeries(speedSeries);
    speedChart->setTitle("Speed (m/s)");
    speedChart->createDefaultAxes();
    speedChart->axes(Qt::Horizontal).first()->setRange(0, MaxTime);
    speedChart->axes(Qt::Vertical).first()->setRange(5, 15);
    speedChart->legend()->setVisible(true);
    speedChart->legend()->hide();
    speedChart->setAnimationOptions(QChart::SeriesAnimations);//AllAnimations SeriesAnimations
    speedChart->setTheme(QChart::ChartThemeBlueCerulean);

//    QChartView *chartView8 = new QChartView(speedChart);
//    chartView8->setRenderHint(QPainter::Antialiasing);
//    ui->graphicsTabWidget->widget(0)->layout()->addWidget(chartView8);

    ui->speedGraph->setChart(speedChart);

    //9
    QLineSeries *RaltitudeSeries = new QLineSeries();
    QChart *RaltitudeChart = new QChart();
    RaltitudeChart->addSeries(RaltitudeSeries);
    RaltitudeChart->setTitle("Altitude (m)");
    RaltitudeChart->createDefaultAxes();
    RaltitudeChart->axes(Qt::Horizontal).first()->setRange(0, MaxTime);
    RaltitudeChart->axes(Qt::Vertical).first()->setRange(500, 700);
    RaltitudeChart->legend()->setVisible(true);
    RaltitudeChart->legend()->hide();
    RaltitudeChart->setAnimationOptions(QChart::SeriesAnimations);//AllAnimations SeriesAnimations
    RaltitudeChart->setTheme(QChart::ChartThemeBlueCerulean);

    QChartView *chartView9 = new QChartView(RaltitudeChart);
    chartView9->setRenderHint(QPainter::Antialiasing);
    graphsLayout->addWidget(chartView9, 2, 1);


  //  graphsLayout->addWidget(new QSpacerItem(10, 5), 2, 3);

    QFile telemtryFile;
    telemtryFile.setFileName("D:/Projects/Interface/resources/tele.txt");
    if(false == telemtryFile.open((QIODevice::ReadOnly)))
    {
        qDebug()  << "rere "<< telemtryFile.errorString();
        return;
    }

    qDebug() << "telemetry file is opened!!";
    int index = 0;
    while(telemtryFile.atEnd() == false)
    {
        QString currLine = telemtryFile.readLine();
        QStringList splitted = currLine.split(",");

        QList<QStandardItem*> modelList;
        for(int i = 0; i < splitted.size(); i++)
        {
            modelList << new QStandardItem(QString(splitted.at(i)).remove("\r\n"));
            switch(i)
            {
            case 3:
                pressureSeries->append(index, splitted.at(i).toDouble());
                break;
            case 5:
                RaltitudeSeries->append(index, splitted.at(i).toDouble());
                break;
            case 7:
                altDifSeries->append(index, splitted.at(i).toDouble());
                break;
            case 8:
                speedSeries->append(index, splitted.at(i).toDouble());
                break;
            case 9:
                temperatureSeries->append(index, splitted.at(i).toDouble());
                break;
            case 10:
                voltageSeries->append(index, splitted.at(i).toDouble());
                break;
            case 11:
                laltitudeSeries->append(index, splitted.at(i).toDouble());
                break;
            case 12:
                longitudeSeries->append(index, splitted.at(i).toDouble());
                break;
            case 13:
                altitudeSeries->append(index, splitted.at(i).toDouble());
                break;

            }
        }
        telemetryModel->insertRow(index++, modelList);

    }
}

void MainWindow::AddData()
{
    srand(time(NULL));
    int rande = rand() % ((100 + 1) - 0 ) + 0;
    altitudeSeries->append(number, rande);
    if(altitudeSeries->count() >  MaxTime )
    {
        altitudeChart->scroll(altitudeChart->plotArea().width() / MaxTime, 0);
    }
    if(rande >= maxVal)
    {// büyüklüğe göre kaydırmalıyız
        altitudeChart->scroll(0, ((rande) - maxVal + 10) * altitudeChart->plotArea().height() / MaxSize);
        maxVal += (rande) - maxVal + 10;
        minVal = maxVal - 25;


        //Sleep(2000);
    }
    if(rande <= minVal)
    {
        altitudeChart->scroll(0, -1 * (minVal - (rande) + 10 )  * altitudeChart->plotArea().height() / MaxSize);
        minVal -= (minVal - (rande) + 10);
        maxVal = minVal + 25;
       // Sleep(2000);
    }
    number++;


}

void MainWindow::InitializeTelemetryTable()
{
    telemetryModel = new QStandardItemModel(); //2 Rows and 3 Columns

    telemetryModel->setHorizontalHeaderItem(0, new QStandardItem(QString("Takım\n No")));
    telemetryModel->setHorizontalHeaderItem(1, new QStandardItem(QString("Paket\n No")));
    telemetryModel->setHorizontalHeaderItem(2, new QStandardItem(QString("Gönderim\n Saati")));

    telemetryModel->setHorizontalHeaderItem(3, new QStandardItem(QString("Görev Yükü\n Basınç")));
    telemetryModel->setHorizontalHeaderItem(4, new QStandardItem(QString("Taşıyıcı\n Basınç")));
    telemetryModel->setHorizontalHeaderItem(5, new QStandardItem(QString("Görev Yükü\n Yükseklik")));
    telemetryModel->setHorizontalHeaderItem(6, new QStandardItem(QString("Taşıyıcı\n Yükseklik")));
    telemetryModel->setHorizontalHeaderItem(7, new QStandardItem(QString("İrtifa\n Farkı")));
    telemetryModel->setHorizontalHeaderItem(8, new QStandardItem(QString("İniş\n Hızı")));
    telemetryModel->setHorizontalHeaderItem(9, new QStandardItem(QString("Sıcaklık")));
    telemetryModel->setHorizontalHeaderItem(10, new QStandardItem(QString("Pil\n Gerilimi")));

    telemetryModel->setHorizontalHeaderItem(11, new QStandardItem(QString("Görev Yükü\n Latitude")));
    telemetryModel->setHorizontalHeaderItem(12, new QStandardItem(QString("Görev Yükü\n Longitude")));
    telemetryModel->setHorizontalHeaderItem(13, new QStandardItem(QString("Görev Yükü\n Altitude")));
    telemetryModel->setHorizontalHeaderItem(14, new QStandardItem(QString("Taşıyıcı\n Latitude")));
    telemetryModel->setHorizontalHeaderItem(15, new QStandardItem(QString("Taşıyıcı\n Longitude")));
    telemetryModel->setHorizontalHeaderItem(16, new QStandardItem(QString("Taşıyıcı\n Altitude")));

    telemetryModel->setHorizontalHeaderItem(17, new QStandardItem(QString("Uydu  \nDurumu")));
    telemetryModel->setHorizontalHeaderItem(18, new QStandardItem(QString("Pitch")));
    telemetryModel->setHorizontalHeaderItem(19, new QStandardItem(QString("Roll")));
    telemetryModel->setHorizontalHeaderItem(20, new QStandardItem(QString("Yaw")));

    telemetryModel->setHorizontalHeaderItem(21, new QStandardItem(QString("Dönüş \n Sayısı")));
    telemetryModel->setHorizontalHeaderItem(22, new QStandardItem(QString("Video Aktarım\nBilgisi")));


    ui->telemetryTable->setModel(telemetryModel);
    for(int  i = 0; i < telemetryModel->columnCount(); i++)
    {
      int length = telemetryModel->horizontalHeaderItem(i)->text().split("\n").first().size();
      ui->telemetryTable->setColumnWidth(i, length * 11);
    }


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

void MainWindow::CreateStateTable()
{
    QStandardItemModel* stateModel = new QStandardItemModel();
    stateModel->appendRow(new QStandardItem("Pre-Launch"));
    stateModel->appendRow(new QStandardItem("Launch"));
    stateModel->appendRow(new QStandardItem("Satellite Released"));
    stateModel->appendRow(new QStandardItem("Payload Released"));
    stateModel->appendRow(new QStandardItem("Landed"));

    this->ui->stateList->setModel(stateModel);
    this->ui->stateList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    setStyleSheet("QListView { background-color: orange }");

    this->ui->stateList->setCurrentIndex(stateModel->indexFromItem(stateModel->item(1)));

    // color for already done
    QModelIndex vIndex = stateModel->index(0, 0);
    QMap<int, QVariant> vMap = stateModel->itemData(vIndex);
    vMap.insert(Qt::ForegroundRole, QVariant(QBrush(Qt::darkGray)));
    stateModel->setItemData(vIndex, vMap);

    // color for up-coming states
    QModelIndex vIndex1 = stateModel->index(1, 0);
    QMap<int, QVariant> vMap1 = stateModel->itemData(vIndex1);
    vMap1.insert(Qt::ForegroundRole, QVariant(QBrush(Qt::black)));
    stateModel->setItemData(vIndex1, vMap1);
}

void MainWindow::ConnectSerialPort()
{
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

void MainWindow::CreateVideoPlayer()
{

    // player window

    // open Gom player with process
//    QProcess *process = new QProcess();
//    process->start("D:/GOMPlayer/GOM.exe");

//       if(process->waitForStarted() == false)
//       {
//           qDebug() << "ERROR: " << process->errorString();
//      }
//       else
//       {
//           qDebug() << "opened process";
//       }

    // open Gom player with url
   // QString link = "D:/QtProjects/Projects/try/GOMPlayer";
    QString link = "D:/Projects/Interface/vlc";
    QDesktopServices::openUrl(QUrl(link));

#ifdef _WIN32
       Sleep(2000);
       qDebug() << "Windows OS is being used ";
       WId id = (WId) FindWindow(NULL, L"VLC Ortam Oynatıcısı");

    /*
     * Examples !!
     * WId id = (WId) FindWindow(NULL, L"Hızlı Erişim - Opera");
     * WId id = (WId) FindWindow(NULL, L"genel - Discord");
     * WId id = (WId) FindWindow(NULL, L"WhatsApp");
     *
     *
     */

       qDebug() << id << " is window id";
       QWindow* window =  QWindow::fromWinId(id);
       window->setFlags(Qt::FramelessWindowHint);
       window->create();
       window->setVisible(true);
       window->requestActivate();
       QWidget* playerWidget = QWidget::createWindowContainer(window, this);

       // add as a widget
       QLayout* layout = new QVBoxLayout();
       layout->addWidget(playerWidget);
       this->ui->widget->setLayout(layout);

       // add as a dock widget
//       QDockWidget* dockWidget = new QDockWidget;
//       dockWidget->setWidget(playerWidget);
//       this->addDockWidget(Qt::RightDockWidgetArea, dockWidget);

#endif

}
