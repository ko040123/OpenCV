#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Image Segmentation

int main() {
	Mat image = imread("Finger.png", 0);
	Mat result;

	threshold(image, result, 0, 255, THRESH_BINARY | THRESH_OTSU);

	imshow("Original", image);
	imshow("Result", result);
	waitKey(0);
	return 0;

}