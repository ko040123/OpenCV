#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Pixel Access
// Using Data member function 

int main() {
	Mat image;
	int value, value_B, value_G, value_R, channels;

	image = imread("lenna.png");
	channels = image.channels();

	uchar* data = (uchar*)image.data;
	value_B = data[(50 * image.cols + 100) * channels + 0];
	value_G = data[(50 * image.cols + 100) * channels + 1];
	value_R = data[(50 * image.cols + 100) * channels + 2];
	cout << "value at (100, 50): " << value_B << " " << value_G << " " << value_R << endl;

	waitKey(0);
	return 0;
}