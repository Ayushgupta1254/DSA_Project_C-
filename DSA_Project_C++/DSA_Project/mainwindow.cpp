#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrKathiHomePage = new KathiHomePage();
    ptrLaundryHomePage = new LaundryHomePage();
    //ptrKathiOrderingPage = new KathiOrderingPage();

}

MainWindow::~MainWindow()
{
    delete ptrKathiHomePage;
    delete ptrLaundryHomePage;
    //delete ptrKathiOrderingPage;
    delete ui;

}


void MainWindow::on_pushButton_clicked()
{
    ptrKathiHomePage->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    ptrLaundryHomePage->show();
}

