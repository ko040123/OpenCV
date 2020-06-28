#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Memory management
// Shallow, Deep copy

int main() {
	Mat m1 = (Mat_ <double>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);

	Mat m_shallow = m1;
	Mat m_deep = m1.clone();

	cout << "m1 =\n" << m1 << endl << endl;
	cout << "m_shallow =\n" << m_shallow << endl << endl;
	cout << "m_deep =\n" << m_deep << endl << endl;

	m1.at <double>(0, 0) = 100;

	cout << "m1 =\n" << m1 << endl << endl;
	cout << "m_shallow =\n" << m_shallow << endl << endl;
	cout << "m_deep =\n" << m_deep << endl << endl;

	waitKey(0);
	return 0;	
}