#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Drawing Function

int main() {
	Mat image(Size(640, 480), CV_8UC3, Scalar(0, 255, 255));

	Point trapezoid[1][4];
	trapezoid[0][0] = Point(50, 50);
	trapezoid[0][1] = Point(200, 50);
	trapezoid[0][2] = Point(150, 150);
	trapezoid[0][3] = Point(100, 150);

	Point hexagon[1][6];
	hexagon[0][0] = Point(400, 400);
	hexagon[0][1] = Point(500, 400);
	hexagon[0][2] = Point(550, 400 - cvRound(50 * sqrt(3)));
	hexagon[0][3] = Point(500, 400 - cvRound(100 * sqrt(3)));
	hexagon[0][4] = Point(400, 400 - cvRound(100 * sqrt(3)));
	hexagon[0][5] = Point(350, 400 - cvRound(50 * sqrt(3)));
	
	const Point* ppt[2] = { trapezoid[0], hexagon[0] };
	int npt[2] = { 4, 6 };
	int nContours = 2;
	
	fillPoly(image, ppt, npt, nContours, Scalar(0));

	imshow("Image", image);
	waitKey(0);
	return 0;
}