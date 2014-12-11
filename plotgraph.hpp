#include <QDialog>
#include <list>

#include "qcustomplot/qcustomplot.h"

class MainDialog: public QDialog
{
    Q_OBJECT
    public:
	MainDialog(QWidget* parent = 0);
        QCustomPlot* CreateGraph(char *file_name);
        void replotGraph();
    private:
	std::list<QCustomPlot*> plot_list;
};
