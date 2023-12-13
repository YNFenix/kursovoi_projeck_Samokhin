#include "deletingrecords.h"
#include "ui_deletingrecords.h"
#include "mainwindow.h"

DeletingRecords::DeletingRecords(QWidget *parent, DataManager* dataManager, MainWindow* mainWindow)
    : QDialog(parent)
    , ui(new Ui::DeletingRecords)
{
    ui->setupUi(this);

    this->datamanager = dataManager;
    this->mainWindow = mainWindow;

    QSqlTableModel* model = dataManager->getDataModel();
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->deleteButton, &QPushButton::clicked, this, &DeletingRecords::onDeleteButtonClicked);

    connect(ui->searchButton, &QPushButton::clicked, this, &DeletingRecords::onSearchButtonClicked);

}

DeletingRecords::~DeletingRecords()
{
    delete ui;
}

void DeletingRecords::onSearchButtonClicked()
{
    QDate selectedDate = ui->calendarWidget->selectedDate();

    // Передаем выбранную дату в метод searchModel
    QSqlTableModel* searchModel = datamanager->searchModel(selectedDate);

    if (searchModel && searchModel->rowCount() > 0) {
        ui->tableView->setModel(searchModel);
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    } else {
        QMessageBox::warning(this, "Ошибка", "Запись не найдена.", QMessageBox::Ok);
    }
}


void DeletingRecords::onDeleteButtonClicked()
{
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();

    if (!selectedRows.isEmpty())
    {
        QSqlTableModel *model = qobject_cast<QSqlTableModel *>(ui->tableView->model());

        for (const QModelIndex &index : selectedRows)
        {
            model->removeRow(index.row());
        }

        if (!model->submitAll())
        {
            qDebug() << "Ошибка при удалении данных: " << model->lastError().text();
            model->revertAll();
        }
        else
        {
            QMessageBox::information(this, "Успех", "Записи успешно удалены.", QMessageBox::Ok);
        }

        model->select();
    }
}


void DeletingRecords::on_pushButton_clicked()
{
    mainWindow->show();
    close();
}

