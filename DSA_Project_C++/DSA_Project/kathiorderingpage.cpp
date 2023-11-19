#include "kathiorderingpage.h"
#include "ui_kathiorderingpage.h"
#include <QCheckBox>
#include <iostream>
#include <ctime>
#include <chrono>
#include "databasemanager.h"


using namespace std;

KathiOrderingPage::KathiOrderingPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KathiOrderingPage)
{
    ui->setupUi(this);


    Fries = 50;
    Chole_Bhature = 70;
    Chicken_Fries = 200;
    Panner_Roll = 100;
    Honey_Chili = 100;
    Burger = 70;
    Chicken_Roll = 180;
    Pav_Bhaji = 130;
    Momo = 60;
    Fried_Rice = 90;
    Hash_Brown = 80;
    Ice_Cream = 50;
    Muffin = 40;
    Pastry = 70;
    Milk_Shake = 120;
    Tea = 20;
    Coffee = 30;
    Cola = 40;
    Water = 25;

    ui->txtEnroll->setReadOnly(true);
    ui->btnOrder->setEnabled(false);

}

KathiOrderingPage::~KathiOrderingPage()
{
    //delete ptrKathiOrderingPage;
    delete ui;
}

void KathiOrderingPage::setEnrolledUsername(const QString& username)
{
    ui->txtEnroll->setText(username);

}

void KathiOrderingPage::on_ckbFries_stateChanged(int arg1)
{

    if(ui->ckbFries->isChecked() == true){
        ui->txtFries->setEnabled(true);
    }
    else{
        ui->txtFries->setEnabled(false);
        ui->txtFries->setText("0");
    }
}




void KathiOrderingPage::on_ckbCholeBhature_stateChanged(int arg1)
{
    if(ui->ckbCholeBhature->isChecked() == true){
        ui->txtCholeBhature->setEnabled(true);
    }
    else{
        ui->txtCholeBhature->setEnabled(false);
        ui->txtCholeBhature->setText("0");
    }
}




void KathiOrderingPage::on_ckbChickenFries_stateChanged(int arg1)
{
    if(ui->ckbChickenFries->isChecked() == true){
        ui->txtChickenFries->setEnabled(true);
    }
    else{
        ui->txtChickenFries->setEnabled(false);
        ui->txtChickenFries->setText("0");
    }
}



void KathiOrderingPage::on_ckbPannerRoll_stateChanged(int arg1)
{
    if(ui->ckbPannerRoll->isChecked() == true){
        ui->txtPannerRoll->setEnabled(true);
    }
    else{
        ui->txtPannerRoll->setEnabled(false);
        ui->txtPannerRoll->setText("0");
    }
}


void KathiOrderingPage::on_ckbHoneyChili_stateChanged(int arg1)
{
    if(ui->ckbHoneyChili->isChecked() == true){
        ui->txtHoneyChili->setEnabled(true);
    }
    else{
        ui->txtHoneyChili->setEnabled(false);
        ui->txtHoneyChili->setText("0");
    }
}


void KathiOrderingPage::on_ckbBurger_stateChanged(int arg1)
{
    if(ui->ckbBurger->isChecked() == true){
        ui->txtBurger->setEnabled(true);
    }
    else{
        ui->txtBurger->setEnabled(false);
        ui->txtBurger->setText("0");
    }
}


void KathiOrderingPage::on_ckbChickenRoll_stateChanged(int arg1)
{
    if(ui->ckbChickenRoll->isChecked() == true){
        ui->txtChickenRoll->setEnabled(true);
    }
    else{
        ui->txtChickenRoll->setEnabled(false);
        ui->txtChickenRoll->setText("0");
    }
}





void KathiOrderingPage::on_ckbHashBrown_stateChanged(int arg1)
{
    if(ui->ckbHashBrown->isChecked() == true){
        ui->txtHashBrown->setEnabled(true);
    }
    else{
        ui->txtHashBrown->setEnabled(false);
        ui->txtHashBrown->setText("0");
    }
}





void KathiOrderingPage::on_ckbIceCream_stateChanged(int arg1)
{
    if(ui->ckbIceCream->isChecked() == true){
        ui->txtIceCream->setEnabled(true);
    }
    else{
        ui->txtIceCream->setEnabled(false);
        ui->txtIceCream->setText("0");
    }
}




void KathiOrderingPage::on_ckbMuffin_stateChanged(int arg1)
{
    if(ui->ckbMuffin->isChecked() == true){
        ui->txtMuffin->setEnabled(true);
    }
    else{
        ui->txtMuffin->setEnabled(false);
        ui->txtMuffin->setText("0");
    }
}





void KathiOrderingPage::on_ckbPastry_stateChanged(int arg1)
{
    if(ui->ckbPastry->isChecked() == true){
        ui->txtPastry->setEnabled(true);
    }
    else{
        ui->txtPastry->setEnabled(false);
        ui->txtPastry->setText("0");
    }
}




void KathiOrderingPage::on_ckbMilkShake_stateChanged(int arg1)
{
    if(ui->ckbMilkShake->isChecked() == true){
        ui->txtMilkShake->setEnabled(true);
    }
    else{
        ui->txtMilkShake->setEnabled(false);
        ui->txtMilkShake->setText("0");
    }
}





void KathiOrderingPage::on_ckbPavBhaji_stateChanged(int arg1)
{
    if(ui->ckbPavBhaji->isChecked() == true){
        ui->txtPavBhaji->setEnabled(true);
    }
    else{
        ui->txtPavBhaji->setEnabled(false);
        ui->txtPavBhaji->setText("0");
    }
}





void KathiOrderingPage::on_ckbMomo_stateChanged(int arg1)
{
    if(ui->ckbMomo->isChecked() == true){
        ui->txtMomo->setEnabled(true);
    }
    else{
        ui->txtMomo->setEnabled(false);
        ui->txtMomo->setText("0");
    }
}




void KathiOrderingPage::on_ckbTea_stateChanged(int arg1)
{
    if(ui->ckbTea->isChecked() == true){
        ui->txtTea->setEnabled(true);
    }
    else{
        ui->txtTea->setEnabled(false);
        ui->txtTea->setText("0");
    }
}




void KathiOrderingPage::on_ckbCoffee_stateChanged(int arg1)
{
    if(ui->ckbCoffee->isChecked() == true){
        ui->txtCoffee->setEnabled(true);
    }
    else{
        ui->txtCoffee->setEnabled(false);
        ui->txtCoffee->setText("0");
    }
}




void KathiOrderingPage::on_ckbCola_stateChanged(int arg1)
{
    if(ui->ckbCola->isChecked() == true){
        ui->txtCola->setEnabled(true);
    }
    else{
        ui->txtCola->setEnabled(false);
        ui->txtCola->setText("0");
    }
}




void KathiOrderingPage::on_ckbWater_stateChanged(int arg1)
{
    if(ui->ckbWater->isChecked() == true){
        ui->txtWater->setEnabled(true);
    }
    else{
        ui->txtWater->setEnabled(false);
        ui->txtWater->setText("0");
    }
}


void KathiOrderingPage::on_ckbFriedRice_stateChanged(int arg1)
{
    if(ui->ckbFriedRice->isChecked() == true){
        ui->txtFriedRice->setEnabled(true);
    }
    else{
        ui->txtFriedRice->setEnabled(false);
        ui->txtFriedRice->setText("0");
    }
}


void KathiOrderingPage::on_btnReset_clicked()
{
    ui->ckbFries->setEnabled(true);
    ui->ckbCholeBhature->setEnabled(true);
    ui->ckbChickenFries->setEnabled(true);
    ui->ckbPannerRoll->setEnabled(true);
    ui->ckbHoneyChili->setEnabled(true);
    ui->ckbBurger->setEnabled(true);
    ui->ckbChickenRoll->setEnabled(true);
    ui->ckbPavBhaji->setEnabled(true);
    ui->ckbMomo->setEnabled(true);
    ui->ckbFriedRice->setEnabled(true);
    ui->ckbHashBrown->setEnabled(true);
    ui->ckbIceCream->setEnabled(true);
    ui->ckbMuffin->setEnabled(true);
    ui->ckbPastry->setEnabled(true);
    ui->ckbMilkShake->setEnabled(true);
    ui->ckbTea->setEnabled(true);
    ui->ckbCoffee->setEnabled(true);
    ui->ckbCola->setEnabled(true);
    ui->ckbWater->setEnabled(true);

    ui->ckbFries->setChecked(false);
    ui->ckbCholeBhature->setChecked(false);
    ui->ckbChickenFries->setChecked(false);
    ui->ckbPannerRoll->setChecked(false);
    ui->ckbHoneyChili->setChecked(false);
    ui->ckbBurger->setChecked(false);
    ui->ckbChickenRoll->setChecked(false);
    ui->ckbPavBhaji->setChecked(false);
    ui->ckbMomo->setChecked(false);
    ui->ckbFriedRice->setChecked(false);
    ui->ckbHashBrown->setChecked(false);
    ui->ckbIceCream->setChecked(false);
    ui->ckbMuffin->setChecked(false);
    ui->ckbPastry->setChecked(false);
    ui->ckbMilkShake->setChecked(false);
    ui->ckbTea->setChecked(false);
    ui->ckbCoffee->setChecked(false);
    ui->ckbCola->setChecked(false);
    ui->ckbWater->setChecked(false);


    ui->txtFries->setText("");
    ui->txtCholeBhature->setText("");
    ui->txtChickenFries->setText("");
    ui->txtPannerRoll->setText("");
    ui->txtHoneyChili->setText("");
    ui->txtBurger->setText("");
    ui->txtChickenRoll->setText("");
    ui->txtPavBhaji->setText("");
    ui->txtMomo->setText("");
    ui->txtFriedRice->setText("");
    ui->txtHashBrown->setText("");
    ui->txtIceCream->setText("");
    ui->txtMuffin->setText("");
    ui->txtPastry->setText("");
    ui->txtMilkShake->setText("");
    ui->txtTea->setText("");
    ui->txtCoffee->setText("");
    ui->txtCola->setText("");
    ui->txtWater->setText("");
    ui->txtTotal->setText("");

    Total = 0;

    ui->listForBill->clear();

    ui->pushButton->setEnabled(true);

}

void KathiOrderingPage::on_btnTotal_clicked()
{
    double itemCost[19];

    itemCost[0] = ui->txtFries->text().toDouble() * Fries;
    itemCost[1] = ui->txtCholeBhature->text().toDouble() * Chole_Bhature;
    itemCost[2] = ui->txtChickenFries->text().toDouble() * Chicken_Fries;
    itemCost[3] = ui->txtPannerRoll->text().toDouble() * Panner_Roll;
    itemCost[4] = ui->txtHoneyChili->text().toDouble() * Honey_Chili;
    itemCost[5] = ui->txtBurger->text().toDouble() * Burger;
    itemCost[6] = ui->txtChickenRoll->text().toDouble() * Chicken_Roll;
    itemCost[7] = ui->txtPavBhaji->text().toDouble() * Pav_Bhaji;
    itemCost[8] = ui->txtMomo->text().toDouble() * Momo;
    itemCost[9] = ui->txtFriedRice->text().toDouble() * Fried_Rice;
    itemCost[10] = ui->txtHashBrown->text().toDouble() * Hash_Brown;
    itemCost[11] = ui->txtIceCream->text().toDouble() * Ice_Cream;
    itemCost[12] = ui->txtMuffin->text().toDouble() * Muffin;
    itemCost[13] = ui->txtPastry->text().toDouble() * Pastry;
    itemCost[14] = ui->txtMilkShake->text().toDouble() * Milk_Shake;
    itemCost[15] = ui->txtTea->text().toDouble() * Tea;
    itemCost[16] = ui->txtCoffee->text().toDouble() * Coffee;
    itemCost[17] = ui->txtCola->text().toDouble() * Cola;
    itemCost[18] = ui->txtWater->text().toDouble() * Water;

    Total = itemCost[0]+itemCost[1]+itemCost[2]+itemCost[3]+itemCost[4]+itemCost[5]+itemCost[6]+itemCost[7]+itemCost[8]+itemCost[9]
            +itemCost[10]+itemCost[11]+itemCost[12]+itemCost[13]+itemCost[14]+itemCost[15]+itemCost[16]+itemCost[17]+itemCost[18];

    ui->txtTotal->setText(QString::number(Total));
}


void KathiOrderingPage::on_pushButton_clicked()
{
    auto currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%H:%M:%S", localtime(&currentTime));
    string currentTimeString(buffer);
    ui->txtTime->setText(buffer) ;

    QString qCurrentTimeString = QString::fromStdString(currentTimeString);

    ui->listForBill->addItem("-----------------------------------------------------");
    ui->listForBill->addItem("-----------------------BILL--------------------------");
    ui->listForBill->addItem("-----------------------------------------------------");
    QString EnrollNolst = "Enrollment No. :--> "+ui->txtEnroll->text() ;
    ui->listForBill->addItem(EnrollNolst);
    QString Date = "Date :---> "+ui->txtDate->text();
    ui->listForBill->addItem(Date);
    QString Time = "Time : ---> "+qCurrentTimeString;
    ui->listForBill->addItem(Time);
    ui->listForBill->addItem("-----------------------------------------------------");


    if(ui->ckbFries->isChecked() == true){
        double FriesPrice =ui->txtFries->text().toDouble() * Fries;
        QString FriesPricetxt = QString::number(FriesPrice);
        QString lsttxtFries = "Fries :- Rs.50   Quantity :" + ui->txtFries->text() +"-->"+FriesPricetxt;
        ui->listForBill->addItem(lsttxtFries);
    }


    if(ui->ckbCholeBhature->isChecked() == true){
        double Chole_BhaturePrice =ui->txtCholeBhature->text().toDouble() * Chole_Bhature;
        QString Chole_BhaturePricetxt = QString::number(Chole_BhaturePrice);
        QString lstChole_Bhature = "Chole-Bhature :- Rs.70   Quantity :" + ui->txtCholeBhature->text() +"-->"+Chole_BhaturePricetxt;
        ui->listForBill->addItem(lstChole_Bhature);
    }

    if(ui->ckbChickenFries->isChecked() == true){
        double ChickenFriesPrice =ui->txtChickenFries->text().toDouble() * Chicken_Fries;
        QString ChickenFriesPricetxt = QString::number(ChickenFriesPrice);
        QString lstChickenFries = "Chicken-Fries :- Rs.200   Quantity :" + ui->txtChickenFries->text() +"-->"+ChickenFriesPricetxt;
        ui->listForBill->addItem(lstChickenFries);
    }

    if(ui->ckbPannerRoll->isChecked() == true){
        double PannerRollPrice =ui->txtPannerRoll->text().toDouble() * Panner_Roll;
        QString PannerRollPricetxt = QString::number(PannerRollPrice);
        QString lstPannerRoll = "Panner-Roll :- Rs.100   Quantity :" + ui->txtPannerRoll->text() +"-->"+PannerRollPricetxt;
        ui->listForBill->addItem(lstPannerRoll);
    }

    if(ui->ckbHoneyChili->isChecked() == true){
        double HoneyChiliPrice =ui->txtHoneyChili->text().toDouble() * Honey_Chili;
        QString HoneyChiliPricetxt = QString::number(HoneyChiliPrice);
        QString lstHoneyChili = "Honey-Chili :- Rs.100   Quantity :" + ui->txtHoneyChili->text() +"-->"+HoneyChiliPricetxt;
        ui->listForBill->addItem(lstHoneyChili);
    }

    if(ui->ckbBurger->isChecked() == true){
        double BurgerPrice =ui->txtBurger->text().toDouble() * Burger;
        QString BurgerPricetxt = QString::number(BurgerPrice);
        QString lstBurger = "Burger :- Rs.70   Quantity :" + ui->txtBurger->text() +"-->"+BurgerPricetxt;
        ui->listForBill->addItem(lstBurger);
    }

    if(ui->ckbChickenRoll->isChecked() == true){
        double ChickenRollPrice =ui->txtChickenRoll->text().toDouble() * Chicken_Roll;
        QString ChickenRollPricetxt = QString::number(ChickenRollPrice);
        QString lstChickenRoll = "Chicken-Roll :- Rs.180   Quantity :" + ui->txtChickenRoll->text() +"-->"+ChickenRollPricetxt;
        ui->listForBill->addItem(lstChickenRoll);
    }

    if(ui->ckbPavBhaji->isChecked() == true){
        double PavBhajiPrice =ui->txtPavBhaji->text().toDouble() * Pav_Bhaji;
        QString PavBhajiPricetxt = QString::number(PavBhajiPrice);
        QString lstPavBhaji = "Pav-Bhaji :- Rs.130   Quantity :" + ui->txtPavBhaji->text() +"-->"+PavBhajiPricetxt;
        ui->listForBill->addItem(lstPavBhaji);
    }

    if(ui->ckbMomo->isChecked() == true){
        double MomoPrice =ui->txtMomo->text().toDouble() * Momo;
        QString MomoPricetxt = QString::number(MomoPrice);
        QString lstMomo = "Fries :- Rs.60   Quantity :" + ui->txtMomo->text() +"-->"+MomoPricetxt;
        ui->listForBill->addItem(lstMomo);
    }


    if(ui->ckbFriedRice->isChecked() == true){
        double FriedRicePrice =ui->txtFriedRice->text().toDouble() * Fried_Rice;
        QString FriedRicePricetxt = QString::number(FriedRicePrice);
        QString lstFriedRice = "Fried-Rice :- Rs.90   Quantity :" + ui->txtFriedRice->text() +"-->"+FriedRicePricetxt;
        ui->listForBill->addItem(lstFriedRice);
    }


    if(ui->ckbHashBrown->isChecked() == true){
        double HashBrownPrice =ui->txtHashBrown->text().toDouble() * Hash_Brown;
        QString HashBrownPricetxt = QString::number(HashBrownPrice);
        QString lstHashBrown = "Hash-Brown :- Rs.80   Quantity :" + ui->txtHashBrown->text() +"-->"+HashBrownPricetxt;
        ui->listForBill->addItem(lstHashBrown);
    }


    if(ui->ckbIceCream->isChecked() == true){
        double IceCreamPrice =ui->txtIceCream->text().toDouble() * Ice_Cream;
        QString IceCreamPricetxt = QString::number(IceCreamPrice);
        QString lstIceCream = "Ice-Cream :- Rs.50   Quantity :" + ui->txtIceCream->text() +"-->"+IceCreamPricetxt;
        ui->listForBill->addItem(lstIceCream);
    }


    if(ui->ckbMuffin->isChecked() == true){
        double MuffinPrice =ui->txtMuffin->text().toDouble() * Muffin;
        QString MuffinPricetxt = QString::number(MuffinPrice);
        QString lstMuffin = "Muffin :- Rs.40   Quantity :" + ui->txtMuffin->text() +"-->"+MuffinPricetxt;
        ui->listForBill->addItem(lstMuffin);
    }


    if(ui->ckbPastry->isChecked() == true){
        double PastryPrice =ui->txtPastry->text().toDouble() * Pastry;
        QString PastryPricetxt = QString::number(PastryPrice);
        QString lstPastry = "Pastry :- Rs.70   Quantity :" + ui->txtPastry->text() +"-->"+PastryPricetxt;
        ui->listForBill->addItem(lstPastry);
    }


    if(ui->ckbMilkShake->isChecked() == true){
        double MilkShakePrice =ui->txtMilkShake->text().toDouble() * Milk_Shake;
        QString MilkShakePricetxt = QString::number(MilkShakePrice);
        QString lstMilkShake = "MilkShake :- Rs.120   Quantity :" + ui->txtMilkShake->text() +"-->"+MilkShakePricetxt;
        ui->listForBill->addItem(lstMilkShake);
    }


    if(ui->ckbTea->isChecked() == true){
        double TeaPrice =ui->txtTea->text().toDouble() * Tea;
        QString TeaPricetxt = QString::number(TeaPrice);
        QString lstTea = "Tea :- Rs.20   Quantity :" + ui->txtTea->text() +"-->"+TeaPricetxt;
        ui->listForBill->addItem(lstTea);
    }

    if(ui->ckbCoffee->isChecked() == true){
        double CoffeePrice =ui->txtCoffee->text().toDouble() * Coffee;
        QString CoffeePricetxt = QString::number(CoffeePrice);
        QString lstCoffee = "Coffee :- Rs.30   Quantity :" + ui->txtCoffee->text() +"-->"+CoffeePricetxt;
        ui->listForBill->addItem(lstCoffee);
    }


    if(ui->ckbCola->isChecked() == true){
        double ColaPrice =ui->txtCola->text().toDouble() * Cola;
        QString ColaPricetxt = QString::number(ColaPrice);
        QString lstCola = "Cola :- Rs.40   Quantity :" + ui->txtCola->text() +"-->"+ColaPricetxt;
        ui->listForBill->addItem(lstCola);
    }


    if(ui->ckbWater->isChecked() == true){
        double WaterPrice =ui->txtWater->text().toDouble() * Water;
        QString WaterPricetxt = QString::number(WaterPrice);
        QString lstWater = "Water :- Rs.25   Quantity :" + ui->txtWater->text() +"-->"+WaterPricetxt;
        ui->listForBill->addItem(lstWater);
    }

    ui->listForBill->addItem("---------------------------------------------------------");
    QString Totaltxt = QString::number(Total);
    QString lstTotal = "Total :- "+Totaltxt;
    ui->listForBill->addItem(lstTotal);
    ui->listForBill->addItem("----------------------------------------------------------");
    ui->listForBill->addItem("Thank-You");

    //ui->pushButton->setEnabled(false);
    ui->btnOrder->setEnabled(true);


}


void KathiOrderingPage::on_btnOrder_clicked()
{
    QString EnrollNo = ui->txtEnroll->text();
    QString Date = ui->txtDate->text();
    QString Time = ui->txtTime->text();
    QString Fries = ui->txtFries->text();
    QString CholeBhature = ui->txtCholeBhature->text();
    QString ChickenFries = ui->txtChickenFries->text();
    QString PannerRoll = ui->txtPannerRoll->text();
    QString HoneyChilli = ui->txtHoneyChili->text();
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


    if (!myDB.isOpen()) {
        myDB = DatabaseManager::getDatabase("C:/Users/rahul/OneDrive/Documents/DSA_Project/database/DSAProject.db", "StdOrderConnection");

        if (!myDB.isOpen()) {
            qDebug() << "Error opening database:" << myDB.lastError().text();
            return;
        }
    }

    QSqlQuery qry(myDB);

    qry.prepare("INSERT INTO KathiOrder (EnrollNo, Date, Time, Fries, CholeBhature, ChickenFries, PannerRoll, HoneyChilli, Burger, ChickenRoll, PavBhaji, Momo, FriedRice, HashBrown, IceCream, Muffin, Pastry, MilkShake, Tea, Coffee, Cola, Water, TotalM) "
                "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

    qry.addBindValue(EnrollNo);
    qry.addBindValue(Date);
    qry.addBindValue(Time);
    qry.addBindValue(Fries);
    qry.addBindValue(CholeBhature);
    qry.addBindValue(ChickenFries);
    qry.addBindValue(PannerRoll);
    qry.addBindValue(HoneyChilli);
    qry.addBindValue(Burger);
    qry.addBindValue(ChickenRoll);
    qry.addBindValue(PavBhaji);
    qry.addBindValue(Momo);
    qry.addBindValue(FriedRice);
    qry.addBindValue(HashBrown);
    qry.addBindValue(IceCream);
    qry.addBindValue(Muffin);
    qry.addBindValue(Pastry);
    qry.addBindValue(MilkShake);
    qry.addBindValue(Tea);
    qry.addBindValue(Coffe);
    qry.addBindValue(Cola);
    qry.addBindValue(Water);
    qry.addBindValue(Total);

    if (qry.exec()) {
        qDebug() << "Data inserted successfully!";
        QString msg = "Order Placed !!";
        QMessageBox::warning(this,"Success",msg);
    } else {
        qDebug() << "Error executing query:" << qry.lastError().text();
    }

    myDB.close();

}

