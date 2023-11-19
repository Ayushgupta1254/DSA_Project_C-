#include "laundryclothesstd.h"
#include "ui_laundryclothesstd.h"
#include "databasemanager.h"

LaundryClothesStd::LaundryClothesStd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LaundryClothesStd)
{
    ui->setupUi(this);

    QString databasePath = "C:/Users/rahul/OneDrive/Documents/DSA_Project/database/DSAProject.db";
    QString connectionName = "LaundryClothesStdConnection";

    myDB = DatabaseManager::getDatabase(databasePath,connectionName);

    if (!myDB.isOpen()) {
        qDebug() << "Error opening database:" << myDB.lastError().text();

    } else {
        qDebug() << "Database opened successfully!";

    }

    ui->txtEnrollNo->setReadOnly(true);
    ui->txtBagNo->setReadOnly(true);

}

LaundryClothesStd::~LaundryClothesStd()
{
    delete ui;
}


void LaundryClothesStd::setValues(const QString& enroll, const QString& bag) {
    ui->txtEnrollNo->setText(enroll);
    ui->txtBagNo->setText(bag);
}


void LaundryClothesStd::on_btnSubmit_clicked()
{
    QString Enroll = ui->txtEnrollNo->text();
    QString BagNo = ui->txtBagNo->text();
    QString Date = ui->txtDate->text();
    QString Kurta = ui->txtKurta->text();
    QString Pajama = ui->txtPajama->text();
    QString Shirt = ui->txtShirt->text();
    QString TShirt = ui->txtTShirt->text();
    QString Pant = ui->txtPant->text();
    QString Lower = ui->txtLower->text();
    QString Shorts = ui->txtShorts->text();
    QString Bedsheet = ui->txtBedsheet->text();
    QString PillowCover = ui->txtPillowCover->text();
    QString Towel = ui->txtTowel->text();




    if(!myDB.isOpen()){
        qDebug()<<"No connection to db : (";
        return;
    }
    QSqlQuery qry(myDB);


    qry.prepare("INSERT INTO LaundryClothes (EnrollNo,BagNo,Date,Kurta, Pajama, Shirt, TShirt, Pant, Lower, Shorts, Bedsheet, PillowCover,Towel) VALUES (? ,? ,? ,?, ?, ?, ?,? ,? ,? ,? ,? ,? )");

    qry.addBindValue(Enroll);
    qry.addBindValue(BagNo);
    qry.addBindValue(Date);
    qry.addBindValue(Kurta);
    qry.addBindValue(Pajama);
    qry.addBindValue(Shirt);
    qry.addBindValue(TShirt);
    qry.addBindValue(Pant);
    qry.addBindValue(Lower);
    qry.addBindValue(Shorts);
    qry.addBindValue(Bedsheet);
    qry.addBindValue(PillowCover);
    qry.addBindValue(Towel);

    if (qry.exec()) {
        QString msg0 = "Laundry Uploaded !!";
        QMessageBox::warning(this, "Success", msg0);


        ui->txtKurta->setText("");
        ui->txtKurta->setText("");
        ui->txtPajama->setText("");
        ui->txtShirt->setText("");
        ui->txtTShirt->setText("");
        ui->txtPant->setText("");
        ui->txtLower->setText("");
        ui->txtShorts->setText("");
        ui->txtBedsheet->setText("");
        ui->txtPillowCover->setText("");
        ui->txtTowel->setText("");
        ui->txtCart->setText("");
        ui->txtDate->setText("");


        hide();


    } else {
        qDebug() << "Error executing query:" << qry.lastError().text();
    }

    qry.finish();

    myDB.close();

    qDebug() << "Database connection closed.";


}


void LaundryClothesStd::on_btncart_clicked()
{
    QString Enroll = ui->txtEnrollNo->text();
    QString BagNo = ui->txtBagNo->text();
    QString Kurta = ui->txtKurta->text();
    QString Pajama = ui->txtPajama->text();
    QString Shirt = ui->txtShirt->text();
    QString TShirt = ui->txtTShirt->text();
    QString Pant = ui->txtPant->text();
    QString Lower = ui->txtLower->text();
    QString Shorts = ui->txtShorts->text();
    QString Bedsheet = ui->txtBedsheet->text();
    QString PillowCover = ui->txtPillowCover->text();
    QString Towel = ui->txtTowel->text();

    int totalClothes = Kurta.toInt() + Pajama.toInt() + Shirt.toInt() + TShirt.toInt() +
                       Pant.toInt() + Lower.toInt() + Shorts.toInt() + Bedsheet.toInt() +
                       PillowCover.toInt() + Towel.toInt();

    if (totalClothes > 10) {
        QMessageBox::warning(this, "Error", "Total number of clothes cannot exceed 10. Please reduce the quantity.");
        ui->btnSubmit->setEnabled(false);
        return;
    }
    else{

        ui->txtCart->setText(QString::number(totalClothes));
        ui->btnSubmit->setEnabled(true);
    }
}

