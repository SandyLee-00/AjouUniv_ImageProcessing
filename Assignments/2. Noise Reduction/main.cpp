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
    
    Mat uniform10 = imread("/Users/seoyeong/Desktop/Resource/Noise/uniform_0.10.png", 0);
    Mat uniform15 = imread("/Users/seoyeong/Desktop/Resource/Noise/uniform_0.15.png", 0);
    Mat uniform20 = imread("/Users/seoyeong/Desktop/Resource/Noise/uniform_0.20.png", 0);
    
    // image type / 0 10 / 1 15 / 2 20
    // blur type / 0 GaussianBlur / 1 bilateralFilter / 2 medianBlur
    // paratemter type / 0 3 / 1 5 / 2 7
    
    Mat UniformNoise[3][3][3];
    
    TickMeter size3;
    size3.start();
    
    GaussianBlur(uniform20, UniformNoise[2][0][0], Size(3,3), 0);
    
    size3.stop();
    cout << "size3: " << size3.getTimeSec() << endl;
    
    TickMeter size5;
    size5.start();
    
    GaussianBlur(uniform20, UniformNoise[2][0][1], Size(5,5), 0);

    size5.stop();
    cout << "size5: " << size5.getTimeSec() << endl;
    
    TickMeter size7;
    size7.start();
    
    GaussianBlur(uniform20, UniformNoise[2][0][2], Size(7,7), 0);

    size7.stop();
    cout << "size7: " << size7.getTimeSec() << endl;

    imwrite("/Users/seoyeong/Desktop/Resource/Noise_results/UniformNoise[2][0][0].png", UniformNoise[2][0][0]);
    imwrite("/Users/seoyeong/Desktop/Resource/Noise_results/UniformNoise[2][0][1].png", UniformNoise[2][0][1]);
    imwrite("/Users/seoyeong/Desktop/Resource/Noise_results/UniformNoise[2][0][2].png", UniformNoise[2][0][2]);
    
    waitKey();
    
    
    return 0;
}
