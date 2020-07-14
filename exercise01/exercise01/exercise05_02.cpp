#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Memory management / Pixel Access

int main() {
	Mat image = imread("lenna.png");

	MatIterator_<Vec3b> it = image.begin<Vec3b>();
	MatIterator_<Vec3b> end = image.end<Vec3b>();

	for (it; it != end; it++) {
		(*it)[0] = 255;
	}

	imshow("Image", image);
	
	waitKey(0);
	return 0;
}