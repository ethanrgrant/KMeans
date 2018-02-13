//
// Created by Ethan Grant on 1/1/2018.
//

#ifndef UNTITLED_KMEANS_H
#define UNTITLED_KMEANS_H

#include "point.h"
#include <algorithm>

namespace home {

    namespace kmeans {
        template<class T>
        class KMeans {
        public:
            // constructor for k means if its going to generate points
            KMeans(int numClusters, bool toGenerate, bool toWriteOutFile)
                    : numClusters(numClusters), toGenerate(toGenerate), toWriteOutFile(toWriteOutFile) {}

            bool doKMeans() {
                if (toGenerate)
                    generateClusters();
                chooseRandomStartingPoints();
                // TODO some calculation about amt of movement to determine when k means is done
                for (int i = 0; i < 10; i++) {
                    determineNewOwnership();
                    findNewMeans();
                }
                writeOutFile(std::string("../output/points.txt"));
            }

        private:

            void determineNewOwnership() {
                for (auto meanPoint : currentMeans) {
                    for (T point : data) {
                        point.updateMinDistance(meanPoint);
                    }
                }
            }

            void findNewMeans() {
                std::vector<T> newMeans = {};
                // create new vector of means
                typename std::vector<T>::iterator it;
                for (T& point: data) {
                    // T must have way to compare ownership between itself and another class
                     it = std::find_if(currentMeans.begin(), currentMeans.end(),
                                       );
                    if (it == currentMeans.end()) {
                        newMeans.push_back(point);
                    } else {
                        it->sumPoint(point);
                    }
                }
                for (auto &point: newMeans) {
                    point.average(data.size());
                }
                currentMeans = newMeans;
            }

            // writes out file to given filename
            bool writeOutFile(std::string fileName) {
                std::cout << "XXXXXXXXX \n \n \n writing file: \n \n \nXXXXXXXX" << fileName << std::endl;
                std::ofstream outFile;
                outFile.open(fileName);
                for (auto &point : data) {
                    point.prettyPrint(outFile);
                }
            }

            // points = a vector to be filled with chosen starting points
            void chooseRandomStartingPoints() {
                // creates uniform distribution across numPoints
                std::default_random_engine generator;
                std::uniform_int_distribution<> dis(0, numPoints - 1);
                // finds starting points
                for (int i = 0; i < numClusters; i++) {
                    // copy value and then update ownership. This will hold each mean as it moves
                    Point newMean = data[dis(generator)];
                    newMean.changeOwnership(i);
                    currentMeans.push_back(data[dis(generator)]);
                }
            }

            // used to generate clusters using normal distribution
            void generateClusters() {
                std::cout << "Generating Clusters" << std::endl;
                numPoints = numClusters * pointsPerGenCluster;
                std::vector<Point> *pointsToCluster = new std::vector<Point>();
                // create vars for normal params
                int mean = 1;
                int stdDev = 1;
                std::default_random_engine generator;
                for (int i = 0; i < numClusters; i++) {
                    std::normal_distribution<double> distribution(mean, stdDev);
                    mean += 3;
                    for (int j = 0; j < pointsPerGenCluster; j++) {
                        Point thisPoint = Point(distribution(generator), distribution(generator));
                        thisPoint.prettyPrint();
                        pointsToCluster->push_back(thisPoint);
                    }
                }
                data = *pointsToCluster;
            }

            bool toWriteOutFile;
            bool toGenerate;
            std::vector<T> data;
            std::vector<T> currentMeans; // vector of current means
            int numClusters;
            int numPoints;
            const int pointsPerGenCluster = 300;
        };
    }
}

#endif //UNTITLED_KMEANS_H
