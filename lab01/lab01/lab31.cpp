#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Video Segmentation
// Generating average image

int main() {
	VideoCapture capture("background.mp4");
	Mat image, sum, avg;
	int cnt = 2;

	capture >> avg;

	while (true) {
		if (!capture.read(image)) break;
		add(image / cnt, avg * (cnt - 1) / cnt, avg);

		imshow("avg", avg);
		cnt++;
		waitKey(33);
	}
}