#include "kathiadminlogin.h"
#include "ui_kathiadminlogin.h"
#include "kathiadminpage.h"



KathiAdminLogin::KathiAdminLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KathiAdminLogin)
{
    ui->setupUi(this);

    ptrKathiAdminPage = new KathiAdminPage();

}

KathiAdminLogin::~KathiAdminLogin()
{
    delete ui;
}

void KathiAdminLogin::on_btnLogin_clicked()
{
    QString username = ui->txtUsername->text();
    QString password = ui->txtPassword->text();


    if(username == "admin@gmail.com" && password == "admin123"){
        QString msg0 = "Welcome Admin !!";
        QMessageBox::warning(this, "Success", msg0);
        ptrKathiAdminPage->show();
    }
    else{
        QString msg0 = "Invalid Details !!";
        QMessageBox::warning(this, "Wrong", msg0);
    }

}

