//
// Created by Ethan Grant on 1/1/2018.
//

#include <iostream>
#include <tuple>
#include <cmath>
#include "point.h"
namespace home {

    namespace kmeans {

        // updates the min distance if this is a new min
        bool Point::updateMinDistance(Point& comparePoint) {
            double newDistance = findDistance(comparePoint);
            // if this is a new min update distance and ownership
            if (newDistance < minDistance) {
                minDistance = newDistance;
                changeOwnership(comparePoint.getOwnership());
                return true;
            } else {
                return false;
            }
        }

        std::tuple<double, double> Point::getCoords() {
            return std::make_tuple(d_x, d_y);
        };

        // euclidean distance
        double Point::findDistance(Point &point) {
            return sqrt(pow(d_x - point.d_x, 2) + pow(d_y - point.d_y, 2));
        }

        // returns the distance from one point to another.
        double Point::getMinDistance(Point) const {
            return minDistance;
        }

        // changes ownership of Point
        void Point::changeOwnership(int newClass) {
            d_owningClass = newClass;
        }

        int Point::getOwnership() const {
            return d_owningClass;
        }

    }
}