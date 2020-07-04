#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Local (Adaptive) Thresholding

int main() {
	Mat image, binary, adaptive_binary;
	image = imread("lenna.png", 0);

	threshold(image, binary, 150, 255, THRESH_BINARY);
	adaptiveThreshold(image, adaptive_binary, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 85, 15);

	imshow("Input image", image);
	imshow("Binary", binary);
	imshow("Adaptive Binary", adaptive_binary);

	waitKey(0);
	return 0;
}