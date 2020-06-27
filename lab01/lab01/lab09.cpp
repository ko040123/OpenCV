#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Mat Operation
// Adaptive Threshold

int main() {
	Mat image = imread("lenna.png");
	cvtColor(image, image, COLOR_BGR2GRAY);
	Mat dst;

	adaptiveThreshold(image, dst, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 7, 10);

	imshow("dst", dst);
	imshow("image", image);

	waitKey(0);
	return 0;
}