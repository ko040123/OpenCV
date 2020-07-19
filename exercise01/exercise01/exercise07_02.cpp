#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Histogram Equalization

Mat drawHist(Mat image);

int main() {
	Mat image = imread("Apple.jpg");
	Mat channels[3];
	Mat R, R_Roi;

	split(image, channels);
	R = channels[2].clone();
	R_Roi = channels[2].clone();

	R_Roi = R_Roi(Rect(Point(160, 140), Point(340, 370)));

	equalizeHist(R, R);
	equalizeHist(R_Roi, R_Roi);

	Mat hist_R = drawHist(R);
	Mat hist_Roi = drawHist(R_Roi);


	imshow("Red_Channel", R);
	imshow("Red_hist", hist_R);
	imshow("Red_ROI", R_Roi);
	imshow("Red_ROI_hist", hist_Roi);

	waitKey(0);
	return 0;
}
Mat drawHist(Mat image) {
	Mat hist, histImage;

	int i, hist_w, hist_h, bin_w, histSize;
	float range[] = { 0, 256 };
	const float* histRange = { range };

	hist_w = 512;
	hist_h = 400;
	histSize = 256;
	bin_w = cvRound((double)hist_w / histSize);

	calcHist(&image, 1, 0, Mat(), hist, 1, &histSize, &histRange);

	histImage = Mat(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));

	normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	for (i = 1; i < histSize; i++) {
		rectangle(histImage, Point(bin_w * i, hist_h), Point(bin_w * i, hist_h - cvRound(hist.at<float>(i))), Scalar(0, 0, 0), 2, 8, 0);
	}

	return histImage;
}