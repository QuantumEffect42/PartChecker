#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <memory>
#include <tuple>
#include "../Part/Part.hpp"
#include "../Part/Cutout/Cutout.hpp"

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
        void cutoutDetect(int**, int, int);

    private:
        int difference = 90;
        int lookAhead = 3;
        int testArray[9][9] = {
            {255, 255, 255, 255, 255, 255, 255, 255, 255},
            {255, 255, 255, 255, 255, 255, 255, 255, 255},
            {255, 60, 60, 60, 60, 60, 60, 60, 255},
            {255, 60, 60, 60, 60, 60, 60, 255, 255},
            {255, 60, 60, 60, 60, 60, 255, 255, 255},
            {255, 60, 60, 60, 255, 255, 255, 60, 255},
            {255, 60, 60, 60, 255, 255, 60, 60, 255},
            {255, 60, 60, 60, 255, 60, 60, 60, 255},
            {255, 255, 255, 255, 255, 255, 255, 255, 255},
        };
        // int testArray[9][9] = {
        //     {255, 255, 255, 255, 255, 255, 255, 255, 255},
        //     {255, 255, 255, 255, 255, 255, 255, 255, 255},
        //     {255, 255, 255, 255, 255, 60, 60, 60, 255},
        //     {255, 255, 255, 255, 255, 60, 60, 255, 255},
        //     {255, 255, 255, 255, 255, 60, 255, 255, 255},
        //     {255, 255, 255, 255, 255, 255, 255, 255, 255},
        //     {255, 255, 255, 255, 255, 255, 255, 255, 255},
        //     {255, 255, 255, 255, 255, 255, 255, 255, 255},
        //     {255, 255, 255, 255, 255, 255, 255, 255, 255},
        // };
};