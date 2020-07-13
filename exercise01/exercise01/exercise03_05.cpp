#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Mat operator

int main() {
	Mat image, dst;
	image = imread("apple.jpg");
	cvtColor(image, image, COLOR_BGR2YCrCb);

	inRange(image, Scalar(0, 150, 0), Scalar(255, 255, 160), dst);

	imshow("inRange", dst);
	
	waitKey(0);
	return 0;
}