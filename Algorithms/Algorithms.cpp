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
    const int width = image.cols;
    const int height = image.rows;

    // for(int i = 0; i < height; i++){
    //     for(int j = 0; j < width; j++){
    //         std::cout << (int)image.at<unsigned char>(i, j) << ", ";
    //     }
    //     std::cout << std::endl;
    // }

    // std::cout << std::endl;

    // const int width = sizeof(testArray[0]) / sizeof(int);
    // const int height = sizeof (testArray) / sizeof(testArray[0]);

    for(int i = 0; i < width; i++){
        std::cout << i - 1 << ", ";
    }
    std::cout << std::endl;

    int** checkArray = createArray(width, height);

    //NOTE: j is the horizontal index, and i is the vertical index
    for(int i = 0; i < height; i++){
        std::cout << i << ": ";

        for(int j = 0; j < width; j++){
            int rightPixelValue = -1;
            int belowPixelValue = -1;

            //TODO: Add checks here to ensure that we skip over marked nodes if they are already in the 2D array
            //make sure that we're not at the right edge of the image
            if((j + 1) < width && checkArray[i][j+1] == 0){
                rightPixelValue = (int)image.at<unsigned char>(i, j+1);
                // rightPixelValue = testArray[i][j+1];
            }

            //make sure that we're not at the bottom edge of the image
            if((i + 1) < height && checkArray[i+1][j] == 0){
                belowPixelValue = (int)image.at<unsigned char>(i+1, j);
                // belowPixelValue = testArray[i+1][j];
            }

            int currentPixelValue = (int)image.at<unsigned char>(i, j);
            // int currentPixelValue = testArray[i][j];

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

    cutoutDetect(checkArray, width, height);

    return checkArray;
}

/**
 * This function is responsible for creating a new part object which will hold all the information
 * about the cutouts and their edge information as well as keep a count of the total number of cutouts
 * detected in the scanned part. The x and y position of the edge pixel will be given to the cutout for
 * easy computation of the distance to and from the edges
 * 
 * This function will work by scanning the array with the marked edges to until an edge is found. Once an edge
 * is found, it will be followed until the starting point is reached again. Once this the entire cutout has
 * been traced, it will resume searching until the next one is found. This will ensure that all the cutouts are
 * accounted for
 */
void Algorithms::cutoutDetect(int** markedArray, int width, int height){
    Part part;

    std::tuple<int, int> edgePoint;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){

            //if we find part of the edge of a cutout
            if(markedArray[i][j] == 1){
                std::tuple<int, int> currentPoint = std::make_tuple(j, i);

                std::shared_ptr<Cutout> cutout(new Cutout);
                cutout->addPointToEdge(j, i);
                
                while(true){
                    markedArray[std::get<1>(currentPoint)][std::get<0>(currentPoint)] = 2;

                    //check right
                    if(!((std::get<0>(currentPoint)+1) >= width) && markedArray[std::get<1>(currentPoint)][std::get<0>(currentPoint) + 1] == 1){
                        std::get<0>(currentPoint) = std::get<0>(currentPoint) + 1;

                        cutout->addPointToEdge(std::get<0>(currentPoint), std::get<1>(currentPoint));
                    }
                    //check down
                    else if(!((std::get<1>(currentPoint)+1) >= height) && markedArray[std::get<1>(currentPoint) + 1][std::get<0>(currentPoint)] == 1){
                        std::get<1>(currentPoint) = std::get<1>(currentPoint) + 1;

                        cutout->addPointToEdge(std::get<0>(currentPoint), std::get<1>(currentPoint));
                    }
                    //check left
                    else if(!((std::get<0>(currentPoint)-1) <= 0) && markedArray[std::get<1>(currentPoint)][std::get<0>(currentPoint) - 1] == 1){
                        std::get<0>(currentPoint) = std::get<0>(currentPoint) - 1;

                        cutout->addPointToEdge(std::get<0>(currentPoint), std::get<1>(currentPoint));
                    }
                    //check top
                    else if(!((std::get<1>(currentPoint)-1) <= 0) && markedArray[std::get<1>(currentPoint) - 1][std::get<0>(currentPoint)] == 1){
                        std::get<1>(currentPoint) = std::get<1>(currentPoint) - 1;

                        cutout->addPointToEdge(std::get<0>(currentPoint), std::get<1>(currentPoint));
                    }
                    //check down-right
                    else if(!((std::get<0>(currentPoint)+1) >= width) && !((std::get<1>(currentPoint)+1) >= height) && markedArray[std::get<1>(currentPoint) + 1][std::get<0>(currentPoint) + 1] == 1){
                        std::get<0>(currentPoint) = std::get<0>(currentPoint) + 1;
                        std::get<1>(currentPoint) = std::get<1>(currentPoint) + 1;

                        cutout->addPointToEdge(std::get<0>(currentPoint), std::get<1>(currentPoint));
                    }
                    //check down-left
                    else if(!((std::get<0>(currentPoint)-1) <= 0) && !((std::get<1>(currentPoint)+1) >= height) && markedArray[std::get<1>(currentPoint) + 1][std::get<0>(currentPoint) - 1] == 1){
                        std::get<0>(currentPoint) = std::get<0>(currentPoint) - 1;
                        std::get<1>(currentPoint) = std::get<1>(currentPoint) + 1;

                        cutout->addPointToEdge(std::get<0>(currentPoint), std::get<1>(currentPoint));
                    }
                    //check top-left
                    else if(!((std::get<0>(currentPoint)-1) <= 0) && !((std::get<1>(currentPoint)-1) <= 0) && markedArray[std::get<1>(currentPoint) - 1][std::get<0>(currentPoint) - 1] == 1){
                        std::get<0>(currentPoint) = std::get<0>(currentPoint) - 1;
                        std::get<1>(currentPoint) = std::get<1>(currentPoint) - 1;

                        cutout->addPointToEdge(std::get<0>(currentPoint), std::get<1>(currentPoint));
                    }
                    //check top-right
                    else if(!((std::get<0>(currentPoint)+1) >= width) && !((std::get<1>(currentPoint)-1) <= 0) && markedArray[std::get<1>(currentPoint) - 1][std::get<0>(currentPoint) + 1] == 1){
                        std::get<0>(currentPoint) = std::get<0>(currentPoint) + 1;
                        std::get<1>(currentPoint) = std::get<1>(currentPoint) - 1;

                        cutout->addPointToEdge(std::get<0>(currentPoint), std::get<1>(currentPoint));
                    }
                    else{
                        break;
                    }
                }

                std::cout << "edgePoints size: " << cutout->getEdgePoints().size() << std::endl;
                cutout->toString();

                part.addCutout(cutout);
            }
        }
    }

    std::cout << "Part cutout count: " << part.getCutoutSize() << std::endl;

    // for(int i = 0; i < height; i++){
    //     for(int j = 0; j < width; j++){
    //         std::cout << markedArray[i][j] << ", ";
    //     }
    //     std::cout << std::endl;
    // }
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