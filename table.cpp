#include "table.h"
#include "ui_table.h"
#include "mainwindow.h"

Table::Table(QWidget *parent, DataManager* dataManager, MainWindow* mainWindow)
    : QDialog(parent)
    , ui(new Ui::Table)
{
    ui->setupUi(this);

    this->dataManager = dataManager;
    this->mainWindow = mainWindow;

    QSqlTableModel* model = dataManager->getDataModel();
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

Table::~Table()
{
    delete ui;
}

void Table::on_exitButton_clicked()
{
    mainWindow->show();
    close();
}

