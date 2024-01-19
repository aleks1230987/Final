#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "mainwindow.h"
#include <fstream>
#include <QDebug>
#include <QFile>
#include <QTextStream>


int AppleCount, PearCount, CherryCount;
int AppleCost, PearCost, CherryCost;
int TotalPrice;
int AppleCountNow, PearCountNow, CherryCountNow;
int i = 0;




SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    ui->label_1->setText("Название");
    ui->label_2->setText("Количество");
    ui->label_3->setText("Цена");


    QFile file(":/products/Text/ListProducts.txt");


    if (file.exists() and file.open(QIODevice::ReadOnly)){
        QTextStream in(&file);
        Update();
        ui->label_14->setText(QString::number(TotalPrice));

        while(!in.atEnd()){
            QString line = in.readLine();
            QStringList key = line.split('/');
            QString line1 = key[0];
            QString Cost = key[1];
            QStringList key1 = line1.split(' ');
            QString Num = key1[1];
            QString Naming = key1[0];

            if (i == 0){
                ui->label_4->setText(Naming);
                ui->label_5->setText(Num);
                ui->label_6->setText(Cost);
                AppleCount = Num.toInt();
                AppleCost = Cost.toInt();
            }
            if (i == 1){
                ui->label_7->setText(Naming);
                ui->label_8->setText(Num);
                ui->label_9->setText(Cost);
                PearCount = Num.toInt();
                PearCost = Cost.toInt();
            }
            if (i == 2){
                ui->label_10->setText(Naming);
                ui->label_11->setText(Num);
                ui->label_12->setText(Cost);
                CherryCount = Num.toInt();
                CherryCost = Cost.toInt();
            }



            i++;

        }

        ui->spinBox->setMaximum(AppleCount);
        ui->spinBox_2->setMaximum(PearCount);
        ui->spinBox_3->setMaximum(CherryCount);
    }
    file.close();



}

SecondWindow::~SecondWindow()
{
    delete ui;
}


void SecondWindow::setName(const QString &name)
{
    Name = name;
}



void SecondWindow::on_pushButton_clicked()
{
    QFile Cheque("C:/Users/user/Desktop/final/Text/Cheque.txt");

    if (Cheque.exists() and Cheque.open(QIODevice::WriteOnly | QIODevice:: Text))
      {
          QTextStream out(&Cheque);
          out << (Name + " заказал: ") << '\n' << '\n';
          out << ("Яблоко: " + (QString::number(AppleCountNow))) << " * " << AppleCost << '\n';
          out << ("Груша: " + (QString::number(PearCountNow))) << " * " << PearCost  <<'\n';
          out << ("Вишня: " + (QString::number(CherryCountNow)))<< " * " << CherryCost << '\n';
          out << ("Общая стоимость: " + (QString::number(TotalPrice)));
      }
      Cheque.close();
      QApplication:: quit();
}

void SecondWindow::Update()
{
    TotalPrice = AppleCost * AppleCountNow + PearCost * PearCountNow + CherryCost * CherryCountNow;
    ui->label_14->setText(QString::number(TotalPrice));
}


void SecondWindow::on_spinBox_3_valueChanged(int arg1)
{
    CherryCountNow = arg1;
    Update();
}

void SecondWindow::on_spinBox_2_valueChanged(int arg1)
{
    PearCountNow = arg1;
    Update();
}

void SecondWindow::on_spinBox_valueChanged(int arg1)
{
    AppleCountNow = arg1;
    Update();
}
