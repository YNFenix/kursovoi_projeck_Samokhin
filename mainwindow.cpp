#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dataManager = new DataManager();
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_inputButton_clicked()
{
    hide();

    windowInput = new DataInput(this, dataManager, this);

    windowInput->setModal(true);
    windowInput->exec();
}


void MainWindow::on_chartButton_clicked()
{
    hide();

    chartWindow = new Chart(this, this);
    chartWindow->setModal(true);
    chartWindow->exec();
}



void MainWindow::on_deleteButton_clicked()
{
    hide();

    deletingRecords = new DeletingRecords(this, dataManager, this);
    deletingRecords->setModal(true);
    deletingRecords->exec();
}

