#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QStringList>
#include <QString>
#include "addressdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList theStates = {"AL", "AK", "AZ", "AR",
                             "CA", "CO", "CT",
                             "DE",
                             "FL",
                             "GA",
                             "HI",
                             "ID", "IL", "IN", "IA",
                             "KS", "KY",
                             "LA",
                             "ME", "MD", "MA", "MI", "MN", "MS", "MO", "MT",
                             "NE", "NV", "NH", "NJ", "NM", "NY", "NC", "ND",
                             "OH", "OK", "OR",
                             "PA",
                             "RI",
                             "SC", "SD",
                             "TN", "TX",
                             "UT",
                             "VT", "VA",
                             "WA", "WV", "WI", "WY"};

    ui->CB_state->addItems(theStates);
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

void MainWindow::readData()
{
    // let's connect the user feedback
    myInfo.firstname = ui->TE_firstName->text();
    myInfo.lastname  = ui->TE_lastName->text();
    myInfo.address   = ui->TE_address->text();
    myInfo.city      = ui->TE_city->text();
    myInfo.state     = ui->CB_state->currentText();
    myInfo.ZIP       = ui->TE_ZIP->text();

    // now we have all the information in myInfo
}

void MainWindow::on_BTN_submit_clicked()
{
    // let's connect the user feedback
    readData();

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

void MainWindow::on_BTN_popupLabel_clicked()
{
    readData();

    // create address string
    QString theAddress;
    theAddress  = myInfo.firstname + " " + myInfo.lastname + "\n";
    theAddress += myInfo.address + "\n";
    theAddress += myInfo.city + ", " + myInfo.state + " " + myInfo.ZIP  + "\n";

    // create dialog
    AddressDialog dlg;
    dlg.setAddress(theAddress);

    // show dialog
    dlg.exec();

    // the dialog gets destroyed upon pressing the OK button
}
