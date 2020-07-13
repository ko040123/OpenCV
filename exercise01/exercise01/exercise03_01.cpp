#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Mat operator

int main() {
	Mat lenna = imread("lenna.png");
	Mat apple = imread("apple.jpg");
	
	Mat sub = lenna - apple;
	Mat abs;
	absdiff(apple, lenna, abs);

	imshow("Subtract", sub);
	imshow("absdiff", abs);

	waitKey(0);
	return 0;
}