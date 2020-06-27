#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


// Mat Operator (1)
// Split, cvtColor, merge

int main() {
	Mat image, image_YUV, dst;
	vector<Mat> yuv_channels(3);

	image = imread("lenna.png");

	cvtColor(image, image_YUV, COLOR_BGR2YUV);

	split(image_YUV, yuv_channels);

	merge(yuv_channels, dst);

	imshow("input image", image);
	imshow("Y", yuv_channels[0]);
	imshow("U", yuv_channels[1]);
	imshow("V", yuv_channels[2]);
	imshow("YUV image", dst);

	waitKey(0);
	return 0;
}