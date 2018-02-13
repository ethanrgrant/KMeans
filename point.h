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
                owningClass = -1;
                minDistance = INTMAX_MAX;
            }

            Point(double x, double y) {
                this->x = x;
                this->y = y;
                owningClass = -1; // indicates unset
                minDistance = INTMAX_MAX; // all distances will be less
            }

            void changeOwnership(const int newClass);

            bool updateMinDistance(Point &comparePoint);

            double findDistance(Point &point);

            std::tuple<double, double> getCoords();

            int getOwnership() const;

            double getMinDistance(Point) const;

            void prettyPrint(std::ostream &outFile) const;

            void prettyPrint() const;

            // allows points to be summed together to later be avgd
            inline
            void sumPoint(Point &p) {
                x += p.x;
                y += p.y;
            }

            // used when a point represents a cluster
            inline
            void average(int num){
                x /= num;
                y /= num;
            }

            // determines if two points are equal
            inline
            static bool sameOwnership(Point otherPoint){
                return (otherPoint.getOwnership() == owningClass);
            }


        private:
            double minDistance;
            double x;
            double y;
            int owningClass;
        };



    }
}


#endif //UNTITLED_POINT_H
