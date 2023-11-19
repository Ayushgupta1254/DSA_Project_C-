#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QDialog>
#include <QMessageBox>
#include "adminpage.h"

namespace Ui {
class AdminLogin;
}

class AdminLogin : public QDialog
{
    Q_OBJECT

public:
    explicit AdminLogin(QWidget *parent = nullptr);
    ~AdminLogin();

private slots:
    void on_btnLogin_clicked();

private:
    Ui::AdminLogin *ui;
    AdminPage *ptrAdminPage;
};

#endif // ADMINLOGIN_H
