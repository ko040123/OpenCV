#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Intensity Transformation

int main() {
	Mat image1 = imread("Aerial_image.png", 0);
	Mat image2 = imread("Fracture_spine.png", 0);

	Mat gamma_img1, gamma_img2;
	MatIterator_<uchar> it, end;
	
	// Gamma < 1 ===> 전체적으로 어두운 영상을 선명하게 
	// Gamma > 1 ===> 전체적으로 밝은 영상을 선명하게 
	float gamma = 2;
	unsigned char pix[256];

	for (int i = 0; i < 256; i++) {
		pix[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gamma) * 255.0f);
	}
	gamma_img1 = image1.clone();
	gamma_img2 = image2.clone();

	for (it = gamma_img1.begin<uchar>(), end = gamma_img1.end<uchar>(); it != end; it++) {
		*it = pix[(*it)];
	}
	for (it = gamma_img2.begin<uchar>(), end = gamma_img2.end<uchar>(); it != end; it++) {
		*it = pix[(*it)];
	}

	imshow("Image1", gamma_img1);
	imshow("Image2", gamma_img2);

	waitKey(0);
	return 0;
}