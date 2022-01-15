#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>

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
    QLineSeries *series;
    QChart *chart;
    QStandardItemModel *telemetryModel;
    QFile cvsFile;
    int rowNumber = 1;

    void AddData();
    void InitializeGraph();
    void InitializeTelemetryTable();
    void OpenCVS();
    void AddToTable();

};
#endif // MAINWINDOW_H
