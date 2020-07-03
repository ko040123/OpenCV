#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Glabal Thresholding
// Otsu's Algorithm

int main() {
	Mat image, result;
	image = imread("lenna.png", 0);
	threshold(image, result, 0, 255, THRESH_BINARY | THRESH_OTSU);
	
	imshow("Input image", image);
	imshow("Result", result);

	waitKey(0);
}