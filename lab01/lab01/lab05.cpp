#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Video Capture class -> get function
#if 0
int main() {
	Mat frame;
	VideoCapture cap;

	if (cap.open("background.mp4") == 0) return -1;
	double fps = cap.get(CAP_PROP_FPS);
	double time_in_msec = 0;
	int curr_frame = 0;
	int total_frames = cap.get(CAP_PROP_FRAME_COUNT);

	// Stop Video after 3sec
	while (time_in_msec < 3000) {
		cap >> frame;
		if (frame.empty()) break;
		time_in_msec = cap.get(CAP_PROP_POS_MSEC);
		curr_frame = cap.get(CAP_PROP_POS_FRAMES);

		// Print current frames over total frames
		cout << "Frames: " << curr_frame << " / " << total_frames << endl;
		imshow("video", frame);

		// Calculate the right delay from given fps
		waitKey(1000 / fps);
	}
	waitKey(0);
	return 0;
}
#endif // 0