#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QFileDialog>
#include <QFrame>
#include <QGridLayout>
#include <QComboBox>
#include <QCheckBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_btnOpenFile_clicked();

    void on_btnShowHidden_clicked();

private:
    void initStatusBar();
    void initUi();
    void connectSlots();
public:
    QLabel *sbSendLen;
    QLabel *sbRecvLen;
    QLabel *sbStatus;
    QLabel *sbFlags;
    QFrame *frameSerialSettings;
    QPushButton *btnSerialMoreSettingsbtnSend;
    QComboBox *cbBoxBaudRate;
    QPushButton *btnSerialRefresh;
    QCheckBox *cBoxRTS;
    QCheckBox *cBoxDTR;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
