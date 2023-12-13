#ifndef DATAINPUT_H
#define DATAINPUT_H

#include <QDialog>
#include <QMessageBox>
#include <QDateTime>

#include "datamanager.h"

class MainWindow;

namespace Ui {
class DataInput;
}

class DataInput : public QDialog
{
    Q_OBJECT

public:
    explicit DataInput(QWidget *parent, DataManager* dataManager, MainWindow* mainWindow);
    ~DataInput();

private slots:
    void on_saveInput_clicked();
    void onDateSelectionChanged();
    void on_backInput_clicked();

private:
    Ui::DataInput *ui;
    DataManager* dataManager;
    MainWindow *mainWindow;
    QDate selectedDate;
};

#endif // DATAINPUT_H
