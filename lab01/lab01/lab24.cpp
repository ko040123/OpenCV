#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Spatial Filtering
// Median Filter

int main() {
	Mat image = imread("saltnpepper.png", 0);
	Mat mf1, mf2;
	imshow("SaltAndPepper", image);
	
	medianBlur(image, mf1, 3);
	imshow("MedianFiltered", mf1);

	medianBlur(image, mf2, 9);
	imshow("MedianFiltered2", mf2);

	waitKey(0);
	return 0;
}