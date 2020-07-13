#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Basics of openCV

int main() {
	VideoCapture cap_f("background.mp4");
	VideoCapture cap_s("background.mp4");

	if (!cap_f.isOpened() || !cap_s.isOpened()) {
		cerr << "Video open failed" << endl;
		return -1;
	}

	double fps = cap_f.get(CAP_PROP_FPS);
	int delay = cvRound(1000 / fps);
	int delay2 = delay / 2;

	Mat fast_ver, slow_ver;
	int count = 0;

	while (true) {
		cap_f >> fast_ver;
		
		if (count % 4 == 0) cap_s >> slow_ver;

		if (!fast_ver.empty()) {
			imshow("Faster", fast_ver);
		}

		if (slow_ver.empty()) break;

		imshow("Slower", slow_ver);

		waitKey(delay2);
		count++;
	}
}