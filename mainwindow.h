#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QSerialPort>
// qcustomplot

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int number = 1;

private:
    Ui::MainWindow *ui;

    QLineSeries *altitudeSeries;
    QChart *altitudeChart;

    QStandardItemModel *telemetryModel;
    QFile cvsFile;
    QSerialPort* arduino;

    static const quint16 arduino_uno_vendor_id = 6790;
    static const quint16 arduino_uno_product_id = 29987;
    int rowNumber = 1;

    void AddData();
    void InitializeAltitudeGraph();
    void InitializeTelemetryTable();
    void OpenCVS();
    void AddToTable();
    void ReadPort();
    void CreateStateTable();
    void ConnectSerialPort();
    void CreateVideoPlayer();
};
#endif // MAINWINDOW_H
