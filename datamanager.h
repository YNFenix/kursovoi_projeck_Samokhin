#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QSqlTableModel>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QDate>

class DataManager
{
public:
    DataManager();
    ~DataManager();

    void insertData(const QString& weight, const QString& data, const QString& dataSave);
    QSqlTableModel* getDataModel();
    QSqlTableModel* searchModel(const QDate& searchDate);

private:
    QSqlDatabase db;
    QSqlQuery* query;
    QSqlTableModel* model;
};

#endif // DATAMANAGER_H
