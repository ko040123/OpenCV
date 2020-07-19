#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Color Processing

int main() {
	Mat image = imread("lenna.png");
	Mat channels[3], result;
	int sumB = 0, sumG = 0, sumR = 0, avgB, avgG, avgR;

	split(image, channels);

	// Get average of Each B,G,R Channel
	MatIterator_<uchar> it, end;
	for (int i = 0; i < 3; i++) {
		for (it = channels[i].begin<uchar>(), end = channels[i].end<uchar>(); it != end; it++) {
			if (i == 0) sumB += (*it);
			if (i == 1) sumG += (*it);
			if (i == 2) sumR += (*it);			
		}
	}
	avgB = sumB / image.total();
	avgG = sumG / image.total();
	avgR = sumR / image.total();

	// Color balancing w/ gray world assumption
	for (int i = 0; i < image.rows; i++) {
		uchar* b = channels[0].ptr<uchar>(i);
		uchar* g = channels[1].ptr<uchar>(i);
		uchar* r = channels[2].ptr<uchar>(i);
		for (int j = 0; j < image.cols; j++) {
			int b_tmp = (128 * b[j]) / avgB;
			if (b_tmp > 255) b[j] = 255;
			else b[j] = b_tmp;

			int g_tmp = (128 * g[j]) / avgG;
			if (g_tmp > 255) g[j] = 255;
			else g[j] = g_tmp;

			int r_tmp = (128 * r[j]) / avgR;
			if (r_tmp > 255) r[j] = 255;
			else r[j] = r_tmp;
		}		
	}

	merge(channels, 3, result);

	imshow("Original", image);
	imshow("Balancing", result);

	waitKey(0);
	return 0;
}