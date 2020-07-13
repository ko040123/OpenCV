#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Mat operator

int main() {
	Mat image, image_hsv;
	Mat hsv_channels[3];
	image = imread("lenna.png");
	
	cvtColor(image, image_hsv, COLOR_BGR2HSV);
	split(image_hsv, hsv_channels);

	imshow("Saturation", hsv_channels[1]);
	waitKey(0);
	return 0;
}