
#include <QtGui>

#include "MapDataPoint.h"

MapDataPoint::MapDataPoint(QObject *parent, double lat, double lon,
    double x, double y, double z) : QObject(parent) {

  mLatitude = lat;
  mLongitude = lon;
  mAccelX = x;
  mAccelY = y;
  mAccelZ = z;

}


QTextStream& operator<<(QTextStream& out, const MapDataPoint &mdp) {

  out << mdp.mLatitude << " " << mdp.mLongitude << " " << mdp.mAccelX << " ";
  out << mdp.mAccelY << " " << mdp.mAccelZ;

  return out;
}

QTextStream& operator>>(QTextStream &in, MapDataPoint &mdp) {

  in >> mdp.mLatitude >> mdp.mLongitude >> mdp.mAccelX;
  in >> mdp.mAccelY >> mdp.mAccelZ;

  return in;

}
