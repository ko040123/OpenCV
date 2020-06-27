#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Drawing Functions
// Rectangle

int main() {
	Mat image = imread("lenna.png");
	Rect rect = Rect(10, 10, 100, 100);
	rectangle(image, rect, Scalar(0, 255, 0), 4, 8, 0);

	imshow("image", image);

	waitKey(0);
	return 0;
}