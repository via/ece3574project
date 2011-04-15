#ifndef TRACEWIDGET_H
#define TRACEWIDGET_H


#include <QObject>
#include <QWidget>
#include <QPaintEvent>

#include "mainwindow.h"
#include "DataPointList.h"

class TraceWidget : public QWidget {

  private:
    Axis R, G, B;
    DataPointList *list;

  protected:

    void paintEvent(QPaintEvent *);

  public:
    TraceWidget(QWidget *parent = 0);
    void setList(DataPointList *list) { this->list = list; };
    void setR(Axis r) {R = r; };
    void setG(Axis g) { G = g; };
    void setB(Axis b) { B = b; };


};

#endif
