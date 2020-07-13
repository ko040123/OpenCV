#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Basics of openCV

int main() {
	Mat image(Size(1920, 1080), CV_8UC3, Scalar(0,255,255));

	imshow("Image", image);
	waitKey(0);
	return 0;
}