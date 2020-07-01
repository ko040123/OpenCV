#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat drawHistogram(Mat src);

// Histogram Equalization

int main() {
	Mat image;
	Mat hist_equalized_image;
	Mat hist_graph;
	Mat hist_equalized_graph;

	image = imread("lenna.png", 0);
	if (!image.data) exit(1);

	equalizeHist(image, hist_equalized_image);

	hist_graph = drawHistogram(image);
	hist_equalized_graph = drawHistogram(hist_equalized_image);

	imshow("input Image", image);
	imshow("Hist Equalized Image", hist_equalized_image);
	imshow("Hist Graph", hist_graph);
	imshow("Hist Equalized Graph", hist_equalized_graph);

	waitKey(0);
	return 0;
}

Mat drawHistogram(Mat src) {
	Mat hist, histImage;
	int i, hist_w, hist_h, bin_w, histSize;
	float range[] = { 0, 256 };
	const float* histRange = { range };

	hist_w = 512;
	hist_h = 400;
	histSize = 256;
	bin_w = cvRound((double)hist_w / histSize);

	calcHist(&src, 1, 0, Mat(), hist, 1, &histSize, &histRange);

	histImage = Mat(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));

	normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	for (i = 1; i < histSize; i++) {
		rectangle(histImage, Point(bin_w * i, hist_h), Point(bin_w * i, hist_h - cvRound(hist.at<float>(i))), Scalar(0, 0, 0), 2, 8, 0);
	}
	return histImage;
}