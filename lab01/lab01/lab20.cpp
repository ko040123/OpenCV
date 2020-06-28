#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Intensity transformation
// Gamma correction

int main() {
	Mat image = imread("lenna.png", 0);
	Mat gamma_img;
	MatIterator_ <uchar> it, end;
	float gamma = 0.5;
	unsigned char pix[256];

	for (int i = 0; i < 256; i++) {
		pix[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gamma) * 255.0f);
	}
	gamma_img = image.clone();

	for (it = gamma_img.begin<uchar>(), end = gamma_img.end<uchar>(); it != end; it++) {
		*it = pix[(*it)];
	}

	imshow("Input image", image);
	imshow("Gamma transformation", gamma_img);

	waitKey(0);
	return 0;
}