#ifndef ADMINREGSTD_H
#define ADMINREGSTD_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QDebug>
#include <QSqlTableModel>
#include <QFileInfo>
#include <QtSql>
#include <QMessageBox>
#include "databaseheader.h"
#include "databasemanager.h"

namespace Ui {
class AdminRegStd;
}

class AdminRegStd : public QDialog
{
    Q_OBJECT

public:
    explicit AdminRegStd(QWidget *parent = nullptr);
    ~AdminRegStd();

private slots:
    void on_btnRegister_clicked();

private:
    Ui::AdminRegStd *ui;

    QSqlDatabase myDB;
};

#endif // ADMINREGSTD_H
