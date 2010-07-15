#ifndef PLOT_H
#define PLOT_H

// Qwt includes
#include <qwt_plot.h>

class Plot : public QwtPlot
{
    Q_OBJECT
public:
    explicit Plot(QWidget *parent = 0);

signals:

public slots:

};

#endif // PLOT_H
