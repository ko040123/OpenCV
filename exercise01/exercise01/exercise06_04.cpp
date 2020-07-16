#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Intensity Transformation

float calcGamma(Mat image);

int main() {
	Mat bright = imread("bright.jpg", 0);
	Mat dark = imread("dark.jpg", 0);

	float gam1 = calcGamma(bright); 

	float gam2 = calcGamma(dark);

	MatIterator_<uchar> it, end;
	
	unsigned char pix1[256], pix2[256];

	for (int i = 0; i < 256; i++)
	{
		pix1[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gam1) * 255.0f);
	}
	for (int i = 0; i < 256; i++)
	{
		pix2[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gam2) * 255.0f);
	}


	for (it = bright.begin<uchar>(), end = bright.end<uchar>(); it != end; it++)
	{
		*it = pix1[(*it)];
	}
	for (it =dark.begin<uchar>(), end = dark.end<uchar>(); it != end; it++)
	{
		*it = pix2[(*it)];
	}

	imshow("BRIGHT", bright);
	imshow("DARK", dark);	

	waitKey(0);
	return 0;
}

float calcGamma(Mat image) {
	int avg , sum = 0;
	MatIterator_<uchar> it, end;

	for (it = image.begin<uchar>(), end = image.end<uchar>(); it != end; it++) {
		sum += (*it);
	}
	avg = sum / image.total();

	if (avg < 60) return 0.2;
	else if (avg < 120) return 0.7;
	else if (avg < 180) return 1.7;
	else return 25;
}