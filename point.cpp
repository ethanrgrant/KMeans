//
// Created by Ethan Grant on 1/1/2018.
//

#include <iostream>
#include "point.h"

void Point::prettyPrint() const {
    std::cout << "Point(" << x << " , " << y << ")" << std::endl;
}

void Point::prettyPrint(std::ostream& outFile) const {
    outFile << x << "  " << y << "  " << owningClass << std::endl;
}


// updates the min distance if this is a new min
bool Point::updateMinDistance(const double newDistance){
    if(newDistance < minDistance){
        minDistance = newDistance;
        return true;
    }
    else{
        return false;
    }
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