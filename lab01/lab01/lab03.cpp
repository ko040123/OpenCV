#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Read a video
// While �� ���� waitKey(33)�� �ǹ� �����غ��� ���� �ٲ㺸��
#if 0
int main() {
	Mat frame;
	VideoCapture cap;

	// Check if Video was read successfully
	if (cap.open("background.mp4") == 0) {
		cout << "No such file..." << endl;
		waitKey(0);
	}

	while (1) {
		cap >> frame;

		// Check if Video is over
		if (frame.empty()) {
			cout << "End of Video" << endl;
			break;
		}
		imshow("video", frame);
		waitKey(33);
	}
}
#endif