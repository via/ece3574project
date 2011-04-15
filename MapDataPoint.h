#ifndef MAPDATAPOINT_H
#define MAPDATAPOINT_H

#include <QObject>
#include <QTextStream>

class MapDataPoint : public QObject {
  Q_OBJECT

  private:
    double mLatitude, mLongitude;
    double mAccelX, mAccelY, mAccelZ;

  public:
    MapDataPoint(QObject *parent = 0, double lat = 0, double lon = 0,
        double x = 0, double y = 0, double z = 0);
    

    double getLat() const { return mLatitude; };
    double getLong() const { return mLongitude; };

    double getX() const { return mAccelX; };
    double getY() const { return mAccelY; };
    double getZ() const { return mAccelZ; };


    friend QTextStream & operator<<(QTextStream & out, const MapDataPoint &mdp);
    friend QTextStream & operator>>(QTextStream & in, MapDataPoint &mdp);

};


#endif
