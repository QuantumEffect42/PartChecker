#include "Algorithms.hpp"

Algorithms::Algorithms(){}

/**
 * Function that takes in a Mat and will scan the image from top to bottom to mark and store high contrast points
 * These points will then be stored in a file and a graph can then be created to represent each segment
 * The graph edges of the graph will be the euclidean distances between the centres of the points initially, but
 * That could change depending on settings
 */
int Algorithms::templateCreate(Mat image){
    int** checkArray = edgeScan(image);
    return 0;
}

//This function will scan for edges and will write store their (x,y) in a vector so they can be drawn the screen
//An edge will be defined as a certain distance in pixel intensity values. This number should be configurable
//to allow for flexibilty in various conditions. Example: the darker spots of the part are somewhere aroun 160,
//and the intensity distance is 100, an edge will be detected if a surrounding pixel has an intensity of 60 or less

//If we assume we are scanning the image left to right, top to bottom then we 
int** Algorithms::edgeScan(Mat image){
    // const int width = image.cols;
    // const int height = image.rows;

    const int width = sizeof(testArray[0]) / sizeof(int);
    const int height = sizeof (testArray) / sizeof(testArray[0]);

    int** checkArray = createArray(width, height);

    //NOTE: j is the horizontal index, and i is the vertical index
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){

            int rightPixelValue = -1;
            int belowPixelValue = -1;

            //TODO: Add checks here to ensure that we skip over marked nodes if they are already in the 2D array
            //make sure that we're not at the right edge of the image
            if((j + 1) < width && checkArray[i][j+1] == 0){
                // rightPixelValue = (int)image.at<unsigned char>(i, j+1);
                rightPixelValue = testArray[i][j+1];
            }

            //make sure that we're not at the bottom edge of the image
            if((i + 1) < height && checkArray[i+1][j] == 0){
                // belowPixelValue = (int)image.at<unsigned char>(i+1, j);
                belowPixelValue = testArray[i+1][j];
            }

            // int currentPixelValue = (int)image.at<unsigned char>(i, j);
            int currentPixelValue = testArray[i][j];

            if(rightPixelValue != -1){
                if((currentPixelValue - rightPixelValue) > 0 && (currentPixelValue - rightPixelValue) > difference){
                    //mark the right node in the 2D array here
                    checkArray[i][j+1] = 1;
                }
                else if((currentPixelValue - rightPixelValue) < 0 && (currentPixelValue - rightPixelValue) < (difference * -1)){
                    //mark the current node in the 2D array here
                    checkArray[i][j] = 1;
                }
                //do nothing otherwise
            }

            if(belowPixelValue != -1){
                if((currentPixelValue - belowPixelValue) > 0 && (currentPixelValue - belowPixelValue) > difference){
                    //mark the below node in the 2D array here
                    checkArray[i+1][j] = 1;
                }
                else if((currentPixelValue - belowPixelValue) < 0 && (currentPixelValue - belowPixelValue) < (difference * -1)){
                    //mark the current node in the 2D array here
                    checkArray[i][j] = 1;
                }
            }

            std::cout << checkArray[i][j] << ", ";
        }

        std::cout << std::endl;
    }

    return checkArray;
}

/**
 * 8 possible directions of travel between pixels (right, left, up, down, UR, UL, DR, DL)
 * Each of these directions will be associated with a value (2, 4, 5, 3, 8, 9, 6, 7) respectively
 * These directions can then be used to measure the points to their respective frame edges.
 * Direction change points will then be marked with a value 10 so they can be checked against both 
 * the left and top frame edges
 * 
 * This function will need to detect corners to be used in measuring the distances to the frame edges
 * The corners will be marked since we need to test the positions of each corner against the left and top 
 * frame edges.
 * 
 * This function will do the following:
 *  - Scan the array until an edge if found
 *  - It will latch onto the edge pixel and follow the edge until the next pixel is a 0
 *  - It will then mark the pixel it found the potential edge change at and follow the edge further
 *      - If there the cardinal direction changes within a specified distance, for a specified distance, 
 *      - mark the middle point as a edge change
 *      - If the cardinal direction goes back to normal within a specified distance, continue marking as normal
 *  - Once an edge has been completely followed, continue the search and skip over marked pixels
 * 
 * PROBLEMS THAT STILL NEED SOLVING
 *  - Long Curves (May need to be a special case)
 * 
 */
void Algorithms::cornerDetect(int** markedArray){

}

int** Algorithms::createArray(int width, int height){
    int** array = new int*[height];

    for(int i = 0; i < height; i++){
        array[i] = new int[width];
    }

    //zeros the array
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            array[i][j] = 0;
        }
    }

    return array;
}

void Algorithms::deleteArray(int** array, int width){
    for(int i = 0; i < width; i++){
        delete[] array[i];
    }

    delete[] array;
}

Algorithms::~Algorithms(){
}