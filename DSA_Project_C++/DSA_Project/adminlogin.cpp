#include "adminlogin.h"
#include "ui_adminlogin.h"
#include "adminpage.h"

AdminLogin::AdminLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminLogin)
{
    ui->setupUi(this);
    ptrAdminPage = new AdminPage();
}

AdminLogin::~AdminLogin()
{
    delete ui;
}

void AdminLogin::on_btnLogin_clicked()
{
    QString Username = ui->txtUserName->text();
    QString Password = ui->txtPassword->text();

    if(Username=="admin@gmail.com" && Password =="admin123"){
        QString msg = "Welcome Admin !!";
        QMessageBox::warning(this,"Login was successful",msg);
        ptrAdminPage->show();
        ui->txtUserName->setText("");
        ui->txtPassword->setText("");
    }
    else{
        QString msg0 = "Please Enter Correct Details";
        QMessageBox::warning(this,"Not correct Credentials",msg0);
    }
}

