#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BTN_quit_clicked()
{
    // the quit button was clicked

    // now terminate the application by closing the MainWindow
    this->close();
}

void MainWindow::on_BTN_submit_clicked()
{
    // let's connect the user feedback
    myInfo.firstname = ui->TE_firstName->text();
    myInfo.lastname  = ui->TE_lastName->text();
    myInfo.address   = ui->TE_address->text();
    myInfo.city      = ui->TE_city->text();
    myInfo.state     = ui->CB_state->currentText();
    myInfo.ZIP       = ui->TE_ZIP->text();

    // now we have all the information in myInfo

    // execute a print statement
    printAddressLabel();

}

void MainWindow::printAddressLabel(void)
{
    // implementing the address label

    // use simple console output
    std::cout << myInfo.firstname.toStdString() << " ";
    std::cout << myInfo.lastname.toStdString()  << std::endl;

    std::cout << myInfo.address.toStdString() << std::endl;
    std::cout << myInfo.city.toStdString() << ", "
              << myInfo.state.toStdString() << " "
              << myInfo.ZIP.toStdString() << std::endl;
}
