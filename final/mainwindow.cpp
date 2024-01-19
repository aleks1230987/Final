#include "mainwindow.h"
#include "ui_mainwindow.h"  
#include "secondwindow.h"
#include <QFile>

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




void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit->text().isEmpty()){
            return;
        }
    QString Name = ui->lineEdit->text();

    SecondWindow window;
    window.setModal(true);
    window.setName(Name);
    this->close();
    window.exec();
}
