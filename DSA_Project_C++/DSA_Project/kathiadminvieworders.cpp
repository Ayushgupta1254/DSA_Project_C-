#include "kathiadminvieworders.h"
#include "ui_kathiadminvieworders.h"

KathiAdminViewOrders::KathiAdminViewOrders(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KathiAdminViewOrders)
{
    ui->setupUi(this);
}

KathiAdminViewOrders::~KathiAdminViewOrders()
{
    delete ui;
    myDB.close();
}

void KathiAdminViewOrders::on_btnView_clicked()
{
    QString datehis = ui->txtDateHis->text();

    if (!myDB.isOpen()) {
        myDB = DatabaseManager::getDatabase("C:/Users/rahul/OneDrive/Documents/DSA_Project/database/DSAProject.db", "AdminViewOrderConnection");

        if (!myDB.isOpen()) {
            qDebug() << "Error opening database:" << myDB.lastError().text();
            return;
        }
    }


    QTableView *tableView = ui->tableOrderHis;

    QSqlTableModel *model = new QSqlTableModel(this, myDB);
    model->setTable("KathiOrder");

    model->setFilter(QString("Date = '%1'").arg(datehis));
    model->setSort(model->fieldIndex("Time"), Qt::DescendingOrder);

    if (model->select()) {
        tableView->setModel(model);
    } else {
        qDebug() << "Error selecting rows:" << model->lastError().text();
    }

}

