#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Mat Operator
// Threshold operation

int main() {
	Mat image = imread("lenna.png");
	Mat dst;

	cvtColor(image, image, COLOR_BGR2GRAY);
	
	threshold(image, dst, 100, 255, THRESH_BINARY);

	imshow("dst", dst);
	imshow("image", image);

	waitKey(0);
	return 0;
}