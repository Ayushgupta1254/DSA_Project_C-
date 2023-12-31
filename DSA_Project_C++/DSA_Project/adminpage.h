#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QDialog>
#include "adminregstd.h"
#include "adminhistory.h"
#include "adminverlaundry.h"

namespace Ui {
class AdminPage;
}

class AdminPage : public QDialog
{
    Q_OBJECT

public:
    explicit AdminPage(QWidget *parent = nullptr);
    ~AdminPage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::AdminPage *ui;
    AdminRegStd *ptrAdminRegStd;
    AdminHistory *ptrAdminHistory;
    AdminVerLaundry *ptrAdminVerLaundry;
};

#endif // ADMINPAGE_H
