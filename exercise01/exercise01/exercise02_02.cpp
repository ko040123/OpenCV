#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Mat operator

int main() {
	Mat image = imread("sun.jpg");
	Mat image_roi = image(Rect(50, 50, 350, 150));

	image_roi.setTo(Scalar(255, 255, 0));

	imshow("Original", image);
	imshow("ROI", image_roi);

	waitKey(0);
	return 0;
}