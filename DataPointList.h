#ifndef DATAPOINTLIST_H
#define DATAPOINTLIST_H


#include <QObject>
#include <QLinkedList>
#include "MapDataPoint.h"

class DataPointList : public QLinkedList<const MapDataPoint *> {

  private:
    double mLatStart, mLatStop;
    double mLonStart, mLonStop;
    double mLatMin, mLonMin;
  
  public:
    DataPointList(double latMin, double lonMin);

    double getLonMin() { return mLonStart; };
    double getLonMax() { return mLonStop;  };
    double getLatMin() { return mLatStart; };
    double getLatMax() { return mLatStop;  };

    void append(const MapDataPoint *& mdp);


};

#endif

