//
// Created by Ethan Grant on 1/1/2018.
//

#ifndef UNTITLED_POINT_H
#define UNTITLED_POINT_H


class Point {

public:

    Point(){
        owningClass = -1;
        minDistance = INTMAX_MAX;
    }

    Point(double x, double y){
        this->x = x;
        this->y = y;
        owningClass = -1; // indicates unset
        minDistance = INTMAX_MAX; // all distances will be less
    }

    void changeOwnership(const int newClass);
    bool updateMinDistance(const double newDistance);
    int getOwnership() const;
    double getMinDistance(Point) const;
    void prettyPrint(std::ostream& outFile) const;
    void prettyPrint() const;
private:
    double minDistance;
    double x;
    double y;
    int owningClass;
};


#endif //UNTITLED_POINT_H
