#include "adminverlaundry.h"
#include "ui_adminverlaundry.h"
#include "databasemanager.h"

AdminVerLaundry::AdminVerLaundry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminVerLaundry)
{
    ui->setupUi(this);

//    QString databasePath = "C:/Users/rahul/OneDrive/Documents/DSA_Project/database/DSAProject.db";
//    QString connectionName = "AdminVerLaundryConnection";

//    myDB = DatabaseManager::getDatabase(databasePath,connectionName);

//    if (!myDB.isOpen()) {
//        qDebug() << "Error opening database:" << myDB.lastError().text();

//    } else {
//        qDebug() << "Database opened successfully!";

//    }

}

AdminVerLaundry::~AdminVerLaundry()
{
    delete ui;
    myDB.close();
}




void AdminVerLaundry::on_btnSearch_clicked()
{
    QString EnrollVer = ui->txtEnrollNoVer->text();
    QString BagNoVer = ui->txtBagNoVer->text();
    QString DateVer = ui->txtDateVer->text();


    if (!myDB.isOpen()) {
        myDB = DatabaseManager::getDatabase("C:/Users/rahul/OneDrive/Documents/DSA_Project/database/DSAProject.db", "AdminVerLaundryConnection");

        if (!myDB.isOpen()) {
            qDebug() << "Error opening database:" << myDB.lastError().text();
            return;
        }
    }

    QSqlQuery qry(myDB);
    if (qry.exec("SELECT * FROM LaundryClothes WHERE EnrollNo='" + EnrollVer + "' AND BagNo='" + BagNoVer + "' AND Date='" + DateVer + "'")) {
        if (qry.next()) {
            ui->txtKurtaVer->setText(qry.value("Kurta").toString());
            ui->txtPajamaVer->setText(qry.value("Pajama").toString());
            ui->txtShirtVer->setText(qry.value("Shirt").toString());
            ui->txtTShirtVer->setText(qry.value("TShirt").toString());
            ui->txtPantVer->setText(qry.value("Pant").toString());
            ui->txtLowerVer->setText(qry.value("Lower").toString());
            ui->txtShortsVer->setText(qry.value("Shorts").toString());
            ui->txtBedsheetVer->setText(qry.value("Bedsheet").toString());
            ui->txtPillowCVer->setText(qry.value("PillowCover").toString());
            ui->txtTowelVer->setText(qry.value("Towel").toString());
        } else {
            qDebug() << "No matching record found.";
            QString msg = "No Record Found !!";
            QMessageBox::warning(this, "Invalid", msg);
        }
    } else {
        qDebug() << "Error executing query:" << qry.lastError().text();
    }

    //myDB.close();
}


void AdminVerLaundry::on_pushButton_clicked()
{
    QString EnrollVer = ui->txtEnrollNoVer->text();
    QString BagNoVer = ui->txtBagNoVer->text();
    QString DateVer = ui->txtDateVer->text();

    QString Kurta = ui->txtKurtaVer->text();
    QString Pajama = ui->txtPajamaVer->text();
    QString Shirt = ui->txtShirtVer->text();
    QString TShirt = ui->txtTShirtVer->text();
    QString Pant = ui->txtPantVer->text();
    QString Lower = ui->txtLowerVer->text();
    QString Shorts = ui->txtShortsVer->text();
    QString Bedsheet = ui->txtBedsheetVer->text();
    QString PillowCover = ui->txtPillowCVer->text();
    QString Towel = ui->txtTowelVer->text();
    QString Verify = ui->txtVerify->text();

    if (!myDB.isOpen()) {
        myDB = DatabaseManager::getDatabase("C:/Users/rahul/OneDrive/Documents/DSA_Project/database/DSAProject.db", "AdminVerLaundryConnection");

        if (!myDB.isOpen()) {
            qDebug() << "Error opening database:" << myDB.lastError().text();
            return;
        }
    }

    QSqlQuery updateQuery(myDB);
    updateQuery.prepare("UPDATE LaundryClothes SET Kurta = :kurta, Pajama = :pajama, Shirt = :shirt, TShirt = :tshirt, "
                        "Pant = :pant, Lower = :lower, Shorts = :shorts, Bedsheet = :bedsheet, PillowCover = :pillowcover, Towel = :towel, Verified = :verified "
                        "WHERE EnrollNo = :enroll AND BagNo = :bag AND Date = :date");

    updateQuery.bindValue(":enroll", EnrollVer);
    updateQuery.bindValue(":bag", BagNoVer);
    updateQuery.bindValue(":date", DateVer);
    updateQuery.bindValue(":kurta", Kurta);
    updateQuery.bindValue(":pajama", Pajama);
    updateQuery.bindValue(":shirt", Shirt);
    updateQuery.bindValue(":tshirt", TShirt);
    updateQuery.bindValue(":pant", Pant);
    updateQuery.bindValue(":lower", Lower);
    updateQuery.bindValue(":shorts", Shorts);
    updateQuery.bindValue(":bedsheet", Bedsheet);
    updateQuery.bindValue(":pillowcover", PillowCover);
    updateQuery.bindValue(":towel", Towel);
    updateQuery.bindValue(":verified",Verify);

    if (updateQuery.exec()) {
        qDebug() << "Record updated successfully!";

        QString msg = "Verified !!";
        QMessageBox::warning(this, "Success", msg);

        ui->txtEnrollNoVer->setText("");
        ui->txtBagNoVer->setText("");
        ui->txtDateVer->setText("");
        ui->txtKurtaVer->setText("");
        ui->txtPajamaVer->setText("");
        ui->txtShirtVer->setText("");
        ui->txtTShirtVer->setText("");
        ui->txtPantVer->setText("");
        ui->txtLowerVer->setText("");
        ui->txtShortsVer->setText("");
        ui->txtBedsheetVer->setText("");
        ui->txtPillowCVer->setText("");
        ui->txtTowelVer->setText("");
        ui->txtVerify->setText("");
    } else {
        qDebug() << "Error updating record:" << updateQuery.lastError().text();
    }

    //myDB.close();
}

