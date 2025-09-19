#include "Sobel.hpp"

using namespace algorithms;

//used to initialize the constant values via initializer list
Sobel::Sobel(int xSize, int ySize) : XSIZE(xSize), YSIZE(ySize){
    
}

void Sobel::edgeDetect(){
    int convolutedXArray[8][8] = {
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
        };

    int convolutedYArray[8][8] = {
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
        };

    int combinedArray[8][8] = {
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
        };

    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            convolutedXArray[i][j] = convolution(i+1, j+1, 1);
            std::cout << convolutedXArray[i][j] << ", ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            convolutedYArray[i][j] = convolution(i+1, j+1, 0);
            std::cout << convolutedYArray[i][j] << ", ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            combinedArray[i][j] =  (int) sqrt((convolutedXArray[i][j] * convolutedXArray[i][j]) + (convolutedYArray[i][j] * convolutedYArray[i][j]));
            std::cout << combinedArray[i][j] << ", ";
        }
        std::cout << std::endl;
    }

}

int Sobel::convolution(int x, int y, int xConvolution){

    int sum = 0;

    //apply convolution with Gx kernel
    if(xConvolution == 1){
        sum = (gX[0][0]*testArray[x-1][y+1]) + (gX[0][2]*testArray[x-1][y-1]) + (gX[1][0]*testArray[x][y+1]) + (gX[1][2]*testArray[x][y-1]) + (gX[2][0]*testArray[x+1][y+1]) + (gX[2][2]*testArray[x+1][y-1]);
    }
    //apply convolution with Gy kernel
    else{
        sum = (gY[0][0]*testArray[x-1][y+1]) + (gY[2][0]*testArray[x+1][y+1]) + (gY[0][1]*testArray[x-1][y]) + (gY[2][1]*testArray[x+1][y]) + (gY[0][2]*testArray[x-1][y-1]) + (gY[2][2]*testArray[x+1][y-1]);
    }

    return sum;
}

Sobel::~Sobel(){

}