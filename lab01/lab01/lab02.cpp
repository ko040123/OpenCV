#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// OpenCV imread�� ���� �̹��� �б�
// imread�� second parameter�� 0 -> read img in gray scale.
// imread�� second parameter�� 1 -> read img in color
#if 0 
int main() {
	Mat gray_image, color_image;
	
	gray_image = imread("lenna.png", 0);
	color_image = imread("lenna.png");

	imshow("gray_image", gray_image);
	imshow("color_image", color_image);

	waitKey(0);
	return 0;

}
#endif