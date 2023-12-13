#ifndef DELETINGRECORDS_H
#define DELETINGRECORDS_H

#include <QDialog>

#include "datamanager.h"

class MainWindow;

namespace Ui {
class DeletingRecords;
}

class DeletingRecords : public QDialog
{
    Q_OBJECT

public:
    explicit DeletingRecords(QWidget *parent = nullptr, DataManager* dataManager = nullptr, MainWindow* mainWindow = nullptr);
    ~DeletingRecords();

    void onSearchButtonClicked();

private slots:
    void on_pushButton_clicked();
    void onDeleteButtonClicked();

private:
    Ui::DeletingRecords *ui;
    MainWindow *mainWindow;
    DataManager *datamanager;
};

#endif // DELETINGRECORDS_H
