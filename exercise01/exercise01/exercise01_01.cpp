#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Basics of openCV

int main() {
	Mat img_g, img_c;
	img_g = imread("lenna.png",0);
	img_c = imread("lenna.png", 1);
	
	imshow("lena_gray", img_g);
	imshow("lena_color", img_c);

	waitKey(0);
	return 0;
}
