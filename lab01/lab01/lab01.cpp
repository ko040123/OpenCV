#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Mat의 Size를 입력하는 방법. (Size()를 사용하면 순서가 바뀜)
// Mat의 type을 입력하는 방법. 
// Mat의 type중 Channel의 개수를 다르게 하는 방법.
// OpenCV에서는 B,G,R 의 순서.
#if 0
int main() {
	int w = 150, h = 100;
	Mat image1(h, w, CV_8UC1, Scalar(255));
	Mat image2(Size(w, h), CV_8UC3, Scalar(0, 255, 0));
	cout << "Size(1): " << image1.size().height << "," << image1.size().width << endl;
	cout << endl;
	cout << "Size(2): " << image2.size().height << "," << image2.size().width << endl;
	imshow("image1", image1);
	imshow("image2", image2);

	waitKey(0);
	return 0;
}
#endif