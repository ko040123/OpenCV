#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Mat Operator
// convertTo, convertScaleAbs, setTo

int main() {
	Mat image = imread("lenna.png");
	Mat after_convertTo, after_convertScaleAbs;

	imshow("original", image);
	image.convertTo(after_convertTo, CV_16SC1);
	imshow("after convertTo", after_convertTo);

	convertScaleAbs(image, after_convertScaleAbs, 2, 3);
	imshow("after convertScaleAbs", after_convertScaleAbs);

	image.setTo(Scalar(0));
	imshow("after setTo", image);
	waitKey(0);

}