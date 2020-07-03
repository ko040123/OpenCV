#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Global Thresholding

int main() {
	Mat image, thresh;
	int thresh_T, low_cnt, low_sum, high_cnt, high_sum, i, j, th;

	thresh_T = 200;
	th = 10;
	low_cnt = high_cnt = low_sum = high_sum = 0;

	image = imread("lenna.png", 0);
	cout << "threshold value" << thresh_T << endl;

	while (1) {
		for (j = 0; j < image.rows; j++) {
			for (i = 0; i < image.cols; i++) {
				if (image.at<uchar>(j, i) < thresh_T) {
					low_sum += image.at<uchar>(j, i);
					low_cnt++;
				}
				else {
					high_sum += image.at<uchar>(j, i);
					high_cnt++;
				}
			}
		}
		if (abs(thresh_T - (low_sum / low_cnt + high_sum / high_cnt) / 2.0f) < th) {
			break;
		}
		else {
			thresh_T = (low_sum / low_cnt + high_sum / high_cnt) / 2.0f;
			cout << "Threshold value" << thresh_T << endl;
			low_cnt = high_cnt = low_sum = high_sum = 0;
		}

	}

	threshold(image, thresh, thresh_T, 255, THRESH_BINARY);

	imshow("Input image", image);
	imshow("thresholding", thresh);
	waitKey(0);
}