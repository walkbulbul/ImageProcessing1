#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>


using namespace cv;
using namespace std;


int column, row;

int main()
{

	Mat orgImg = imread("lena.png");

	column = orgImg.cols;
	row = orgImg.rows;

	cout << "Column:" << column << endl;

	cout << "Row:" << row << endl;

	namedWindow("Image");

	imshow("Image Window", orgImg);

	waitKey(0);
	destroyWindow("Image");


	return 0;



}