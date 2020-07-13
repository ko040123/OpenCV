#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Mat operator

int main() {
	Mat apple = imread("apple.jpg");
	Mat spine = imread("Fracture_spine");
	
	// Error Occurs
	// 1. Same size
	// 2. Same Num. of channels
	Mat sum = apple + spine;
	imshow("Sum", sum);
	waitKey(0);
	return 0;
}