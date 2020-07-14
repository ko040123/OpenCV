#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Drawing Function

int main() {
	VideoCapture cap("road.mp4");

	if (!cap.isOpened()) {
		cerr << "Video open failed..!" << endl;
		return -1;
	}

	Mat frame;
	double fps = cap.get(CAP_PROP_FPS);
	int delay = cvRound(1000 / fps);

	while (true) {
		cap >> frame;

		if (frame.empty()) break;

		line(frame, Point(frame.cols / 2 - 100, 0), Point(frame.cols / 2 + 200, frame.rows), Scalar(50, 50, 200), 3);
		line(frame, Point(frame.cols / 2 + 100, 0), Point(frame.cols / 2 - 200, frame.rows), Scalar(50, 50, 200), 3);

		imshow("Video", frame);
		waitKey(delay);
	}

}