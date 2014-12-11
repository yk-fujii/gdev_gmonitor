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
#include "maingraph.hpp"

  MainGraph::MainGraph(QWidget* parent)
:QCustomPlot(parent)
{
    for (int i = 0; i<256; ++i)
    {
	x[i] = i;
	y[i] = 0;

    }
    addGraph();
    graph(0)->setData(x,y);
    xAxis->setRange(0, 256);//MAX_GRAPH_SIZE);
    yAxis->setRange(0,100);
    replot();

}

 void MainGraph::loadGraphData()
{
    for (int i= 0; i<256; ++i)
	y[i] = y[i+1];

    y[255] = rand() %100;

}

void MainGraph::replotGraph()
{
    loadGraphData();
    graph(0)->setData(x,y);
    replot();
}

void MainGraph::replotGraph_Data(int data)
{

}


