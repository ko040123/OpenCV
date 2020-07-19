#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Color Processing

int main() {
	Mat img = imread("apple.jpg");
	Mat img_HSV, channels[3];

	cvtColor(img, img_HSV, COLOR_BGR2HSV);
	split(img_HSV, channels);
	
	for (int i = 0; i < img_HSV.rows; i++) {
		for (int j = 0; j < img_HSV.cols; j++) {
			if (channels[0].at<uchar>(i, j) < 150 ) {
				channels[1].at<uchar>(i, j) = 0;
			}
		}
	}
	
	merge(channels, 3, img_HSV);
	cvtColor(img_HSV, img_HSV, COLOR_HSV2BGR);
	imshow("ORIGINAL", img);
	imshow("Color Slicing", img_HSV);
	waitKey(0);
	return 0;
}