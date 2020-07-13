#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Mat operator

int main() {
	Mat image = imread("lenna.png", 0);
	Mat img_thresh1, img_thresh2, img_thresh3;

	adaptiveThreshold(image, img_thresh1, 200, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 3, 10);
	adaptiveThreshold(image, img_thresh2, 200, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 5, 10);
	adaptiveThreshold(image, img_thresh3, 200, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 7, 10);

	imshow("Adaptive_Thresh_1", img_thresh1);
	imshow("Adaptive_Thresh_2", img_thresh2);
	imshow("Adaptive_Thresh_3", img_thresh3);
	
	waitKey(0);
	return 0;
}