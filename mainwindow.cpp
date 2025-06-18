#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <iostream>
#include <vector>
#include <cmath>
#include <QLineEdit>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}



// int size = 1;

std::vector <std::string> const seledka = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };


// void In10System() {
//     int result = 0;
//     int cnt = 0;
//     while (number > 0)
//     {
//         result += number % 10 * pow(base, cnt++);
//         number /= 10;
//     }
//     number = result;
//     base = base2;

// }

// void In2to30System() {
//     std::vector <std::string> theNumbers;
//     int digit = number;
//     int digit1 = number;
//     std::string fish = "";

//     while (digit1>0) {
//         digit = digit1 % base2;
//         digit1 = digit1 / base2;
//         theNumbers.push_back(seledka[digit]);
//     }

//     for (int i = theNumbers.size() - 1; i >= 0; i--) { //Доработать
//         fish += theNumbers[i];
//     }

//     ui->DesiredNumber->setText(QString::number(fish))
// }


void MainWindow::on_TransitButton_clicked()
{
    int number = ui->EditNumber->text().toInt();
    int base = ui->EditBaseNumber->text().toInt();
    int base2 = ui->EditDesiredNumber->text().toInt();


    int result = 0;
    int cnt = 0;
    while (number > 0)
    {
        result += number % 10 * pow(base, cnt++);
        number /= 10;
    }
    number = result;
    base = base2;

    std::vector <std::string> theNumbers;
    int digit = number;
    int digit1 = number;
    std::string fish = "";

    while (digit1>0) {
        digit = digit1 % base2;
        digit1 = digit1 / base2;
        theNumbers.push_back(seledka[digit]);
    }

    for (int i = theNumbers.size() - 1; i >= 0; i--) { //Доработать
        fish += theNumbers[i];
    }

    ui->DesiredNumber->setText(QString::fromStdString(fish));
}

