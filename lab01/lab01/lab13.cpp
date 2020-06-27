#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Drawing Functions
// putText

int main() {
	Mat image = Mat::zeros(400, 600, CV_8UC3);
	int w = image.cols;
	int h = image.rows;

	putText(image, format("width: %d, height: %d", w, h), Point(50, 80), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 200, 200), 4);
	imshow("image", image);

	waitKey(0);
	return 0;
}