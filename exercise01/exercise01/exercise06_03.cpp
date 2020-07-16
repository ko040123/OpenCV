#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Intensity Transformation

int main() {
	Mat image = imread("reverse_light_1.jpg", 0);
	Mat gamma_img;
	MatIterator_<uchar> it, end;

	// Gamma < 1 ===> ��ü������ ��ο� ������ �����ϰ� 
	// Gamma > 1 ===> ��ü������ ���� ������ �����ϰ� 
	float gamma = 0.5;
	unsigned char pix[256];
	
	gamma_img = image.clone();

	for (int i = 0; i < 256; i++)
	{
		pix[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gamma) * 255.0f);
	}
	for (it = gamma_img.begin<uchar>(), end = gamma_img.end<uchar>(); it != end; it++)
	{
		*it = pix[(*it)];
	}

	image = image + 50;
	imshow("ADD", image);
	imshow("GAMMA", gamma_img);

	waitKey(0);
	return 0;	
}