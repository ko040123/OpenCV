#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Image Segmentation

int main() {
	Mat src = imread("adaptive_1.jpg", 0);
	Mat dst1, dst2, dst3;

	adaptiveThreshold(src, dst1, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 5, 15);
	adaptiveThreshold(src, dst2, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 5, 5);
	adaptiveThreshold(src, dst3, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 33, 15);

	imshow("Original", src);
	imshow("Result_1", dst1);
	imshow("Result_2", dst2);
	imshow("Result_3", dst3);

	waitKey(0);
	return 0;
}