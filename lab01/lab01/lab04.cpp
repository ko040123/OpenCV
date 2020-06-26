#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Read a video from a Webcam
#if 0
int main() {
	Mat frame;
	VideoCapture cap(0);

	if (!cap.isOpened()) {
		cout << "Capture(Webcam) Couldn't open." << endl;
		return -1;
	}

	while (1) {
		cap >> frame;

		imshow("Webcam", frame);
		waitKey(16);
	}
}
#endif