#include "adminhistory.h"
#include "ui_adminhistory.h"
#include "databasemanager.h"

AdminHistory::AdminHistory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminHistory)
{
    ui->setupUi(this);
}

AdminHistory::~AdminHistory()
{
    delete ui;
    myDB.close();
}

void AdminHistory::on_pushButton_clicked()
{

    QString bagNo = ui->txtBagNoHis->text();
    QString date = ui->txtDateHis->text();


    if (!myDB.isOpen()) {
        myDB = DatabaseManager::getDatabase("C:/Users/rahul/OneDrive/Documents/DSA_Project/database/DSAProject.db", "AdminHistoryConnection");

        if (!myDB.isOpen()) {
            qDebug() << "Error opening database:" << myDB.lastError().text();
            return;
        } else {
            qDebug() << "Database opened successfully!";
        }
    }


//    if (!myDB.isOpen()) {
//        myDB = DatabaseManager::getDatabase("C:/Users/rahul/OneDrive/Documents/DSA_Project/database/DSAProject.db", "AdminHistoryConnection");

//        if (!myDB.isOpen()) {
//            qDebug() << "Error opening database:" << myDB.lastError().text();
//            return;
//        }
//    }

    QSqlQuery qry(myDB);

    QTableView *tableView = ui->tableHistory;

    QSqlTableModel *model = new QSqlTableModel(this, myDB);
    model->setTable("LaundryClothes");

    model->setFilter(QString("BagNo = '%1' AND Date = '%2'").arg(bagNo, date));

    if (model->select()) {
        tableView->setModel(model);
    } else {
        qDebug() << "Error selecting rows:" << model->lastError().text();
    }


}


void AdminHistory::on_btnView_clicked()
{

    QString SDate = ui->txtSDateHis->text();

    if (!myDB.isOpen()) {
        myDB = DatabaseManager::getDatabase("C:/Users/rahul/OneDrive/Documents/DSA_Project/database/DSAProject.db", "AdminHistoryForDateConnection");

        if (!myDB.isOpen()) {
            qDebug() << "Error opening database:" << myDB.lastError().text();
            return;
        }
    }

    QSqlQuery qry(myDB);

    QTableView *tableView = ui->tableHistory;

    QSqlTableModel *model = new QSqlTableModel(this, myDB);
    model->setTable("LaundryClothes");

    model->setFilter(QString("Date = '%1'").arg( SDate));

    if (model->select()) {
        tableView->setModel(model);
    } else {
        qDebug() << "Error selecting rows:" << model->lastError().text();
    }
}

