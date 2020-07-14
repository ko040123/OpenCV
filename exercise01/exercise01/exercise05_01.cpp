#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Memory management / Pixel Access

int main() {
	Mat image1 = imread("lenna.png");
	Mat image2 = imread("lenna.png");
	Mat image3 = imread("lenna.png");

	// Using At
	for (int i = 0; i < image1.rows; i++) {
		for (int j = 0; j < image1.cols; j++) {
			if (i % 2 == 0) {
				image1.at<Vec3b>(i, j)[0] = 0;
				image1.at<Vec3b>(i, j)[1] = 0;
				image1.at<Vec3b>(i, j)[2] = 255;
			}
		}
	}


	// Using Ptr
	for (int i = 0; i < image2.rows; i++) {
		uchar* ptr = image2.ptr(i);
		for (int j = 0; j < image2.cols; j++) {
			if (i % 2 == 0) {
				ptr[(j * image2.channels()) + 0] = 0;
				ptr[(j * image2.channels()) + 1] = 0;
				ptr[(j * image2.channels()) + 2] = 255;
			}
		}
	}

	// Using Data Member Function
	uchar* data = (uchar*)image3.data;
	for (int i = 0; i < image3.rows; i++) {
		for (int j = 0; j < image3.cols; j++) {
			if (i % 2 == 0) {
				data[(i * image3.cols + j) * image3.channels() + 0] = 0;
				data[(i * image3.cols + j) * image3.channels() + 1] = 0;
				data[(i * image3.cols + j) * image3.channels() + 2] = 255;
			}
		}
	}


	imshow("Using At..", image1);
	imshow("Using Ptr..", image2);
	imshow("Using Dmf..", image3);

	waitKey(0);
	return 0;
}
