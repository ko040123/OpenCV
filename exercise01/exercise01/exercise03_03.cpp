#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Mat operator

int main() {
	Mat image_c = imread("lenna.png");
	Mat image_g = imread("lenna.png", 0);

	threshold(image_c, image_c, 128, 200, THRESH_BINARY);
	threshold(image_g, image_g, 128, 200, THRESH_BINARY);
	
	imshow("Threshold_Gray", image_g);
	imshow("Threshold_Color", image_c);
	
	waitKey(0);
	return 0;
}