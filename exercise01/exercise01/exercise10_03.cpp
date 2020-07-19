#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Image Segmentation

int main() {
	Mat src = imread("adaptive.png", 0);
	Mat dst1, dst2, dst3, dst4;

	adaptiveThreshold(src, dst1, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 7, 15);
	adaptiveThreshold(src, dst2, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 11, 15);
	adaptiveThreshold(src, dst3, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 21, 15);
	adaptiveThreshold(src, dst4, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 85, 15);

	
	imshow("Original", src);
	imshow("Dst1", dst1);
	imshow("Dst2", dst2);
	imshow("Dst3", dst3);
	imshow("Dst4", dst4);

	waitKey(0);
	return 0;
}