#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Erosion and Dilation
// + Opening & Closing

int main() {
	Mat image, erosion, dilation;
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(10, 10));
	// Or MORPH_RECT, MORPH_CROSS

	image = imread("water_coins.jpg", 0);
	threshold(image, image, 128, 255, THRESH_BINARY);

	erode(image, erosion, element);
	dilate(image, dilation, element);

	imshow("Binary image", image);
	imshow("Erosion", erosion);
	imshow("Dilation", dilation);

	Mat opening, closing;
	element = getStructuringElement(MORPH_ELLIPSE, Size(7, 7));

	morphologyEx(image, closing, MORPH_CLOSE, element);
	morphologyEx(image, opening, MORPH_OPEN, element);

	imshow("Opening", opening);
	imshow("Closing", closing);


	
}