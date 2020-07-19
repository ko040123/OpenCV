#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Color Processing

int main() {
	Mat img_BGR = imread("lenna.png");
	Mat img_HSV = img_BGR.clone();
	Mat channels_BGR[3], channels_HSV[3];
	MatIterator_<uchar> it, end;

	cvtColor(img_BGR, img_HSV, COLOR_BGR2HSV);
	split(img_HSV, channels_HSV);
	split(img_BGR, channels_BGR);

	// Gamma < 1 ===> 전체적으로 어두운 영상을 선명하게 
	// Gamma > 1 ===> 전체적으로 밝은 영상을 선명하게 
	float gamma = 0.5;
	unsigned char pix[256];

	//LUT
	for (int i = 0; i < 256; i++) {
		pix[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gamma) * 255.0f);
	}
	
	// Gamma Correction on Intensity Channel
	for (it = channels_HSV[2].begin<uchar>(), end = channels_HSV[2].end<uchar>(); it != end; it++) {
		*it = pix[(*it)];
	}


	// Gamma Correction On Blue Channel
	for (int i = 0; i < 3; i++) {
		for (it = channels_BGR[i].begin<uchar>(), end = channels_BGR[i].end<uchar>(); it != end; it++) {
			*it = pix[(*it)];
		}
	}

	imshow("IMG_HSV", img_HSV);
	imshow("IMG_BGR", img_BGR);

	waitKey(0);
	return 0;
}