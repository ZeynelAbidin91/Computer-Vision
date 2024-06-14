#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

const int MAX_VALUE_H = 360 / 2;
const int MAX_VALUE = 255;

int main()
{
    string image_path1 = "C:/Users/zeyne/opencvtest/lenna.png";

    Mat image1 = imread(image_path1, IMREAD_COLOR);
    resize(image1, image1, {500, 500});

    if (image1.empty())
    {
        cout << " Could not read the image: " << endl;
        return 1;
    }

    vector<int> lower_bound = {170, 80, 50};

    int low_H = lower_bound[0], low_S = lower_bound[1], low_V = lower_bound[2];
    int high_H = MAX_VALUE_H, high_S = MAX_VALUE, high_V = MAX_VALUE;

    Mat hsvImg, imgThreshold;

    // Conver from BGR to HSV colorspace
    cvtColor(image1, hsvImg, COLOR_BGR2HSV);
    // Detect the object based on HSV range values
    inRange(hsvImg, Scalar(low_H, low_S, low_V), Scalar(high_H, high_S, high_V), imgThreshold);

    Mat medianBlurImg, gaussianBlurImg;
    medianBlur(image1, medianBlurImg, 3);
    GaussianBlur(image1, gaussianBlurImg, Size(3,3), 9, 9);

    imshow("Original Image", image1);
    imshow("Median Blurred Image", medianBlurImg);
    imshow("Gaussian Blurred Image", gaussianBlurImg);

    imshow("HSV image", hsvImg);
    imshow("Threshold Image", imgThreshold);

    int k = waitKey(0); // Wait for keystroke in the window

    if (k == 'q'){
        destroyAllWindows();
    }
    return 0;
}