//
// Created by Ethan Grant on 1/1/2018.
//

#ifndef UNTITLED_POINT_H
#define UNTITLED_POINT_H

#include <tuple>
#include <iostream>
#include <cmath>
#include <fstream>

namespace home {

    namespace kmeans {

        class Point {

        public:

            Point(double x, double y) : d_x(x), d_y(y), d_owningClass(-1),
                                        d_minDist(INTMAX_MAX), d_totalPoints(0) { }


            Point(int owningClass) : d_owningClass(owningClass) {}

            // mutators
            void changeOwnership(const int newClass);
            bool updateMinDistance(const Point &comparePoint);
            void sumPoint(Point& p);
            void average();

            // accessors
            double findDistance(const Point &point);
            int getOwnership() const;
            std::tuple<double, double> getCoords() const;
            double getMinDistance(Point) const;

            // output
            bool sameOwnership(Point& otherPoint);


        private:
            double d_minDist;
            double d_x;
            double d_y;
            int d_owningClass;
            int d_totalPoints;
        };

        inline
        std::ofstream& operator<<(std::ofstream& outfile, const Point& point) {
            std::tuple<double, double> coords = point.getCoords();
            outfile << std::get<0>(coords) << "  " << std::get<1>(coords)
                    << "  " << point.getOwnership() << std::endl;
            return outfile;
        }

        // allows points to be summed together to later be avgd
        inline
        void Point::sumPoint(Point &p) {
            d_x += p.d_x;
            d_y += p.d_y;
            ++d_totalPoints;
        }

        // used when a point represents a cluster
        inline
        void Point::average(){
            d_x /= d_totalPoints;
            d_y /= d_totalPoints;
            d_totalPoints = 1;
        }

        // determines if two points are equal
        inline
        bool Point::sameOwnership(Point& otherPoint){
            return (otherPoint.getOwnership() == d_owningClass);
        }

        inline
        std::tuple<double, double> Point::getCoords() const {
            return std::make_tuple(d_x, d_y);
        };

        // euclidean distance
        inline
        double Point::findDistance(const Point &point) {
            return sqrt(pow(d_x - point.d_x, 2) + pow(d_y - point.d_y, 2));
        }

        // returns the distance from one point to another.
        inline
        double Point::getMinDistance(Point) const {
            return d_minDist;
        }

        // changes ownership of Point
        inline
        void Point::changeOwnership(int newClass) {
            d_owningClass = newClass;
        }

        inline
        int Point::getOwnership() const {
            return d_owningClass;
        }

        inline
        Point& operator+=(Point& lhs, Point& rhs) {
            lhs.sumPoint(rhs);
        }

    }
}


#endif //UNTITLED_POINT_H
