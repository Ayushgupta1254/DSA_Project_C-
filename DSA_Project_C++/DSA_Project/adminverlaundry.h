#ifndef ADMINVERLAUNDRY_H
#define ADMINVERLAUNDRY_H

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
class AdminVerLaundry;
}

class AdminVerLaundry : public QDialog
{
    Q_OBJECT

public:
    explicit AdminVerLaundry(QWidget *parent = nullptr);
    ~AdminVerLaundry();

private slots:
    void on_btnSearch_clicked();

    void on_pushButton_clicked();

private:
    Ui::AdminVerLaundry *ui;
    QSqlDatabase myDB;
};

#endif // ADMINVERLAUNDRY_H
