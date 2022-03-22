#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>


using namespace cv;
using namespace std;

Mat newCont;

void convert(Mat input, Mat output, int depth, float alfa, float beta)

{
	if (depth == -1)
	{

		for (int i = 0; i < input.rows; i++)
		{

			for (int j = 0; j < input.cols; j++)

			{
				if (input.at<Vec3b>(i, j)[0] * alfa + beta > 255)input.at<Vec3b>(i, j)[0] = 255;
				else if (input.at<Vec3b>(i, j)[0] * alfa + beta < 0)input.at<Vec3b>(i, j)[0] = 255;
				else input.at<Vec3b>(i, j)[0] = input.at<Vec3b>(i, j)[0] * alfa + beta;


				if (input.at<Vec3b>(i, j)[1] * alfa + beta > 255)input.at<Vec3b>(i, j)[1] = 255;
				else if (input.at<Vec3b>(i, j)[1] * alfa + beta < 0)input.at<Vec3b>(i, j)[1] = 255;
				else input.at<Vec3b>(i, j)[1] = input.at<Vec3b>(i, j)[1] * alfa + beta;

				if (input.at<Vec3b>(i, j)[2] * alfa + beta > 255)input.at<Vec3b>(i, j)[2] = 255;
				else if (input.at<Vec3b>(i, j)[2] * alfa + beta < 0)input.at<Vec3b>(i, j)[2] = 255;
				else input.at<Vec3b>(i, j)[2] = input.at<Vec3b>(i, j)[2] * alfa + beta;




			}
		}
	}

	else if (depth == 1)
	{
		cvtColor(input, input, COLOR_BGR2GRAY);

		for (int i = 0; i < input.rows; i++)
			for (int j = 0; j < input.cols; j++)
			{
				if (input.at<uchar>(i, j) * alfa + beta > 255)input.at<uchar>(i, j) = 255;
				else if (input.at<uchar>(i, j) * alfa + beta < 0) input.at<uchar>(i, j) = 0;
				else input.at<uchar>(i, j) = input.at<uchar>(i, j) * alfa + beta;

			}
	}

	newCont = input;

}

int main()

{
	Mat orgim = imread("lena.png");
	imshow("Orginal", orgim);

	convert(orgim, newCont, -1, 1, -100);
	imshow("Picture", newCont);

	convert(orgim, newCont, 1, 1, 0);
	imshow("Picture1", newCont);

	waitKey(0);
	return 0;


}