#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Memory management / Pixel Access

int main() {
	Mat image = imread("lenna.png", 0);

	int brightness = image.at<uchar>(Point(100, 120));

	printf("\n\nBrightness at (100, 120) = %d\n\n", brightness);

	waitKey(0);
	return 0;
}