#ifndef KATHIADMINVIEWORDERS_H
#define KATHIADMINVIEWORDERS_H

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
class KathiAdminViewOrders;
}

class KathiAdminViewOrders : public QDialog
{
    Q_OBJECT

public:
    explicit KathiAdminViewOrders(QWidget *parent = nullptr);
    ~KathiAdminViewOrders();

private slots:
    void on_btnView_clicked();

private:
    Ui::KathiAdminViewOrders *ui;

    QSqlDatabase myDB;
};

#endif // KATHIADMINVIEWORDERS_H
