#include <opencv2/opencv.hpp>
#include <iostream>

#include "Camera/Camera.hpp"
#include "Algorithms/Algorithms.hpp"
#include "Algorithms/Sobel.hpp"

using namespace std;


//NOTE: Greyscaled images use CV_8UC1 (1 channel) Mat where 0 is black and 255 is white

int main(){

    Camera camera;
    Algorithms algoirthm;
    algorithms::Sobel sobel;

    std::string imagePath = "./Images/Test_Image_2.png";

    // std::optional<cv::Mat> image = camera.CaptureGreyImage();

    // if(!image.has_value()){
    //     return -1;
    // }
    // else{
    //     cv::Mat imageMat = image.value();
    //     cv::imshow("Captured Image", imageMat);

    //     std::cout << "Type of Mat: " << imageMat.type() << std::endl;
    //     std::cout << "Image value at index: 17, 17: " << (int)imageMat.at<unsigned char>(17, 17) << std::endl;
    //     std::cout << "Image Mat size " << imageMat.size() << std::endl;
    //     cv::waitKey(0);

    //     algoirthm.templateCreate(imageMat);
    // }

    // cv::Mat image = cv::imread(imagePath, cv::IMREAD_GRAYSCALE);

    // std::cout << "Type of Mat: " << image.type() << std::endl;
    // std::cout << "Image Mat size " << image.size() << std::endl;
    // std::cout << "Image value at index: 17, 17: " << (int)image.at<unsigned char>(17, 17) << std::endl;

    // algoirthm.templateCreate(image);

    // cv::imshow("Test Window", image);

    // cv::waitKey(0);

    sobel.edgeDetect();

    return 0;
}


