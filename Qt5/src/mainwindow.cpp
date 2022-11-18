#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_pushButtonlimpiar_clicked(){
    ui->lineEdit1->setText("");
    ui->lineEdit2->setText("");
    ui->lineEdit3->setText("");
}

void MainWindow::on_pushButtonsumar_clicked(){
    if(ui->lineEdit1->text().isEmpty() || ui->lineEdit2->text().isEmpty()){
        QMessageBox msgBox;
        msgBox.setText("Ingrese dos numeros");
        msgBox.exec();
    }
    else{
        float n1, n2, suma;
        n1 = ui->lineEdit1->text().toFloat();
        n2 = ui->lineEdit2->text().toFloat();
        suma = n1 + n2;
        ui->lineEdit3->setText(QString::number(suma));
    }
}
