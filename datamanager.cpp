#include "datamanager.h"

DataManager::DataManager()
{
    // Инициализация базы данных и модели
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./dataBase.db");

    if (db.open())
    {
        qDebug("Open");
    }
    else
    {
        qDebug("Not open!");
    }

    query = new QSqlQuery(db);
    query->exec("CREATE TABLE WeightMagazine(\"Показатели веса\", \"Дата измерения\" , \"Дата добавления\")");

    model = new QSqlTableModel(nullptr, db);
    model->setTable("WeightMagazine");
    model->select();
}

DataManager::~DataManager()
{
    delete query;
    delete model;
}

void DataManager::insertData(const QString& weight, const QString& data, const QString& dataSave)
{
    QString queryString = "INSERT INTO WeightMagazine (\"Показатели веса\", \"Дата измерения\" , \"Дата добавления\") VALUES (:weight, :data, :dataSave)";
    query->prepare(queryString);
    query->bindValue(":weight", weight);
    query->bindValue(":data", data);
    query->bindValue(":dataSave", dataSave);

    if (query->exec()) {
        qDebug("Data saved successfully");
        model->select();
    } else {
        qDebug("Error saving data: %s", qPrintable(query->lastError().text()));
    }
}

QSqlTableModel* DataManager::searchModel(const QDate& searchDate)
{
    QSqlTableModel* searchModel = new QSqlTableModel(nullptr, db);
    searchModel->setTable("WeightMagazine");

    QString queryString = "SELECT * FROM WeightMagazine WHERE \"Дата измерения\" = :searchDate";
    QSqlQuery searchQuery(db);
    searchQuery.prepare(queryString);
    searchQuery.bindValue(":searchDate", searchDate.toString("dd-MM-yyyy"));

    if (searchQuery.exec()) {
        searchModel->setQuery(searchQuery);
        return searchModel;
    } else {
        qDebug("Ошибка поиска данных: %s", qPrintable(searchQuery.lastError().text()));
        delete searchModel;
        return nullptr;
    }
}

QSqlTableModel* DataManager::getDataModel()
{
    return model;
}
