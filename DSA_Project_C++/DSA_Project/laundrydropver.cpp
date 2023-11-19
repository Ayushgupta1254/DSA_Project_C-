#include "laundrydropver.h"
#include "ui_laundrydropver.h"
#include "databasemanager.h"
#include "laundryclothesstd.h"




#define Path_to_DB "C:/Users/rahul/OneDrive/Documents/DSA_Project/database/DSAProject.db"


LaundryDropVer::LaundryDropVer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LaundryDropVer)
{
    ui->setupUi(this);

    ptrLaundryClothesStd = new LaundryClothesStd();

    QString databasePath = "C:/Users/rahul/OneDrive/Documents/DSA_Project/database/DSAProject.db";
    QString connectionName = "LaundryDropVerConnection";

    myDB = DatabaseManager::getDatabase(databasePath,connectionName);

    if (!myDB.isOpen()) {
        qDebug() << "Error opening database:" << myDB.lastError().text();

    } else {
        qDebug() << "Database opened successfully!";

    }

}

LaundryDropVer::~LaundryDropVer()
{
    DatabaseManager::closeDatabase("LaundryDropVerConnection");
    delete ui;
    qDebug()<<"Closing the connection to Database file on exit.";
    //myDB.close();
}

void LaundryDropVer::on_pushButton_clicked()
{
    QString ENo = ui->txtENo->text();
    QString BagNo = ui->txtBagNo->text();




    if(!myDB.isOpen()){
        qDebug()<<"No connection to db : (";
        return;
    }
    QSqlQuery qry(myDB);
    if (qry.exec("SELECT EnrollNo,BagNo FROM LaundryVer WHERE EnrollNo='" + ENo + "' AND BagNo='" + BagNo + "'")) {
        if (qry.next()) {
            QString msg = "Welcome User !!";
            QMessageBox::warning(this, "Login was successful", msg);

            //LaundryClothesStd* ptrLaundryClothesStd = new LaundryClothesStd();
            ptrLaundryClothesStd->setValues(ENo, BagNo);
            ptrLaundryClothesStd->show();
            ui->txtENo->setText("");
            ui->txtBagNo->setText("");
        } else {
            QString msg0 = "Try Again !!";
            QMessageBox::warning(this, "Invalid Details", msg0);
        }
    } else {
        qDebug() << "Error executing query:" << qry.lastError().text();
    }



}

