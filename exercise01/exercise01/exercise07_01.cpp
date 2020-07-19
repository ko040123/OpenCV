#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Histogram Equalization

void drawHist(Mat hist);

int main() {
	Mat hist;
	Mat image = imread("Moon.png", 0);
	
	if (!image.data) {
		cerr << "Image Loading Failed..!" << endl;
		return -1;
	}

	drawHist(image);

	imshow("Image", image);

	waitKey(0);
	return 0;	
}

void drawHist(Mat image) {
	Mat hist, histImage;

	int i, hist_w, hist_h, bin_w, histSize;
	float range[] = { 0, 256 };
	const float* histRange = { range };

	hist_w = 512;
	hist_h = 400;
	histSize = 16;
	bin_w = cvRound((double)hist_w / histSize);

	calcHist(&image, 1, 0, Mat(), hist, 1, &histSize, &histRange);

	histImage = Mat(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));

	normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	for (i = 1; i < histSize; i++) {
		rectangle(histImage, Point(bin_w * i, hist_h), Point(bin_w * i, hist_h - cvRound(hist.at<float>(i))), Scalar(0, 0, 0), 2, 8, 0);
	}

	imshow("HISTIMAGE", histImage);
}