#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUi();
    initStatusBar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initStatusBar()
{
    this->sbSendLen = new QLabel(QString("S:0"));
    sbSendLen->setMinimumSize(60, 14);
    this->sbRecvLen = new QLabel(QString("R:0"));
    sbSendLen->setMinimumSize(60, 14);
    this->sbStatus = new QLabel;
    this->sbFlags = new QLabel;
    ui->statusbar->addWidget(this->sbSendLen);
    ui->statusbar->addWidget(this->sbRecvLen);
    ui->statusbar->addWidget(this->sbStatus);
    ui->statusbar->addWidget(this->sbFlags);
}

void MainWindow::initUi()
{
    ui->tableView->setHidden(true);

    frameSerialSettings = new QFrame(ui->centralwidget);
    frameSerialSettings->setObjectName(QString::fromUtf8("frameSerialSettings"));
    frameSerialSettings->setGeometry(QRect(920, 440, 237, 71));
    frameSerialSettings->setFrameShape(QFrame::StyledPanel);
    frameSerialSettings->setFrameShadow(QFrame::Raised);
    QGridLayout *layoutSerialSettingsParent = new QGridLayout(frameSerialSettings);
    layoutSerialSettingsParent->setObjectName(QString::fromUtf8("layoutSerialSettingsParent"));
    QGridLayout *layoutSerialSettings = new QGridLayout();
    layoutSerialSettings->setObjectName(QString::fromUtf8("layoutSerialSettings"));

    QLabel *labelBaudRate = new QLabel(frameSerialSettings);
    labelBaudRate->setObjectName(QString::fromUtf8("labelBaudRate"));
    labelBaudRate->setMaximumSize(QSize(80, 30));
    QFont font;
    font.setBold(true);
    labelBaudRate->setFont(font);

    layoutSerialSettings->addWidget(labelBaudRate, 0, 0, 1, 1);

    cbBoxBaudRate = new QComboBox(frameSerialSettings);
    cbBoxBaudRate->setObjectName(QString::fromUtf8("cbBoxBaudRate"));
    cbBoxBaudRate->setMaximumSize(QSize(16777215, 30));
    cbBoxBaudRate->setEditable(true);

    layoutSerialSettings->addWidget(cbBoxBaudRate, 0, 1, 1, 1);

    btnSerialRefresh = new QPushButton(frameSerialSettings);
    btnSerialRefresh->setObjectName(QString::fromUtf8("btnSerialRefresh"));
    btnSerialRefresh->setMaximumSize(QSize(150, 30));
    btnSerialRefresh->setFont(font);

    layoutSerialSettings->addWidget(btnSerialRefresh, 0, 2, 1, 1);

    cBoxRTS = new QCheckBox(frameSerialSettings);
    cBoxRTS->setObjectName(QString::fromUtf8("cBoxRTS"));
    cBoxRTS->setMaximumSize(QSize(100, 30));
    cBoxRTS->setFont(font);

    layoutSerialSettings->addWidget(cBoxRTS, 1, 0, 1, 1);

    cBoxDTR = new QCheckBox(frameSerialSettings);
    cBoxDTR->setObjectName(QString::fromUtf8("cBoxDTR"));
    cBoxDTR->setMaximumSize(QSize(100, 30));
    cBoxDTR->setFont(font);

    layoutSerialSettings->addWidget(cBoxDTR, 1, 1, 1, 1);

    btnSerialMoreSettingsbtnSend = new QPushButton(frameSerialSettings);
    btnSerialMoreSettingsbtnSend->setObjectName(QString::fromUtf8("btnSerialMoreSettingsbtnSend"));
    btnSerialMoreSettingsbtnSend->setMaximumSize(QSize(16777215, 30));
    btnSerialMoreSettingsbtnSend->setFont(font);

    layoutSerialSettings->addWidget(btnSerialMoreSettingsbtnSend, 1, 2, 1, 1);

    layoutSerialSettingsParent->addLayout(layoutSerialSettings, 0, 0, 1, 1);
    ui->gridLayoutLeftCenterTailLeft->addWidget(frameSerialSettings, 1, 0, 1, 1);
    ui->frameNetwork->setHidden(true);
    frameSerialSettings->setHidden(false);
//    layoutSerialSettingsParent->addLayout(ui->gridLayout_2, 0, 0, 1, 1);
    labelBaudRate->setText(QCoreApplication::translate("MainWindow", "BaudRate:", nullptr));
    btnSerialRefresh->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
    cBoxRTS->setText(QString("RTS"));
    cBoxDTR->setText(QString("DTR"));
    btnSerialMoreSettingsbtnSend->setText(QCoreApplication::translate("MainWindow", "MoreSettings", nullptr));

}

void MainWindow::connectSlots()
{
//    connect(ui->btnOpenFile, SIGNAL(clicked()), nullptr, SLOT(this->on_btnOpenFile_clicked()));
}

void MainWindow::on_btnOpenFile_clicked()
{
    qDebug("open button clicked!");
    QString path = QFileDialog::getOpenFileName(this, tr("Open Data File"), ".", tr("Data Files(*.txt *.data)"));
    ui->txtFilePath->setText(path);
}

void MainWindow::on_btnShowHidden_clicked()
{
    if (ui->tableView->isHidden())
    {
        ui->btnShowHidden->setText(tr("Hidden"));
        ui->tableView->setHidden(false);
    }
    else
    {
        ui->btnShowHidden->setText(tr("Show"));
        ui->tableView->setHidden(true);
    }
}

