#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QVector<int> natId;
    QVector<int> teamCntryId;

private:
    Ui::MainWindow *ui;
    int n = 0;
    int nat = 0;
    int cntry = 0;
    QString line;
    QStringList item;
private slots:
    void LblNvalueChanged();
    void LblNatCntryCurrentRowChanged();
    void CmdWriteDataClicked();
};

#endif // MAINWINDOW_H
