#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Color Processing
// Pseudo coloring

int main() {
	Mat gray = imread("moon.jpg", 0);
	Mat color;

	applyColorMap(gray, color, COLORMAP_SUMMER);
	imshow("gray", gray);
	imshow("color", color);

	waitKey(0);
	return 0;
}