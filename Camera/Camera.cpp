#include "Camera.hpp"

Camera::Camera(){

}

//Wrap the Mat in an optional for Null type safety in case the camera can't be opened
std::optional<Mat> Camera::CaptureGreyImage(){
    std::optional<Mat> imageOptional = std::nullopt;
    Mat frame;
    namedWindow("Captured Image");

    VideoCapture cap(0);
    cap.set(CAP_PROP_FRAME_HEIGHT, 1080);
    cap.set(CAP_PROP_FRAME_WIDTH, 1920);

    if(!cap.isOpened()){ //check to make sure the camera device is found
        std::cout << "No video stream detected" << std::endl;
        return imageOptional;
    }

    //checks for success code for reading a frame from the camera
    if(!cap.read(frame)){
        std::cout << "Can't capture image from camera" << std::endl;
        return imageOptional;
    }

    Mat greyScale;
    cvtColor(frame, greyScale, cv::COLOR_BGR2GRAY);

    //release the previous Mat and the camera device
    cap.release();
    frame.release();

    imageOptional = greyScale;

    return imageOptional;
}

Camera::~Camera(){

}