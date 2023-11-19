#ifndef LAUNDRYCLOTHESSTD_H
#define LAUNDRYCLOTHESSTD_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QDebug>
#include <QSqlTableModel>
#include <QFileInfo>
#include <QtSql>
#include <QMessageBox>
#include "databasemanager.h"

namespace Ui {
class LaundryClothesStd;
}

class LaundryClothesStd : public QDialog
{
    Q_OBJECT

public:
    explicit LaundryClothesStd(QWidget *parent = nullptr);
    ~LaundryClothesStd();
    void setValues(const QString& enroll, const QString& bag);

private slots:
    void on_btnSubmit_clicked();

    void on_btncart_clicked();

private:
    Ui::LaundryClothesStd *ui;

    QSqlDatabase myDB;
};

#endif // LAUNDRYCLOTHESSTD_H
