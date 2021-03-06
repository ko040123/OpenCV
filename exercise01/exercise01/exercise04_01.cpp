#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Drawing Function

int main() {
	Mat image = imread("lenna.png");

	Rect face(Point(200, 180), Size(180, 210));

	rectangle(image, face, Scalar(0,255,0), 3);

	imshow("Image", image);

	waitKey(0);
	return 0;
}