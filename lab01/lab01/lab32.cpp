#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Video Segmentation
// Background Subtraction
// Mixture of Gaussian ( Conditional probability )

int main() {
	Ptr<BackgroundSubtractor> bg_model = createBackgroundSubtractorMOG2();
	Mat image, foregroundMask, backgroundImg, foregroundImg;
	VideoCapture cap("background.mp4");

	while (true) {
		cap >> image;
		resize(image, image, Size(640, 480));

		if (foregroundMask.empty())
			foregroundMask.create(image.size(), image.type());

		bg_model->apply(image, foregroundMask);
		GaussianBlur(foregroundMask, foregroundMask, Size(11,11), 3.5, 3.5);
		threshold(foregroundMask, foregroundMask, 10, 255, THRESH_BINARY);
		foregroundImg = Scalar::all(0);
		image.copyTo(foregroundImg, foregroundMask);
		bg_model->getBackgroundImage(backgroundImg);
		
		imshow("foreground mask", foregroundMask);
		imshow("foreground image", foregroundImg);
		
		if (!backgroundImg.empty()) {
			imshow("mean background image", backgroundImg);
		}
		waitKey(33);
	}
}