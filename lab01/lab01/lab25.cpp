#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Color Processing
// Usage of HSI

int main() {
	Mat image = imread("colorful.jpg");
	Mat HSV, intensity_change, mask_out, change_color;
	vector<Mat> ic(3);
	vector<Mat> mo(3);
	vector<Mat> cc(3);

	int rows = image.rows;
	int cols = image.cols;
	uchar* h;
	uchar* s;
	uchar* v;

	cvtColor(image, HSV, COLOR_BGR2HSV);
	split(HSV, ic);
	split(HSV, mo);
	split(HSV, cc);

	equalizeHist(ic[2], ic[2]);

	// Masking out except Orange Color
	for (int i = 0; i < rows; i++) {
		h = mo[0].ptr<uchar>(i);
		s = mo[1].ptr<uchar>(i);
		for (int j = 0; j < cols; j++) {
			if (h[j] > 9 && h[j] < 23) s[j] = s[j];
			else s[j] = 0;
		}
	}

	// Changing all colors
	for (int i = 0; i < rows; i++) {
		h = cc[0].ptr<uchar>(i);
		s = cc[1].ptr<uchar>(i);
		for (int j = 0; j < cols; j++) {
			if (h[j] + 50 > 255) h[j] = h[j] + 50 - 255;
			else h[j] += 50;
		}
	}

	merge(ic, intensity_change);
	merge(mo, mask_out);
	merge(cc, change_color);

	cvtColor(intensity_change, intensity_change, COLOR_HSV2BGR);
	cvtColor(mask_out, mask_out, COLOR_HSV2BGR);
	cvtColor(change_color, change_color, COLOR_HSV2BGR);

	imshow("image", image);
	imshow("intensity change", intensity_change);
	imshow("mask out", mask_out);
	imshow("change color", change_color);

	waitKey(0);
	return 0;
}