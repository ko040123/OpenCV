#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Spatial Filtering

int main() {
	Mat image = imread("saltnpepper.png", 0);
	Mat img_med, img_avg;

	medianBlur(image, img_med, 7);
	blur(image, img_avg, Size(7, 7));

	imshow("img_med", img_med);
	imshow("img_avg", img_avg);

	waitKey(0);
	return 0;
}