#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Mat operator
// Setting ROI

int main() {
	Mat image = imread("lenna.png");
	Mat poly_roi;

	Mat poly_mask = Mat::zeros(image.size(), image.type());
	Point poly[1][4];
	poly[0][0] = Point(226, 100);
	poly[0][1] = Point(286, 100);
	poly[0][2] = Point(316, 300);
	poly[0][3] = Point(196, 300);
	const Point* ppt[1] = { poly[0] };
	int npt[] = { 4 };

	fillPoly(poly_mask, ppt, npt, 1, Scalar(255, 255, 255), 8);
	image.copyTo(poly_roi, poly_mask);
	imshow("polyROI", poly_roi);

	waitKey(0);
	return 0;
}