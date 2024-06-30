#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

class Camera {
    public:
        Camera();
        ~Camera();
        std::optional<Mat> CaptureGreyImage();
};
