#ifndef CHART_H
#define CHART_H

#include <QDialog>
#include <QChartView>
#include <QLineSeries>

#include "datainput.h"

class MainWindow;

namespace Ui {
class Chart;
}

class Chart : public QDialog
{
    Q_OBJECT

public:
    explicit Chart(QWidget *parent = nullptr, MainWindow* mainWindow = nullptr);
    ~Chart();

private slots:
    void on_exitButton_clicked();

private:
    Ui::Chart *ui;
    DataManager* dataManager;
    MainWindow *mainWindow;
    QChartView *chartView;
    void setupChart();
};

#endif // CHART_H
