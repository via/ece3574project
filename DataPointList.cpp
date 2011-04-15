
#include "DataPointList.h"


DataPointList::DataPointList(double latMin, double lonMin) {

  mLatMin = latMin;
  mLonMin = lonMin;

}

void DataPointList::append(const MapDataPoint *& mdp) {

  if (empty()) {
    mLatStart = mdp->getLat() - mLatMin / 2;
    mLatStop = mdp->getLat() + mLatMin / 2;
    mLonStart = mdp->getLong() - mLonMin / 2;
    mLonStop = mdp->getLong() + mLonMin / 2;
  } else {
    if (mdp->getLat() > mLatStart - mLatMin)
      mLatStart = mdp->getLat() - mLatMin;
    if (mdp->getLat() < mLatStop + mLatMin)
      mLatStop = mdp->getLat() + mLatMin;
    if (mdp->getLong() > mLonStart - mLonMin)
      mLonStart = mdp->getLong() - mLonMin;
    if (mdp->getLong() < mLonStop + mLonMin)
      mLonStop = mdp->getLong() + mLonMin;
  }

  QLinkedList::append(mdp);

}


