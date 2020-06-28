#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Intensity transformation
// Log transformation

int main() {
	Mat image = imread("lenna.png", 0);
	Mat f_img, log_img;
	double c = 1.5f; // Scaling Constant
	image.convertTo(f_img, CV_32F);
	f_img = abs(f_img) + 1;
	
	log(f_img, f_img);
	
	// Normalize image to 0 ~ 255
	normalize(f_img, f_img, 0, 255, NORM_MINMAX);
	
	// Scaling by c, conversion to an unsigned 8-bit type
	convertScaleAbs(f_img, log_img, c);

	imshow("Input image", image);
	imshow("Log transformation", log_img);

	waitKey(0);
	return 0;

}