#ifndef TABLE_H
#define TABLE_H

#include <QDialog>

#include "datamanager.h"

class MainWindow;

namespace Ui {
class Table;
}

class Table : public QDialog
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent, DataManager* dataManager, MainWindow* mainWindow);
    ~Table();

private slots:
    void on_exitButton_clicked();

private:
    Ui::Table *ui;
    DataManager *dataManager;
    MainWindow *mainWindow;
};

#endif // TABLE_H
