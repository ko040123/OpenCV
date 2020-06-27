#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Drawing Functions
// fillPoly

int main() {
	Mat image = Mat::zeros(400, 400, CV_8UC3);
	int w = 400;

	Point trapezoid[1][4];
	trapezoid[0][0] = Point(w * 2 / 6, w / 4);
	trapezoid[0][1] = Point(w * 4 / 6, w / 4);
	trapezoid[0][2] = Point(w * 5 / 6, w * 3 / 4);
	trapezoid[0][3] = Point(w / 6, w * 3 / 4);

	const Point* ppt[1] = { trapezoid[0] };
	int npt[] = { 4 };

	fillPoly(image, ppt, npt, 1, Scalar(255, 255, 255), 8);
	imshow("image", image);

	waitKey(0);
	return 0;
}