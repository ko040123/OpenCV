#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Video Segmentation

int main() {

	VideoCapture cap("background.mp4", 0);

	if (!cap.isOpened()) {
		cerr << "Video Loading Failed..!" << endl;
		return -1;
	}

	Mat frame, background, avg;
	vector<Mat> frameList;

	double fps = cap.get(CAP_PROP_FPS);
	int delay = cvRound(1000 / fps);

	
	while (true) {
		cap >> frame;
		if (frame.empty()) break;

		// Saves Recent 10 frames in the vector.
		if (frameList.size() < 10) {
			if (frameList.size() == 0) {
				avg = frame;
				frameList.push_back(frame);
			}

			else {
				frameList.push_back(frame);
				add(frame / frameList.size(), (avg * (frameList.size() - 1)) / frameList.size(), avg);
			}
		}

		else {
			Mat temp = *frameList.begin();
			frameList.erase(frameList.begin());
			frameList.push_back(frame);
			add((frame - temp) / frameList.size(), avg, avg);
		}

		imshow("Background", avg);
		waitKey(delay);

	}
	

	
}
