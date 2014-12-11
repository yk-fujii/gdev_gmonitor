#include <QDialog>
#include <list>

#include "qcustomplot/qcustomplot.h"
#include "maingraph.hpp"


class MainDialog: public QDialog
{
    Q_OBJECT
    public:
	MainDialog(QWidget* parent = 0);
	void replotGraph();
    private:
	std::list<QCustomPlot*> plot_list;
	std::list<MainGraph*> graph_list;
};
