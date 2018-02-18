//
// Created by Ethan Grant on 1/1/2018.
//

#ifndef UNTITLED_KMEANS_H
#define UNTITLED_KMEANS_H

#include "point.h"

#include <algorithm>
#include <ctime>
#include <bits/unique_ptr.h>

namespace home {

    namespace kmeans {

        template<class T>
        class KMeans {
        public:
            typedef std::unique_ptr<std::vector<T>> PointsPtr;
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
                for (auto& meanPoint : *currentMeans) {
                    for (T& point : *data) {
                        point.updateMinDistance(meanPoint);
                    }
                }
            }

            void findNewMeans() {
                currentMeans->clear();
                for(int i = 0; i< numClusters; i++){
                    currentMeans->push_back(Point(i));
                }
                for (T& point: *data) {
                    currentMeans->at(point.getOwnership()) += point;
                }
                for (auto &point: *currentMeans) {
                    point.average();
                }
            }

            // writes out file to given filename
            bool writeOutFile(std::string fileName) const {
                std::cout << "XXXXXXXXX \n \n \n writing file: \n \n \nXXXXXXXX" << fileName << std::endl;
                std::ofstream outFile;
                outFile.open(fileName);
                for (auto &point : *data) {
                    point.prettyPrint(outFile);
                }
                outFile.close();
            }

            // points = a vector to be filled with chosen starting points
            void chooseRandomStartingPoints() {
                std::srand(std::time(NULL));
                std::default_random_engine generator;
                std::uniform_int_distribution<> dis(0, numPoints - 1);
                // finds starting points
                currentMeans =  PointsPtr(new std::vector<T>());
                for (int i = 0; i < numClusters; i++) {
                    // copy value and then update ownership. This will hold each mean as it moves
                    Point newMean(data->at(dis(generator)));
                    newMean.changeOwnership(i);
                    currentMeans->push_back(newMean);
                }
            }

            // used to generate clusters using normal distribution
            void generateClusters() {
                std::srand(std::time(NULL));
                std::cout << "Generating Clusters" << std::endl;
                numPoints = numClusters * pointsPerGenCluster;
                data =  PointsPtr(new std::vector<T>());
                // create vars for normal params
                int mean = 1;
                int stdDev = 1;
                std::default_random_engine generator;
                for (int i = 0; i < numClusters; i++) {
                    std::normal_distribution<double> distribution(mean, stdDev);
                    mean += 3;
                    for (int j = 0; j < pointsPerGenCluster; j++) {
                        data->push_back(Point(distribution(generator), distribution(generator)));
                    }
                }
            }

            bool toWriteOutFile;
            bool toGenerate;
            PointsPtr data;
            PointsPtr currentMeans; // vector of current means
            int numClusters;
            int numPoints;
            const int pointsPerGenCluster = 300;
        };
    }
}

#endif //UNTITLED_KMEANS_H
