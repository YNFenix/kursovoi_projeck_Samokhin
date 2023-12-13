#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");

    MainWindow w;
    QPalette m_pal;

    m_pal.setColor(QPalette::Window, QColor(37, 37, 38));
    m_pal.setColor(QPalette::WindowText, QColor(255, 255, 255));
    m_pal.setColor(QPalette::Button, QColor(64, 64, 64));
    m_pal.setColor(QPalette::ButtonText, QColor(255, 255, 255));
    m_pal.setColor(QPalette::Highlight, QColor(10, 124, 242));
    m_pal.setColor(QPalette::HighlightedText, QColor(255, 255, 255));

    w.setPalette(m_pal);

    w.show();
    return a.exec();
}
