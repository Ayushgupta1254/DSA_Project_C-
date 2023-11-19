#include "adminpage.h"
#include "ui_adminpage.h"
//#include "ui_adminregstd.h"
#include "adminregstd.h"
#include "adminhistory.h"

AdminPage::AdminPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminPage)
{
    ui->setupUi(this);
    ptrAdminRegStd = new AdminRegStd();
    ptrAdminHistory = new AdminHistory();
    ptrAdminVerLaundry = new AdminVerLaundry();
}

AdminPage::~AdminPage()
{
    delete ui;
}

void AdminPage::on_pushButton_clicked()
{
    ptrAdminRegStd->show();
}


void AdminPage::on_pushButton_2_clicked()
{
    ptrAdminHistory->show();
}


void AdminPage::on_pushButton_3_clicked()
{
    ptrAdminVerLaundry->show();
}

