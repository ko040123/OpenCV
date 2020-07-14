#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Drawing Function

int main() {
	VideoCapture cap("NTH3.mp4");

	if (!cap.isOpened()) {
		cerr << "Video Open failed..!" << endl;
		return -1;
	}

	double fps = cap.get(CAP_PROP_FPS);
	int delay = cvRound(1000 / fps);

	Mat frame;
	int total_frame = cap.get(CAP_PROP_FRAME_COUNT);
	int cur_frame;

	while (true) {
		cap >> frame;

		if (frame.empty()) break;

		cur_frame = cap.get(CAP_PROP_POS_FRAMES);
		string text = format("Current frame: %d, Total frame: %d", cur_frame, total_frame);

		putText(frame, text, Point(50, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0,0,255));
		
		imshow("Video", frame);
		waitKey(delay);
	}
}