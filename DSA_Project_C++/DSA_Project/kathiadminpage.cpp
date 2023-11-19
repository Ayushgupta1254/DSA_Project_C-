#include "kathiadminpage.h"
#include "ui_kathiadminpage.h"

KathiAdminPage::KathiAdminPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KathiAdminPage)
{
    ui->setupUi(this);

    ptrKathiAdminViewOrders = new KathiAdminViewOrders();
    ptrKathiAdminPendingOrder = new KathiAdminPendingOrder();
}

KathiAdminPage::~KathiAdminPage()
{
    delete ui;
}

void KathiAdminPage::on_pushButton_clicked()
{
    ptrKathiAdminViewOrders->show();
}


void KathiAdminPage::on_pushButton_2_clicked()
{
    ptrKathiAdminPendingOrder->show();
}

