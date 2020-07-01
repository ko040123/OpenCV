#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Spatial filtering
// Averaging filter

int main() {
	Mat image, avgImg, gaussianImg;
	image = imread("lenna.png");
	
	blur(image, avgImg, Size(5, 5));

	GaussianBlur(image, gaussianImg, Size(5, 5), 1.5);

	imshow("Input image", image);
	imshow("Average image", avgImg);
	imshow("Gaussian blurred image", gaussianImg);

	waitKey(0);
	return 0;
}