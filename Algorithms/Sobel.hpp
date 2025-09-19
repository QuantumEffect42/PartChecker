#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>

namespace algorithms{
    class Sobel{
        public:
            Sobel(int, int);
            ~Sobel();
            void edgeDetect();
        
        private:
            int convolution(int, int, int);

        private:
            const int gX[3][3] = {
                {1, 0, -1},
                {2, 0, -2},
                {1, 0, -1}
            };

            const int gY[3][3] = {
                {-1, -2, -1}, 
                {0, 0, 0},
                {1, 2, 1}
            };

            const int XSIZE;
            const int YSIZE;

            const int testArray[9][9] = {
                {0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 60, 60, 60, 60, 60, 60, 60, 0},
                {0, 60, 60, 60, 60, 60, 60, 0, 0},
                {0, 60, 60, 60, 60, 60, 0, 0, 0},
                {0, 60, 60, 60, 0, 0, 0, 60, 0},
                {0, 60, 60, 60, 0, 0, 60, 60, 0},
                {0, 60, 60, 60, 0, 60, 60, 60, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0},
            };
    };
}