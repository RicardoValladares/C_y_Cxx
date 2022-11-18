#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.setMaximumSize(w.size());
    w.setMinimumSize(w.size());
    w.setWindowTitle("Suma de dos numeros");
    w.show();
    return a.exec();
}
