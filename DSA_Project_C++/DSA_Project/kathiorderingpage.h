#ifndef KATHIORDERINGPAGE_H
#define KATHIORDERINGPAGE_H

#include <QDialog>
#include <QCheckBox>
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QDebug>
#include <QSqlTableModel>
#include <QFileInfo>
#include <QtSql>
#include <QMessageBox>
#include "ui_kathiorderingpage.h"
#include "databasemanager.h"

namespace Ui {
class KathiOrderingPage;
}

class KathiOrderingPage : public QDialog
{
    Q_OBJECT

public:
    explicit KathiOrderingPage(QWidget *parent = nullptr);
    ~KathiOrderingPage();
    void setEnrolledUsername(const QString& username);

private slots:
    void on_ckbFries_stateChanged(int arg1);

    void on_ckbCholeBhature_stateChanged(int arg1);

    void on_ckbChickenFries_stateChanged(int arg1);

    void on_ckbPannerRoll_stateChanged(int arg1);

    void on_ckbHoneyChili_stateChanged(int arg1);

    void on_ckbBurger_stateChanged(int arg1);

    void on_ckbChickenRoll_stateChanged(int arg1);

    void on_ckbHashBrown_stateChanged(int arg1);

    void on_ckbIceCream_stateChanged(int arg1);

    void on_ckbMuffin_stateChanged(int arg1);

    void on_ckbPastry_stateChanged(int arg1);

    void on_ckbMilkShake_stateChanged(int arg1);

    void on_ckbPavBhaji_stateChanged(int arg1);

    void on_ckbMomo_stateChanged(int arg1);

    void on_ckbTea_stateChanged(int arg1);

    void on_ckbCoffee_stateChanged(int arg1);

    void on_ckbCola_stateChanged(int arg1);

    void on_ckbWater_stateChanged(int arg1);

    void on_ckbFriedRice_stateChanged(int arg1);

    void on_btnReset_clicked();

    //void on_pushButton_clicked();

    void on_btnTotal_clicked();

    void on_pushButton_clicked();

    void on_btnOrder_clicked();

private:
    Ui::KathiOrderingPage *ui;

    QSqlDatabase myDB;

    double Fries ;
    double Chole_Bhature ;
    double Chicken_Fries ;
    double Panner_Roll;
    double Honey_Chili ;
    double Burger ;
    double Chicken_Roll ;
    double Pav_Bhaji ;
    double Momo ;
    double Fried_Rice ;
    double Hash_Brown ;
    double Ice_Cream;
    double Muffin ;
    double Pastry ;
    double Milk_Shake ;
    double Tea ;
    double Coffee ;
    double Cola ;
    double Water ;
    double Total;
};

#endif // KATHIORDERINGPAGE_H
