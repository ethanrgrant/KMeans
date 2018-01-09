//
// Created by Ethan Grant on 1/1/2018.
//

#include <iostream>
#include <tuple>
#include <cmath>
#include "point.h"

void Point::prettyPrint() const {
    std::cout << "Point(" << x << " , " << y << ")" << std::endl;
}

void Point::prettyPrint(std::ostream& outFile) const {
    outFile << x << "  " << y << "  " << owningClass << std::endl;
}


// updates the min distance if this is a new min
bool Point::updateMinDistance(Point& comparePoint){
    double newDistance = findDistance(comparePoint);
    // if this is a new min update distance and ownership
    if(newDistance < minDistance){
        minDistance = newDistance;
        changeOwnership(comparePoint.getOwnership());
        return true;
    }
    else{
        return false;
    }
}

std::tuple<double, double> Point::getCoords(){
    return std::make_tuple(x, y);
};

// euclidean distance
double Point::findDistance(Point& point){
    return sqrt(pow(x-point.x, 2)+pow(y-point.y, 2));
}
// returns the distance from one point to another.
double Point::getMinDistance(Point) const {
    return minDistance;
}

// changes ownership of Point
void Point::changeOwnership(int newClass){
    owningClass = newClass;
}

int Point::getOwnership() const{
    return owningClass;
}