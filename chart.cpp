// chart.cpp
#include "chart.h"
#include "ui_chart.h"
#include "mainwindow.h"
#include "datamanager.h"

#include <QSqlRecord>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>

Chart::Chart(QWidget* parent, MainWindow* mainWindow)
    : QDialog(parent),
    ui(new Ui::Chart)
{
    ui->setupUi(this);

    this->mainWindow = mainWindow;

    dataManager = new DataManager();
    setupChart();
}

Chart::~Chart()
{
    delete ui;
    delete dataManager;
}

void Chart::on_exitButton_clicked()
{
    mainWindow->show();
    close();
}

void Chart::setupChart()
{
    chartView = new QChartView(this);
    QChart *chart = new QChart();
    chart->setTitle("Weight Chart");
    QLineSeries *series = new QLineSeries();

    QSqlTableModel *model = dataManager->getDataModel();
    int rowCount = model->rowCount();
    for (int i = 0; i < rowCount; ++i) {
        QString weight = model->record(i).value("Показатели веса").toString();
        QString date = model->record(i).value("Дата измерения").toString();
        QDateTime dateTime = QDateTime::fromString(date, "dd-MM-yyyy");

        series->append(dateTime.toMSecsSinceEpoch(), weight.toDouble());
    }

    chart->addSeries(series);

    // Создаем ось X
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setFormat("dd-MM");
    axisX->setTitleText("Дата измерения");

    // Создаем ось Y
    QValueAxis *axisY = new QValueAxis;
    axisY->setTitleText("Показатели веса");

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    chart->setTheme(QChart::ChartThemeHighContrast);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setDropShadowEnabled(true);
    chart->setMargins(QMargins(5, 5, 5, 5));
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->verticalLayout->addWidget(chartView);
}



