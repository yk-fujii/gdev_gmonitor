#include <QApplication>
#include <QLabel>
#include <QtGui>
#include <QThread>
#include <iostream>
#include <functional>
#include <thread>
#include <exception>
#include <unistd.h>
#include <array>

using namespace std;

#include "qcustomplot/qcustomplot.h"
#include "plotgraph.hpp"

void MainDialog::replotGraph()
{
    static QVector<double> x(256),y(256);
    int temp;
    QCustomPlot *plot;
retry:
    list<QCustomPlot*>::iterator it = plot_list.begin();

    while( it != plot_list.end() ){
	for (int i= 0; i<256; ++i)
	{
	    x[i] = i;
	    y[i] = y[i+1];
	}

	y[255] = rand() %100;

	(*it)->graph(0)->setData(x, y);
	(*it)->rescaleAxes();

	(*it)->replot();
	++it;
    }
    sleep(1);
    goto retry;
}

  
QCustomPlot* MainDialog::CreateGraph(char *file_name)
{

  QCustomPlot *ret = new QCustomPlot;
  static int count = 0;
  static QVector<double> x(256),y(256);
  int temp;
    for (int i= 0; i<256; ++i)
    {
	x[i] = i;
	y[i] = y[i+1];
    }

    y[255] = rand() %100;


ret:
    ret->addGraph();
    ret->graph(0)->setData(x, y);
    ret->xAxis->setRange(0,256);
    ret->yAxis->setRange(0,100);
 
    ret->replot();
    return ret;
}
 
  MainDialog::MainDialog(QWidget* parent)
:QDialog(parent)
{

  setGeometry(300,300,1000,800);

  for(int j=0;j<8;j++){
      QCustomPlot *graph1 = CreateGraph(NULL);
      plot_list.push_back(graph1);
  }
 
  QGridLayout *layout = new QGridLayout;

  list<QCustomPlot*>::iterator it = plot_list.begin();
  int i = 0;
  while( it != plot_list.end() ){
  
      layout->addWidget((*it), i/4, i % 4 );
      ++it;
      i++;
  }

  setLayout(layout);
}


