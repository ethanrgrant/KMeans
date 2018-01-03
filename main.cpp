#include <iostream>
#include <random>
#include "point.h"
#include "kMeans.cpp"

void generateClusters(std::vector<Point>& pointsToCluster, int numClusters){
    std::cout << "Generating Clusters" << std::endl;
    int numPoints = numClusters * 300;

    // create vars for normal params
    int mean = 1;
    int stdDev = 2;
    std::default_random_engine generator;
    for(int i = 0; i < numClusters; i++){
        std::normal_distribution<double> distribution(mean++, stdDev++);
        for(int j=0; j<300; j++){
            double number = distribution(generator);
            Point thisPoint = Point(distribution(generator), distribution(generator));
            thisPoint.prettyPrint();
            pointsToCluster.push_back(thisPoint);
        }
    }
}

int main() {
    std::vector<Point> pointsToCluster;
    generateClusters(pointsToCluster, 4);
    KMeans<Point> kMeans = KMeans<Point>(4, pointsToCluster, true);
    std::cout << "\n \n \n CLUSTERS GENERATED \n \n \n" << std::endl;
    kMeans.doKMeans();
    return 0;
}