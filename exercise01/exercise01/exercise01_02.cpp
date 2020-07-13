#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Basics of openCV

int main() {
	VideoCapture cap("background.mp4");
	
	if (!cap.isOpened()) {
		cerr << "Video open failed!" << endl;
		return;
	}

	double fps = cap.get(CAP_PROP_FPS);
	int delay = cvRound(1000 / fps);

	Mat frame;

	while (true) {
		cap >> frame;
		if (frame.empty()) break;

		imshow("Video", frame);

		waitKey(delay);
	}
}