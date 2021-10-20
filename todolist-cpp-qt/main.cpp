#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <vector>
#include <string>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    mydialog *fwin = new mydialog();

    w.setWindowFlags(Qt::FramelessWindowHint);
    w.setAttribute(Qt::WA_TranslucentBackground);
    w.setAttribute(Qt::WA_NoSystemBackground);
    w.setWindowTitle("TODO-LIST");
    fwin->show();
    w.show();
    return a.exec();
}
