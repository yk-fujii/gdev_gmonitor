#include <QApplication>
#include <QLabel>
#include <QtGui>
//#include "mainwindow.h"
#include <QThread>
#include <iostream>
#include <functional>
#include <thread>
#include <exception>
#include <unistd.h>
#include <array>

using namespace std;

#include "qcustomplot/qcustomplot.h"
#include "maindialog.hpp"

void MainDialog::replotGraph()
{
    int i;
retry:
    list<MainGraph*>::iterator it = graph_list.begin();
    while( it != graph_list.end() ){
	(*it)->replotGraph();
	++it;
    }
    sleep(1);
    goto retry;
}

 
  MainDialog::MainDialog(QWidget* parent)
:QDialog(parent)
{

  setGeometry(300,300,1000,800);

  for(int j=0;j<8;j++){
      MainGraph *graph = new MainGraph();
      graph_list.push_back(graph);
  }
 
  QGridLayout *layout = new QGridLayout;

  list<MainGraph*>::iterator it = graph_list.begin();
  int i = 0;
  while( it != graph_list.end() ){
      layout->addWidget((*it), i/4, i % 4 );
      ++it;
      i++;
  }
  setLayout(layout);
}


