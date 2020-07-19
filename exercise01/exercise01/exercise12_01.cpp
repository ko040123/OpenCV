#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Morthological Operation

int main() {
	Ptr<BackgroundSubtractor> bg_model = createBackgroundSubtractorMOG2();
	
	VideoCapture cap("background.mp4", 0);
	Mat image, foregroundMask, backgroundImg, foregroundImg;
	Mat element = getStructuringElement(MORPH_CROSS, Size(3, 3));
	
	vector<vector<Point>> contours;
	vector<Vec4i>hierarchy;

	double fps = cap.get(CAP_PROP_FPS);
	int delay = cvRound(1000 / fps);

	while (true) {
		cap >> image;
		//if (image.empty()) break;
		cvtColor(image, image, COLOR_BGR2GRAY);
		if (foregroundMask.empty()) foregroundMask.create(image.size(), image.type());

		bg_model->apply(image, foregroundMask);
		GaussianBlur(foregroundMask, foregroundMask, Size(11, 11), 3.5, 3.5);
		threshold(foregroundMask, foregroundMask, 10, 255, THRESH_BINARY);
		foregroundImg = Scalar::all(0);
		image.copyTo(foregroundImg, foregroundMask);

		erode(foregroundMask, foregroundMask, element);
		morphologyEx(foregroundMask, foregroundMask, MORPH_OPEN, element);

		findContours(foregroundMask, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

		putText(foregroundImg, format("Contour count: %d", contours.size()), Point(30, 30), FONT_HERSHEY_SCRIPT_SIMPLEX, 1, Scalar(255));

		imshow("Foreground Image", foregroundImg);
		imshow("Foreground Mask", foregroundMask);

		waitKey(delay);
	}

}


