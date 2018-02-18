//
// Created by Ethan Grant on 1/1/2018.
//
#include "point.h"
namespace home {

    namespace kmeans {

        // updates the min distance if this is a new min
        bool Point::updateMinDistance(const Point& comparePoint) {
            double newDistance = findDistance(comparePoint);
            if (newDistance < d_minDist) {
                d_minDist = newDistance;
                changeOwnership(comparePoint.getOwnership());
                return true;
            } else {
                return false;
            }
        }

    }
}