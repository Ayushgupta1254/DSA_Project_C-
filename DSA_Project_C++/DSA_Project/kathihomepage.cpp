#include "kathihomepage.h"
#include "ui_kathihomepage.h"
#include "databaseheader.h"
//#include "mainwindow.h"
#include "kathihomepage.h"
#include "kathiorderingpage.h"
#include "databasemanager.h"




#define Path_to_DB "C:/Users/rahul/OneDrive/Documents/DSA_Project/database/DSAProject.db"

KathiHomePage::KathiHomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KathiHomePage)
{
    ui->setupUi(this);

    ptrKathiOrderingPage = new KathiOrderingPage();

    ptrKathiAdminLogin = new KathiAdminLogin();


    QString databasePath = "C:/Users/rahul/OneDrive/Documents/DSA_Project/database/DSAProject.db";
    QString connectionName = "KathiHomePageConnection";

    myDB = DatabaseManager::getDatabase(databasePath, connectionName);

    if (!myDB.isOpen()) {
        qDebug() << "Error opening database:" << myDB.lastError().text();
        ui->lblResult->setText("[!] Unable to open the database :(");
    } else {
        qDebug() << "Database opened successfully!";
        ui->lblResult->setText("[+] Connected to Database File :");
    }



}


KathiHomePage::~KathiHomePage()
{
    DatabaseManager::closeDatabase("KathiHomePageConnection");
    delete ptrKathiOrderingPage;
    delete ui;
    //qDebug()<<"Closing the connection to Database file on exit.";
    //myDB.close();
}



void KathiHomePage::on_pushButton_clicked()
{






    QString Username = ui->txtEnrollmentNo->text();
    QString Password = ui->txtPassword->text();



    if (!myDB.isOpen()) {
        qDebug() << "No connection to db : (";
        return;
    }

    QSqlQuery qry(myDB);
    if (qry.exec("SELECT Username,Password FROM KathiLogin WHERE Username='" + Username + "' AND Password='" + Password + "'")) {
        if (qry.next()) {
            ui->lblResult->setText("[+]Valid Username and password");
            QString msg = "Username = " + qry.value(0).toString();
            QMessageBox::warning(this, "Login was successful", msg);
            loggedInUsername = qry.value(0).toString();


            ptrKathiOrderingPage->show();

            ptrKathiOrderingPage->setEnrolledUsername(loggedInUsername);
            //ptrKathiOrderingPage->txtEnroll->setReadOnly(true);

        } else {
            QString msg0 = "Please Enter Correct Details";
            QMessageBox::warning(this, "Incorrect Details", msg0);
            ui->lblResult->setText("[-]Wrong Username or Password. :( ");
        }
    } else {
        qDebug() << "Error executing query:" << qry.lastError().text();
    }



}


void KathiHomePage::on_pushButton_2_clicked()
{
    ptrKathiAdminLogin->show();
}

