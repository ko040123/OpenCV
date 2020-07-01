#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Spatial filtering
// Using unsharp masking

int main() {
	Mat input = imread("lenna.png");
	Mat gray, blur, sharp;

	cvtColor(input, gray, COLOR_BGR2GRAY);

	GaussianBlur(gray, blur, Size(5, 5), 3);

	addWeighted(gray, 1.5, blur, -0.5, 0, sharp);

	imshow("gray", gray);
	imshow("sharp", sharp);

	waitKey(0);
	return 0;

}
