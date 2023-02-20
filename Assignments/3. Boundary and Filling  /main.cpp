#include <iostream>
#include <opencv2/opencv.hpp>
#include <array>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/quality/qualitypsnr.hpp>
#include <vector>
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

int main() {
    
    Mat image = imread("/Users/seoyeong/Desktop/Resource/Profile.png", IMREAD_GRAYSCALE);
    
    
    int morph_size = 2;
    Mat element = getStructuringElement(MORPH_RECT,Size(2 * morph_size + 1,2 * morph_size + 1), Point(morph_size, morph_size));
    Mat output;
    // Gradient
    
    morphologyEx(image, output,MORPH_GRADIENT, element,Point(-1, -1), 1);
    
    imshow("1", image);
    imshow("2", output);
    waitKey();
    
    
    return 0;
}
