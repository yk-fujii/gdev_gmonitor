#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QScreen>
#include <QMessageBox>
#include <QMetaEnum>
#include <linux/sched.h>

//#include <boost/thread.hpp>
//#include <boost/bind.hpp>

using namespace std;
//using namespace boost;


GraphWidget::GraphWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphWidget)
{
    ui->setupUi(this);
    gplot = ui->customPlot;
    showUseGraph(ui->customPlot);
}


void GraphWidget::replotGraph(){
    showUseGraph(gplot);
}


void GraphWidget::showUseGraph(QCustomPlot *customPlot)
{
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
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    customPlot->xAxis->setRange(0,256);
    customPlot->yAxis->setRange(0,100);
//customPlot->rescaleAxes();
#if 0

    customPlot->graph(0)->rescaleValueAxis(true);

    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
    //customPlot->yAxis->setRange(0, 1);
#endif
    customPlot->replot();

    
}

GraphWidget::~GraphWidget()
{
    delete ui;
}
