#include "mydialog.h"
#include "ui_mydialog.h"

mydialog::mydialog(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::mydialog)
{
    ui->setupUi(this);
}

mydialog::~mydialog()
{
    delete ui;
}
