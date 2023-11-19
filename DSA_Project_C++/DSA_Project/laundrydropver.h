#ifndef LAUNDRYDROPVER_H
#define LAUNDRYDROPVER_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QDebug>
#include <QSqlTableModel>
#include <QFileInfo>
#include <QtSql>
#include <QMessageBox>
#include "kathihomepage.h"
#include "ui_kathihomepage.h"
#include "databasemanager.h"
#include "laundryclothesstd.h"

namespace Ui {
class LaundryDropVer;
}

class LaundryDropVer : public QDialog
{
    Q_OBJECT

public:
    explicit LaundryDropVer(QWidget *parent = nullptr);
    ~LaundryDropVer();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LaundryDropVer *ui;
    LaundryClothesStd *ptrLaundryClothesStd;
    QSqlDatabase myDB;
};

#endif // LAUNDRYDROPVER_H
