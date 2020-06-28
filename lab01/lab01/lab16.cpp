#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Pixel Access
// Using Pointer

int main() {
	Mat image = imread("lenna.png");
	int value, value_B, value_G, value_R, channels;
	channels = image.channels();

	uchar* p;
	p = image.ptr<uchar>(50);
	value_B = p[100 * channels + 0];
	value_G = p[100 * channels + 1];
	value_R = p[100 * channels + 2];

	cout << "value at (100, 50): " << value_B << " " << value_G << " " << value_R << endl;

	waitKey(0);
	return 0;
}