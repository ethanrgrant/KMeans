#include <iostream>
#include <random>
#include "point.h"
#include "kMeans.cpp"

int main() {
    using namespace home::kmeans;
    // k means will use generated data
    KMeans<Point> kMeans = KMeans<Point>(4, true, true);
    std::cout << "\n \n \n CLUSTERS GENERATED \n \n \n" << std::endl;
    kMeans.doKMeans();
    return 0;
}