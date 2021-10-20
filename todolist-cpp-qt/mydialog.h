#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QFrame>

namespace Ui {
class mydialog;
}

class mydialog : public QFrame
{
    Q_OBJECT

public:
    explicit mydialog(QWidget *parent = nullptr);
    ~mydialog();

private:
    Ui::mydialog *ui;
};

#endif // MYDIALOG_H
