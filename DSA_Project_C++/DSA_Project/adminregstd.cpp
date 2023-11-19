#include "adminregstd.h"
#include "ui_adminregstd.h"
#include "kathihomepage.h"
#include "databasemanager.h"

AdminRegStd::AdminRegStd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminRegStd)
{
    ui->setupUi(this);

    QString databasePath = "C:/Users/rahul/OneDrive/Documents/DSA_Project/database/DSAProject.db";
    QString connectionName = "AdminRegStdConnection";

    myDB = DatabaseManager::getDatabase(databasePath,connectionName);

    if (!myDB.isOpen()) {
        qDebug() << "Error opening database:" << myDB.lastError().text();

    } else {
        qDebug() << "Database opened successfully!";

    }

}

AdminRegStd::~AdminRegStd()
{
    //DatabaseManager::closeDatabase("AdminRegStdConnection");
    delete ui;
}

void AdminRegStd::on_btnRegister_clicked()
{
    QString ENo = ui->txtENo->text();
    QString Name = ui->txtName->text();
    QString PhoneNo = ui->txtPhoneNo->text();
    QString BagNo = ui->txtBagNo->text();

    if(!myDB.isOpen()){
        qDebug()<<"No connection to db : (";
        return;
    }
    QSqlQuery qry(myDB);

    qry.prepare("INSERT INTO LaundryVer (EnrollNo, Name, PhoneNo, BagNo) VALUES (?, ?, ?, ?)");
    qry.addBindValue(ENo);
    qry.addBindValue(Name);
    qry.addBindValue(PhoneNo);
    qry.addBindValue(BagNo);

    if (qry.exec()) {
        QString msg0 = "Student Registered !!";
        QMessageBox::warning(this, "Success", msg0);
    } else {
        qDebug() << "Error executing query:" << qry.lastError().text();
    }

    qry.finish();

    myDB.close();

    qDebug() << "Database connection closed.";



}
