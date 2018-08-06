#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

typedef struct {
    QString firstname;
    QString lastname;
    QString address;
    QString city;
    QString state;
    QString ZIP;
} DATA;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void printAddressLabel(void);

private slots:
    void on_BTN_quit_clicked();

    void on_BTN_submit_clicked();

private:
    Ui::MainWindow *ui;

    // create a private variable to store feedback
    DATA myInfo;
};

#endif // MAINWINDOW_H
