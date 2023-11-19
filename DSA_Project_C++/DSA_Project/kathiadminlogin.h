#ifndef KATHIADMINLOGIN_H
#define KATHIADMINLOGIN_H

#include <QDialog>
#include <QMessageBox>
#include "kathiadminpage.h"


namespace Ui {
class KathiAdminLogin;
}

class KathiAdminLogin : public QDialog
{
    Q_OBJECT

public:
    explicit KathiAdminLogin(QWidget *parent = nullptr);
    ~KathiAdminLogin();

private slots:
    void on_btnLogin_clicked();

private:
    Ui::KathiAdminLogin *ui;

    KathiAdminPage *ptrKathiAdminPage;
};

#endif // KATHIADMINLOGIN_H
