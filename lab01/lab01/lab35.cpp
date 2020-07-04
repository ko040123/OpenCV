#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Edge Detection
// Canny Edge Operator

int main() {
	Mat image, canny;
	image = imread("lenna.png", 0);

	Canny(image, canny, 190, 200, 3);

	imshow("Input image", image);
	imshow("Canny", canny);

	waitKey(0);
}