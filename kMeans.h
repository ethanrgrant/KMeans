//
// Created by Ethan Grant on 1/1/2018.
//

#ifndef UNTITLED_KMEANS_H
#define UNTITLED_KMEANS_H

template<class T>
class KMeans {
public:
    KMeans(int numClusters, std::vector<T>& data, bool toWriteOutFile)
        : numClusters(numClusters), data(data), toWriteOutFile(toWriteOutFile){}

    bool doKMeans(){
        writeOutFile(std::string("../output/points.txt"));
    }

private:

    bool writeOutFile(std::string fileName){
        std::cout << "XXXXXXXXX \n \n \n writing file: \n \n \nXXXXXXXX" << fileName << std::endl;
        std::ofstream myfile;
        myfile.open(fileName);
        for(auto& point : data){
            point.prettyPrint(myfile);
        }
    }

    void chooseRandomStartingPoints(std::vector<int>& points, int numPoints, int numClusters){
        std::random_device rd;
        std::mt19937 gen(rd);
        std::uniform_int_distribution<> dis(0, numPoints-1);
        for(int i = 0; i< numClusters; i++){
            points[i] = dis(gen);
        }
    }

    bool toWriteOutFile;
    std::vector<T> data;
    int numClusters;
};


#endif //UNTITLED_KMEANS_H
