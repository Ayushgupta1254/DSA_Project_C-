#ifndef LAUNDRYHOMEPAGE_H
#define LAUNDRYHOMEPAGE_H
#include "adminlogin.h"
#include "laundrydropver.h"

#include <QDialog>


namespace Ui {
class LaundryHomePage;
}

class LaundryHomePage : public QDialog
{
    Q_OBJECT

public:
    explicit LaundryHomePage(QWidget *parent = nullptr);
    ~LaundryHomePage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::LaundryHomePage *ui;
    AdminLogin *ptrAdminLogin;
    LaundryDropVer *ptrLaundryDropVer;
};

#endif // LAUNDRYHOMEPAGE_H
