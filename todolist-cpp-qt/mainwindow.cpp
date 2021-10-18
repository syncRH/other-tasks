#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_inputTask_editingFinished()
{
    QString arg1=  ui->inputTask->text();
    ui->inputTask->clear();
    ui->listWidget->addItem(arg1);
}

