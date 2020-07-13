#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Mat operator

int main() {
	VideoCapture cap("night.mp4");
	
	if (!cap.isOpened()) {
		cerr << "Video open failed..!" << endl;
		return -1;
	}

	double fps = cap.get(CAP_PROP_FPS);
	int delay = cvRound(1000 / fps);

	Mat frame, csa_frame;

	while (true) {
		cap >> frame;
		if (frame.empty()) break;

		convertScaleAbs(frame, csa_frame, 5, 10);

		imshow("ConvertScaleAbs", csa_frame);
		waitKey(delay);
	}

}