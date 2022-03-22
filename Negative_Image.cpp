#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;


int main()

{

	Mat orginal = imread("lena.png");
	Mat negative_bit;

	bitwise_not(orginal, negative_bit);
	imshow("orginal", orginal);
	imshow("Negative", negative_bit);

	waitKey(0);
	return 0;

}