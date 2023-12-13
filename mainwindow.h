#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "datainput.h"
#include "datamanager.h"
#include "chart.h"
#include "deletingrecords.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_inputButton_clicked();
    void on_chartButton_clicked();
    void on_deleteButton_clicked();

private:
    Ui::MainWindow *ui;
    DataInput *windowInput;
    DataManager *dataManager;
    Chart *chartWindow;
    DeletingRecords *deletingRecords;
};
#endif // MAINWINDOW_H
