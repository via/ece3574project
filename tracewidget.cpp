#include <QtGui>

#include "tracewidget.h"

TraceWidget::TraceWidget(QWidget *parent) : QWidget(parent) {

  R = X;
  G = Y;
  B = Z;
  list = NULL;

}

void TraceWidget::paintEvent(QPaintEvent *ev) {

  QPainter painter(this);
  painter.fillRect(painter.window(), Qt::white);
  QTextStream cout(stdout);

  if (list == NULL)
    return;

  painter.setWindow(list->getLonMin() * 10000000, list->getLatMin() * 10000000,
      (list->getLonMax() - list->getLonMin()) * 10000000,
      (list->getLatMax() - list->getLatMin()) * 10000000);

  DataPointList::const_iterator iter;
  for (iter = list->constBegin(); iter != list->constEnd(); ++iter) {
    int red = ( R == X ? (*iter)->getX() :
        ( R == Y ? (*iter)->getY() : (*iter)->getZ())) * 5 + 127;
    int green = ( G == X ? (*iter)->getX() :
        ( G == Y ? (*iter)->getY() : (*iter)->getZ())) * 5 + 127;
    int blue = ( B == X ? (*iter)->getX() :
        ( B == Y ? (*iter)->getY() : (*iter)->getZ())) * 5 + 127;
    painter.setPen(QColor::fromRgb(red, green, blue));
    painter.setBrush(QColor::fromRgb(red, green, blue));
    painter.drawEllipse((*iter)->getLong() * 10000000, (*iter)->getLat() * 10000000,
        300, 300);

  }

}
