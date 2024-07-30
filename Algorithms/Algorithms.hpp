#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <memory>

using namespace cv;

class Algorithms {

    public: 
        Algorithms();
        ~Algorithms();
        int templateCreate(Mat);

    private:
        std::ifstream readFile();
        std::ofstream writeToFile();
        int** edgeScan(Mat);
        void deleteArray(int**, int);
        int** createArray(int, int);
        void cornerDetect(int**);

    private:
        int difference = 60;
        int lookAhead = 3;
        int testArray[9][6] = {
            {255, 255, 255, 255, 255, 255},
            {255, 255, 255, 255, 255, 255},
            {255, 60, 60, 60, 255, 255},
            {255, 60, 60, 60, 255, 255},
            {255, 60, 60, 255, 255, 255},
            {255, 60, 255, 255, 255, 255},
            {255, 60, 60, 255, 255, 255},
            {255, 60, 60, 255, 255, 255},
            {255, 255, 255, 255, 255, 255},
        };
};