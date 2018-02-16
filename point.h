//
// Created by Ethan Grant on 1/1/2018.
//

#ifndef UNTITLED_POINT_H
#define UNTITLED_POINT_H

namespace home {

    namespace kmeans {

        class Point {

        public:

            Point() {
                d_owningClass = -1;
                minDistance = INTMAX_MAX;
                x = 0;
                y = 0;
            }

            Point(double x, double y) {
                this->x = x;
                this->y = y;
                d_owningClass = -1; // indicates unset
                minDistance = INTMAX_MAX; // all distances will be less
            }

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
            double minDistance;
            double x;
            double y;
            int d_owningClass;
            int totalPoints;
        };

        // allows points to be summed together to later be avgd
        inline
        void Point::sumPoint(Point &p) {
            x += p.x;
            y += p.y;
            ++totalPoints;
        }

        // used when a point represents a cluster
        inline
        void Point::average(){
            x /= totalPoints;
            y /= totalPoints;
        }

        // determines if two points are equal
        inline
        bool Point::sameOwnership(Point& otherPoint){
            return (otherPoint.getOwnership() == d_owningClass);
        }

        inline
        void Point::prettyPrint() const {
            std::cout << "Point(" << x << " , " << y << ")" << std::endl;
        }

        inline
        void Point::prettyPrint(std::ostream &outFile) const {
            outFile << x << "  " << y << "  " << d_owningClass << std::endl;
        }

    }
}


#endif //UNTITLED_POINT_H
