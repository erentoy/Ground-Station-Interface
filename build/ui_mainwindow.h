/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>
#include "QtCharts"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *telemetryTable;
    QLabel *turksatLogo;
    QLabel *opsatLogo;
    QLabel *opsatText;
    QLabel *simulation;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *calibrateBttn;
    QPushButton *separateBttn;
    QPushButton *cvsBttn;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *timeLabel;
    QLCDNumber *minLcd;
    QLabel *label_2;
    QLCDNumber *secLcd;
    QLabel *label_3;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *videoPath;
    QPushButton *selectVideoBttn;
    QPushButton *pushButton_2;
    QListView *stateList;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *pushButton_3;
    QTabWidget *graphicsTabWidget;
    QWidget *generalTab;
    QChartView *speedGraph;
    QChartView *temperatureGraph;
    QChartView *voltageGraph;
    QChartView *distanceGraph;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLCDNumber *minLcd_4;
    QLCDNumber *minLcd_3;
    QLCDNumber *minLcd_2;
    QLCDNumber *minLcd_5;
    QCheckBox *checkBox;
    QWidget *payloadTAb;
    QWidget *containerTab;
    QWidget *widget_2;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QComboBox *comboBox_2;
    QPushButton *pushButton_4;
    QWidget *widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1905, 1018);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QPalette palette;
        MainWindow->setPalette(palette);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        telemetryTable = new QTableView(centralwidget);
        telemetryTable->setObjectName(QString::fromUtf8("telemetryTable"));
        telemetryTable->setGeometry(QRect(10, 760, 1891, 192));
        turksatLogo = new QLabel(centralwidget);
        turksatLogo->setObjectName(QString::fromUtf8("turksatLogo"));
        turksatLogo->setGeometry(QRect(1660, 10, 241, 61));
        opsatLogo = new QLabel(centralwidget);
        opsatLogo->setObjectName(QString::fromUtf8("opsatLogo"));
        opsatLogo->setGeometry(QRect(20, 10, 111, 161));
        opsatText = new QLabel(centralwidget);
        opsatText->setObjectName(QString::fromUtf8("opsatText"));
        opsatText->setGeometry(QRect(670, 10, 621, 61));
        QPalette palette1;
        QBrush brush(QColor(0, 170, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(227, 227, 227, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(160, 160, 160, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush4);
        QBrush brush5(QColor(0, 0, 127, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush6(QColor(105, 105, 105, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        QBrush brush7(QColor(0, 120, 215, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush7);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        QBrush brush8(QColor(0, 0, 255, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Link, brush8);
        QBrush brush9(QColor(255, 0, 255, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::LinkVisited, brush9);
        QBrush brush10(QColor(245, 245, 245, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        QBrush brush11(QColor(0, 0, 0, 255));
        brush11.setStyle(Qt::NoBrush);
        palette1.setBrush(QPalette::Active, QPalette::NoRole, brush11);
        QBrush brush12(QColor(255, 255, 220, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush12);
        QBrush brush13(QColor(0, 0, 0, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush13);
        QBrush brush14(QColor(0, 0, 0, 128));
        brush14.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush14);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::Link, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        QBrush brush15(QColor(0, 0, 0, 255));
        brush15.setStyle(Qt::NoBrush);
        palette1.setBrush(QPalette::Inactive, QPalette::NoRole, brush15);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush13);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush14);
#endif
        QBrush brush16(QColor(120, 120, 120, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush16);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        QBrush brush17(QColor(247, 247, 247, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush17);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush16);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Link, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        QBrush brush18(QColor(0, 0, 0, 255));
        brush18.setStyle(Qt::NoBrush);
        palette1.setBrush(QPalette::Disabled, QPalette::NoRole, brush18);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush13);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush14);
#endif
        opsatText->setPalette(palette1);
        QFont font;
        font.setPointSize(28);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        font.setKerning(false);
        opsatText->setFont(font);
        opsatText->setFrameShape(QFrame::NoFrame);
        opsatText->setFrameShadow(QFrame::Plain);
        opsatText->setTextFormat(Qt::PlainText);
        simulation = new QLabel(centralwidget);
        simulation->setObjectName(QString::fromUtf8("simulation"));
        simulation->setGeometry(QRect(1550, 410, 301, 331));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(700, 140, 301, 51));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        calibrateBttn = new QPushButton(layoutWidget);
        calibrateBttn->setObjectName(QString::fromUtf8("calibrateBttn"));

        gridLayout->addWidget(calibrateBttn, 0, 1, 1, 1);

        separateBttn = new QPushButton(layoutWidget);
        separateBttn->setObjectName(QString::fromUtf8("separateBttn"));

        gridLayout->addWidget(separateBttn, 0, 2, 1, 1);

        cvsBttn = new QPushButton(layoutWidget);
        cvsBttn->setObjectName(QString::fromUtf8("cvsBttn"));

        gridLayout->addWidget(cvsBttn, 0, 0, 1, 1);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(660, 80, 381, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        timeLabel = new QLabel(layoutWidget1);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));

        horizontalLayout->addWidget(timeLabel);

        minLcd = new QLCDNumber(layoutWidget1);
        minLcd->setObjectName(QString::fromUtf8("minLcd"));
        minLcd->setFrameShape(QFrame::NoFrame);
        minLcd->setDigitCount(2);

        horizontalLayout->addWidget(minLcd);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        secLcd = new QLCDNumber(layoutWidget1);
        secLcd->setObjectName(QString::fromUtf8("secLcd"));
        secLcd->setFrameShape(QFrame::NoFrame);
        secLcd->setDigitCount(2);

        horizontalLayout->addWidget(secLcd);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(160, 20, 401, 51));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        videoPath = new QLineEdit(layoutWidget2);
        videoPath->setObjectName(QString::fromUtf8("videoPath"));
        videoPath->setEnabled(false);
        QFont font1;
        font1.setItalic(true);
        font1.setUnderline(false);
        videoPath->setFont(font1);
        videoPath->setFrame(true);
        videoPath->setReadOnly(true);

        horizontalLayout_3->addWidget(videoPath);

        selectVideoBttn = new QPushButton(layoutWidget2);
        selectVideoBttn->setObjectName(QString::fromUtf8("selectVideoBttn"));

        horizontalLayout_3->addWidget(selectVideoBttn);

        pushButton_2 = new QPushButton(layoutWidget2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);

        stateList = new QListView(centralwidget);
        stateList->setObjectName(QString::fromUtf8("stateList"));
        stateList->setGeometry(QRect(1100, 80, 221, 121));
        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(160, 80, 401, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label);

        comboBox = new QComboBox(layoutWidget3);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy2);
        comboBox->setMaximumSize(QSize(16777215, 28));

        horizontalLayout_2->addWidget(comboBox);

        pushButton_3 = new QPushButton(layoutWidget3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);

        graphicsTabWidget = new QTabWidget(centralwidget);
        graphicsTabWidget->setObjectName(QString::fromUtf8("graphicsTabWidget"));
        graphicsTabWidget->setEnabled(true);
        graphicsTabWidget->setGeometry(QRect(10, 200, 1411, 531));
        generalTab = new QWidget();
        generalTab->setObjectName(QString::fromUtf8("generalTab"));
        speedGraph = new QChartView(generalTab);
        speedGraph->setObjectName(QString::fromUtf8("speedGraph"));
        speedGraph->setGeometry(QRect(20, 20, 301, 241));
        temperatureGraph = new QChartView(generalTab);
        temperatureGraph->setObjectName(QString::fromUtf8("temperatureGraph"));
        temperatureGraph->setGeometry(QRect(360, 20, 301, 241));
        voltageGraph = new QChartView(generalTab);
        voltageGraph->setObjectName(QString::fromUtf8("voltageGraph"));
        voltageGraph->setGeometry(QRect(700, 20, 301, 241));
        distanceGraph = new QChartView(generalTab);
        distanceGraph->setObjectName(QString::fromUtf8("distanceGraph"));
        distanceGraph->setGeometry(QRect(1050, 20, 301, 241));
        label_4 = new QLabel(generalTab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(100, 320, 63, 20));
        label_7 = new QLabel(generalTab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(310, 320, 63, 20));
        label_8 = new QLabel(generalTab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(570, 320, 63, 20));
        label_9 = new QLabel(generalTab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(770, 320, 111, 20));
        minLcd_4 = new QLCDNumber(generalTab);
        minLcd_4->setObjectName(QString::fromUtf8("minLcd_4"));
        minLcd_4->setGeometry(QRect(300, 380, 63, 39));
        minLcd_4->setFrameShape(QFrame::NoFrame);
        minLcd_4->setDigitCount(2);
        minLcd_4->setProperty("intValue", QVariant(24));
        minLcd_3 = new QLCDNumber(generalTab);
        minLcd_3->setObjectName(QString::fromUtf8("minLcd_3"));
        minLcd_3->setGeometry(QRect(80, 380, 63, 39));
        minLcd_3->setFrameShape(QFrame::NoFrame);
        minLcd_3->setDigitCount(2);
        minLcd_3->setProperty("intValue", QVariant(2));
        minLcd_2 = new QLCDNumber(generalTab);
        minLcd_2->setObjectName(QString::fromUtf8("minLcd_2"));
        minLcd_2->setGeometry(QRect(540, 380, 63, 39));
        minLcd_2->setFrameShape(QFrame::NoFrame);
        minLcd_2->setDigitCount(3);
        minLcd_2->setProperty("intValue", QVariant(140));
        minLcd_5 = new QLCDNumber(generalTab);
        minLcd_5->setObjectName(QString::fromUtf8("minLcd_5"));
        minLcd_5->setGeometry(QRect(770, 370, 63, 39));
        minLcd_5->setFrameShape(QFrame::NoFrame);
        minLcd_5->setDigitCount(2);
        minLcd_5->setProperty("intValue", QVariant(1));
        checkBox = new QCheckBox(generalTab);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(1050, 330, 241, 61));
        graphicsTabWidget->addTab(generalTab, QString());
        payloadTAb = new QWidget();
        payloadTAb->setObjectName(QString::fromUtf8("payloadTAb"));
        graphicsTabWidget->addTab(payloadTAb, QString());
        containerTab = new QWidget();
        containerTab->setObjectName(QString::fromUtf8("containerTab"));
        widget_2 = new QWidget(containerTab);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(240, 40, 481, 291));
        graphicsTabWidget->addTab(containerTab, QString());
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(160, 136, 401, 51));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setEnabled(true);
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(label_6);

        comboBox_2 = new QComboBox(layoutWidget_2);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        sizePolicy2.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy2);
        comboBox_2->setMaximumSize(QSize(16777215, 28));

        horizontalLayout_4->addWidget(comboBox_2);

        pushButton_4 = new QPushButton(layoutWidget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_4->addWidget(pushButton_4);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(1430, 90, 450, 300));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1905, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        graphicsTabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        turksatLogo->setText(QCoreApplication::translate("MainWindow", "Turksat Logo", nullptr));
        opsatLogo->setText(QCoreApplication::translate("MainWindow", "Team Logo", nullptr));
        opsatText->setText(QCoreApplication::translate("MainWindow", "OPSAT GROUND STATION", nullptr));
        simulation->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        calibrateBttn->setText(QCoreApplication::translate("MainWindow", "Calibrate", nullptr));
        separateBttn->setText(QCoreApplication::translate("MainWindow", "Separate", nullptr));
        cvsBttn->setText(QCoreApplication::translate("MainWindow", "Create .cvs File", nullptr));
        timeLabel->setText(QCoreApplication::translate("MainWindow", "MISSION TIME:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "min", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "sec", nullptr));
        videoPath->setText(QCoreApplication::translate("MainWindow", "D:/Documents/video.mp4", nullptr));
        selectVideoBttn->setText(QCoreApplication::translate("MainWindow", "Select Video", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Send Video", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Telemetri Com Port:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Select Port", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "COM1", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "COM2", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "COM3", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "COM4", nullptr));

        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Pitch", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Roll", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Yaw", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Spin Count ", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Video Transfer Finished", nullptr));
        graphicsTabWidget->setTabText(graphicsTabWidget->indexOf(generalTab), QCoreApplication::translate("MainWindow", "General", nullptr));
        graphicsTabWidget->setTabText(graphicsTabWidget->indexOf(payloadTAb), QCoreApplication::translate("MainWindow", "Payload", nullptr));
        graphicsTabWidget->setTabText(graphicsTabWidget->indexOf(containerTab), QCoreApplication::translate("MainWindow", "Container", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Video Com Port:", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Select Port", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "COM1", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "COM2", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "COM3", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("MainWindow", "COM4", nullptr));

        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
