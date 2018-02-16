//
// Created by Ethan Grant on 1/1/2018.
//

#ifndef UNTITLED_POINT_H
#define UNTITLED_POINT_H

namespace home {

    namespace kmeans {

        class Point {

        public:

            Point(double x, double y) : d_x(x), d_y(y), d_owningClass(-1),
                                        d_minDist(INTMAX_MAX), d_totalPoints(0) { }


            Point(int owningClass) : d_owningClass(owningClass) {}

            // mutators
            void changeOwnership(const int newClass);
            bool updateMinDistance(Point &comparePoint);
            void sumPoint(Point& p);
            void average();

            // accessors
            double findDistance(Point &point);
            int getOwnership() const;
            std::tuple<double, double> getCoords();
            double getMinDistance(Point) const;

            // output
            void prettyPrint(std::ostream &outFile) const;
            void prettyPrint() const;
            bool sameOwnership(Point& otherPoint);


        private:
            double d_minDist;
            double d_x;
            double d_y;
            int d_owningClass;
            int d_totalPoints;
        };

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
        }

        // determines if two points are equal
        inline
        bool Point::sameOwnership(Point& otherPoint){
            return (otherPoint.getOwnership() == d_owningClass);
        }

        inline
        void Point::prettyPrint() const {
            std::cout << "Point(" << d_x << " , " << d_y << ")" << std::endl;
        }

        inline
        void Point::prettyPrint(std::ostream &outFile) const {
            outFile << d_x << "  " << d_y << "  " << d_owningClass << std::endl;
        }

    }
}


#endif //UNTITLED_POINT_H
