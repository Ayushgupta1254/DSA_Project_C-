#include "kathiadminpendingorder.h"
#include "ui_kathiadminpendingorder.h"

KathiAdminPendingOrder::KathiAdminPendingOrder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KathiAdminPendingOrder)
{
    ui->setupUi(this);


    ui->txtEnrollNo->setReadOnly(true);
    ui->txtDate->setReadOnly(true);
    ui->txtTime->setReadOnly(true);
    ui->txtFries->setReadOnly(true);
    ui->txtCholeBhature->setReadOnly(true);
    ui->txtChickenFries->setReadOnly(true);
    ui->txtPannerRoll->setReadOnly(true);
    ui->txtHoneyChilli->setReadOnly(true);
    ui->txtBurger->setReadOnly(true);
    ui->txtChickenRoll->setReadOnly(true);
    ui->txtPavBhaji->setReadOnly(true);
    ui->txtMomo->setReadOnly(true);
    ui->txtFriedRice->setReadOnly(true);
    ui->txtHashBrown->setReadOnly(true);
    ui->txtIceCream->setReadOnly(true);
    ui->txtMuffin->setReadOnly(true);
    ui->txtPastry->setReadOnly(true);
    ui->txtMilkShake->setReadOnly(true);
    ui->txtTea->setReadOnly(true);
    ui->txtCoffee->setReadOnly(true);
    ui->txtCola->setReadOnly(true);
    ui->txtWater->setReadOnly(true);
    ui->txtTotal->setReadOnly(true);



}

KathiAdminPendingOrder::~KathiAdminPendingOrder()
{
    delete ui;
    myDB.close();
}

void KathiAdminPendingOrder::on_tableKathiOrderP_clicked(const QModelIndex &index)
{




    if (index.isValid()){
        QVariant dataColumn1 = index.siblingAtColumn(0).data();
        QVariant dataColumn2 = index.siblingAtColumn(1).data();
        QVariant dataColumn3 = index.siblingAtColumn(2).data();
        QVariant dataColumn4 = index.siblingAtColumn(3).data();
        QVariant dataColumn5 = index.siblingAtColumn(4).data();
        QVariant dataColumn6 = index.siblingAtColumn(5).data();
        QVariant dataColumn7 = index.siblingAtColumn(6).data();
        QVariant dataColumn8 = index.siblingAtColumn(7).data();
        QVariant dataColumn9 = index.siblingAtColumn(8).data();
        QVariant dataColumn10 = index.siblingAtColumn(9).data();
        QVariant dataColumn11 = index.siblingAtColumn(10).data();
        QVariant dataColumn12 = index.siblingAtColumn(11).data();
        QVariant dataColumn13 = index.siblingAtColumn(12).data();
        QVariant dataColumn14 = index.siblingAtColumn(13).data();
        QVariant dataColumn15 = index.siblingAtColumn(14).data();
        QVariant dataColumn16 = index.siblingAtColumn(15).data();
        QVariant dataColumn17 = index.siblingAtColumn(16).data();
        QVariant dataColumn18 = index.siblingAtColumn(17).data();
        QVariant dataColumn19 = index.siblingAtColumn(18).data();
        QVariant dataColumn20 = index.siblingAtColumn(19).data();
        QVariant dataColumn21 = index.siblingAtColumn(20).data();
        QVariant dataColumn22 = index.siblingAtColumn(21).data();
        QVariant dataColumn23 = index.siblingAtColumn(22).data();
        QVariant dataColumn24 = index.siblingAtColumn(23).data();


        ui->txtEnrollNo->setText(dataColumn1.toString());
        ui->txtDate->setText(dataColumn2.toString());
        ui->txtTime->setText(dataColumn3.toString());
        ui->txtFries->setText(dataColumn4.toString());
        ui->txtCholeBhature->setText(dataColumn5.toString());
        ui->txtChickenFries->setText(dataColumn6.toString());
        ui->txtPannerRoll->setText(dataColumn7.toString());
        ui->txtHoneyChilli->setText(dataColumn8.toString());
        ui->txtBurger->setText(dataColumn9.toString());
        ui->txtChickenRoll->setText(dataColumn10.toString());
        ui->txtPavBhaji->setText(dataColumn11.toString());
        ui->txtMomo->setText(dataColumn12.toString());
        ui->txtFriedRice->setText(dataColumn13.toString());
        ui->txtHashBrown->setText(dataColumn14.toString());
        ui->txtIceCream->setText(dataColumn15.toString());
        ui->txtMuffin->setText(dataColumn16.toString());
        ui->txtPastry->setText(dataColumn17.toString());
        ui->txtMilkShake->setText(dataColumn18.toString());
        ui->txtTea->setText(dataColumn19.toString());
        ui->txtCoffee->setText(dataColumn20.toString());
        ui->txtCola->setText(dataColumn21.toString());
        ui->txtWater->setText(dataColumn22.toString());
        ui->txtTotal->setText(dataColumn23.toString());
        ui->txtForward->setText(dataColumn24.toString());


    }
}


void KathiAdminPendingOrder::on_pushButton_clicked()
{

    QString DateS = ui->txtDateS->text();



    if (myDB.isOpen()) {
        myDB.close();
    }

    myDB = DatabaseManager::getDatabase("C:/Users/rahul/OneDrive/Documents/DSA_Project/database/DSAProject.db", "KathiAdminPendingSearchConnection");

    if (!myDB.isOpen()) {
        qDebug() << "Error opening database:" << myDB.lastError().text();
        return;
    }




    QTableView *tableView = ui->tableKathiOrderP;

    QSqlTableModel *model = new QSqlTableModel(this, myDB);
    model->setTable("KathiOrder");

    model->setFilter(QString("Date = '%1'").arg(DateS));

    if (model->select()) {
        tableView->setModel(model);
    } else {
        qDebug() << "Error selecting rows:" << model->lastError().text();
    }
}


void KathiAdminPendingOrder::on_pushButton_2_clicked()
{


    QString EnrollNo = ui->txtEnrollNo->text();
    QString Date = ui->txtDate->text();
    QString Time = ui->txtTime->text();
    QString Fries = ui->txtFries->text();
    QString CholeBhature = ui->txtCholeBhature->text();
    QString ChickenFries = ui->txtChickenFries->text();
    QString PannerRoll = ui->txtPannerRoll->text();
    QString HoneyChilli = ui->txtHoneyChilli->text();
    QString Burger = ui->txtBurger->text();
    QString ChickenRoll = ui->txtChickenRoll->text();
    QString PavBhaji = ui->txtPavBhaji->text();
    QString Momo = ui->txtMomo->text();
    QString FriedRice = ui->txtFriedRice->text();
    QString HashBrown = ui->txtHashBrown->text();
    QString IceCream = ui->txtIceCream->text();
    QString Muffin = ui->txtMuffin->text();
    QString Pastry = ui->txtPastry->text();
    QString MilkShake = ui->txtMilkShake->text();
    QString Tea = ui->txtTea->text();
    QString Coffe = ui->txtCoffee->text();
    QString Cola = ui->txtCola->text();
    QString Water = ui->txtWater->text();
    QString Total = ui->txtTotal->text();
    QString Forward = ui->txtForward->text();



    if (!myDB.isOpen()) {
        myDB = DatabaseManager::getDatabase("C:/Users/rahul/OneDrive/Documents/DSA_Project/database/DSAProject.db", "KathiAdminPendingUpdateConnection");

        if (!myDB.isOpen()) {
            qDebug() << "Error opening database:" << myDB.lastError().text();
            return;
        }
    }


    QSqlQuery qry(myDB);

    QString updateQuery = "UPDATE KathiOrder SET "
                          "Fries = '" + Fries + "', "
                          "CholeBhature = '" + CholeBhature + "', "
                          "ChickenFries = '" + ChickenFries + "', "
                          "PannerRoll = '" + PannerRoll + "', "
                          "HoneyChilli = '" + HoneyChilli + "', "
                          "Burger = '" + Burger + "', "
                          "ChickenRoll = '" + ChickenRoll + "', "
                          "PavBhaji = '" + PavBhaji + "', "
                          "Momo = '" + Momo + "', "
                          "FriedRice = '" + FriedRice + "', "
                          "HashBrown = '" + HashBrown + "', "
                          "IceCream = '" + IceCream + "', "
                          "Muffin = '" + Muffin + "', "
                          "Pastry = '" + Pastry + "', "
                          "MilkShake = '" + MilkShake + "', "
                          "Tea = '" + Tea + "', "
                          "Coffee = '" + Coffe + "', "
                          "Cola = '" + Cola + "', "
                          "Water = '" + Water + "', "
                          "TotalM = '" + Total + "', "
                          "Verify = '" + Forward + "' "
                          "WHERE EnrollNo = '" + EnrollNo + "' AND Date = '" + Date + "' AND Time = '" + Time + "'";

    if (qry.exec(updateQuery)) {
        qDebug() << "Update successful!";
    } else {
        qDebug() << "Error updating record:" << qry.lastError().text();
    }

    myDB.close();

}

