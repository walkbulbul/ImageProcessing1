#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>


using namespace cv;
using namespace std;

int main()
{
	Mat org = imread("lena.png");

	Mat gray;

	cvtColor(org, gray, COLOR_BGR2GRAY);
	imshow("Picture", gray);
	imshow("Orginal Picture", org);

	waitKey(0);
	return 0;


}