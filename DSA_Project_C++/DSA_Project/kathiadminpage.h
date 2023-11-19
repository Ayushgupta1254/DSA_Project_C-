#ifndef KATHIADMINPAGE_H
#define KATHIADMINPAGE_H

#include <QDialog>
#include "kathiadminvieworders.h"
#include "kathiadminpendingorder.h"

namespace Ui {
class KathiAdminPage;
}

class KathiAdminPage : public QDialog
{
    Q_OBJECT

public:
    explicit KathiAdminPage(QWidget *parent = nullptr);
    ~KathiAdminPage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::KathiAdminPage *ui;
    KathiAdminViewOrders *ptrKathiAdminViewOrders;
    KathiAdminPendingOrder *ptrKathiAdminPendingOrder;
};

#endif // KATHIADMINPAGE_H
