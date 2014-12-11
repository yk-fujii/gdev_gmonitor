#include <QApplication>
#include <QLabel>
#include <QtGui>
//#include "mainwindow.h"
#include <QThread>
#include <iostream>
#include <thread>
#include <exception>
#include <unistd.h>
#include <thread>

#include "maindialog.hpp"

using namespace std;


int main(int argc, char **argv){
   
    QApplication a(argc, argv);
    MainDialog *dialog = new MainDialog;

    dialog->show();
    std::thread t1(std::bind(&MainDialog::replotGraph, dialog));

    return a.exec();
}
