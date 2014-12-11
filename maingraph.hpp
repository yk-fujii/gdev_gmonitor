#include <QDialog>
#include <list>
#include <QVector>

#include "qcustomplot/qcustomplot.h"

class MainGraph: public QCustomPlot
{
    Q_OBJECT
	QVector<double> x = QVector<double>(256);
	QVector<double> y = QVector<double>(256);
    public:
	MainGraph(QWidget* parent = 0);
        void CreateGraph(char *file_name);
        void replotGraph();
        void replotGraph_Data(int data);
 void loadGraphData();
    private:

};
