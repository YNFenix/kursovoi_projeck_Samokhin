#include "datainput.h"
#include "ui_datainput.h"
#include "datamanager.h"
#include "mainwindow.h"

DataInput::DataInput(QWidget *parent, DataManager* dataManager, MainWindow* mainWindow)
    : QDialog(parent)
    , ui(new Ui::DataInput)
{
    ui->setupUi(this);

    this->dataManager = dataManager;
    this->mainWindow = mainWindow;

    connect(ui->date, SIGNAL(selectionChanged()), this, SLOT(onDateSelectionChanged()));

    setWindowFlags(windowFlags() | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
}

DataInput::~DataInput()
{
    delete ui;
}

void DataInput::onDateSelectionChanged()
{
    selectedDate = ui->date->selectedDate();
}

void DataInput::on_saveInput_clicked()
{

    QString weight = ui->weight->text();

    bool conversionOK;
    double weightValue = weight.toDouble(&conversionOK);

    if (!conversionOK)
    {
        QMessageBox::critical(this, "Ошибка", "Пожалуйста, введите корректный вес (число).");
        return;
    }

    QString date = ui->date->selectedDate().toString("dd-MM-yyyy");

    if (!ui->date->selectedDate().isValid()) {
        QMessageBox::critical(this, "Ошибка", "Выберите дату.");
        return;
    }

    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString dataSave = currentDateTime.toString("dd-MM-yyyy");

    // Вставка данных с использованием DataManager
    dataManager->insertData(QString::number(weightValue), date, dataSave);

    if (dataManager->getDataModel()->lastError().isValid()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось сохранить данные.");
    } else {
        QMessageBox::information(this, "Успех", "Данные успешно сохранены.");
    }

    mainWindow->show();
    close();
}

void DataInput::on_backInput_clicked()
{
    close();

    mainWindow->show();
}

