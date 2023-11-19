#ifndef ADMINHISTORY_H
#define ADMINHISTORY_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QDebug>
#include <QSqlTableModel>
#include <QFileInfo>
#include <QtSql>
#include <QMessageBox>

namespace Ui {
class AdminHistory;
}

class AdminHistory : public QDialog
{
    Q_OBJECT

public:
    explicit AdminHistory(QWidget *parent = nullptr);
    ~AdminHistory();

private slots:
    void on_pushButton_clicked();

    void on_btnView_clicked();

private:
    Ui::AdminHistory *ui;
    QSqlDatabase myDB;
};

#endif // ADMINHISTORY_H
