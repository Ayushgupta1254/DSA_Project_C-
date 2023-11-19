#ifndef KATHIHOMEPAGE_H
#define KATHIHOMEPAGE_H

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
//#include "kathihomepage.h"
#include "kathiorderingpage.h"
#include "ui_kathiorderingpage.h"
#include "kathiadminlogin.h"

namespace Ui {
class KathiHomePage;
}

class KathiHomePage : public QDialog
{
    Q_OBJECT

public:
    explicit KathiHomePage(QWidget *parent = nullptr);
    ~KathiHomePage();
    QSqlDatabase getDatabase() const;
    void closeDatabaseConnection();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::KathiHomePage *ui;
    KathiHomePage *ptrKathiHomePage;
    KathiOrderingPage *ptrKathiOrderingPage;
    KathiAdminLogin *ptrKathiAdminLogin;
    QString loggedInUsername;

    QSqlDatabase myDB;
};

#endif // KATHIHOMEPAGE_H
