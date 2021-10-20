#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mydialog *mdial = new mydialog();
    mdial->show();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_inputTask_editingFinished()
{
    QString arg1 =  ui->inputTask->text();
    ui->inputTask->clear();
    if(arg1.length() < 20 && arg1.length() > 1) {
        QListWidgetItem *newItem = new QListWidgetItem;
        newItem->setText(arg1);
        newItem->setFlags(newItem->flags().setFlag(Qt::ItemIsEditable, true));
        ui->listWidget->addItem(newItem);
    }
    // else - дописать вывод окна ошибки при превышении 20 символов.
}


void MainWindow::on_listWidget_itemChanged(QListWidgetItem *item)
{
    QString temp = item->text();
    if(temp.length() < 20 && temp.length() > 1) item->setText(temp);
    else {
        item->setText(item->previousText());
        // дописать вывод окна ошибки изменения при превышении 20 символов
        // и при пустом тексте.
        }
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item) {
 if (item) item->setPreviousText(item->text());
}
