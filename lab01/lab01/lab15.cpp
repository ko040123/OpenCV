#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Pixel Access
// at operator

int main() {
	Mat image, image_gray;
	int value, value_B, value_G, value_R, channels;

	image = imread("lenna.png");
	image_gray = imread("lenna.png", 0);

	channels = image.channels();

	switch (channels) {
	case 1: 
		value = image.at<uchar>(50, 100);
		cout << "value: " << value;
		break;

	case 3: 
		value_B = image.at<Vec3b>(50, 100)[0];
		value_G = image.at<Vec3b>(50, 100)[1];
		value_R = image.at<Vec3b>(50, 100)[2];
		cout << "value at (100,50): " << value_B << " " << value_G << " " << value_R << endl;
		break;
	}
	waitKey(0);
	return 0;
}