#ifndef KATHIADMINPENDINGORDER_H
#define KATHIADMINPENDINGORDER_H

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
class KathiAdminPendingOrder;
}

class KathiAdminPendingOrder : public QDialog
{
    Q_OBJECT

public:
    explicit KathiAdminPendingOrder(QWidget *parent = nullptr);
    ~KathiAdminPendingOrder();

private slots:
    void on_tableKathiOrderP_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::KathiAdminPendingOrder *ui;

    QSqlDatabase myDB;
};

#endif // KATHIADMINPENDINGORDER_H
