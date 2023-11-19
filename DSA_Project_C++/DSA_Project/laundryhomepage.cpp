#include "laundryhomepage.h"
#include "ui_laundryhomepage.h"
#include "adminlogin.h"

LaundryHomePage::LaundryHomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LaundryHomePage)
{
    ui->setupUi(this);

    ptrAdminLogin = new AdminLogin();
    ptrLaundryDropVer = new LaundryDropVer();
}

LaundryHomePage::~LaundryHomePage()
{
    delete ui;
}

void LaundryHomePage::on_pushButton_clicked()
{
    ptrAdminLogin->show();
}


void LaundryHomePage::on_pushButton_2_clicked()
{
    ptrLaundryDropVer->show();
}

