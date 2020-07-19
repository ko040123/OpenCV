#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Spatial Filtering

int main() {
	Mat image = imread("Moon.png", 0);
	Mat img_blur, img_sharp;

	GaussianBlur(image, img_blur, Size(5, 5), 3);
	
	addWeighted(image, 1.5, img_blur, -0.5, 0, img_sharp);

	imshow("Image", image);
	imshow("Sharpened", img_sharp);
	
	waitKey(0);
	return 0;
}