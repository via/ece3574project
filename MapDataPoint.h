#ifndef MAPDATAPOINT_H
#define MAPDATAPOINT_H

#include <QObject>
#include <QDataStream>

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


    friend QDataStream & operator<<(QDataStream & out, const MapDataPoint &mdp);
    friend QDataStream & operator>>(QDataStream & in, MapDataPoint &mdp);

};


#endif
