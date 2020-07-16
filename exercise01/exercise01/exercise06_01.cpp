#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Intensity Transformation

int main() {
	Mat image = imread("Binary.png", 0);

	image = ~image;

	imshow("Image", image);

	waitKey(0);
	return 0;
}