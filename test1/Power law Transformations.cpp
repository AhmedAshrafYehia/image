#include<opencv2/opencv.hpp>
#include"iostream"
#include"math.h"
using namespace std;
using namespace cv;
int main()
{
Mat input = imread("x3.jpg", 0);
namedWindow("orginal", 0);
imshow("orginal", input);
waitKey(0);
Mat outputgama1(input.rows, input.cols, CV_8UC1);
Mat outputgama2(input.rows, input.cols, CV_8UC1);
int cons = 1;
////////////apply power law transformation with gama <1/////////////////
for (int r = 0; r < input.rows; r++)
for (int c = 0; c < input.cols; c++)
{
outputgama1.at<uchar>(r, c) = cons*powf(input.at < uchar>(r, c), 0.5);
}
////////////apply power law transformation with gama <1/////////////////
for (int r = 0; r < input.rows; r++)
for (int c = 0; c < input.cols; c++)
{
outputgama2.at<uchar>(r, c) = cons*powf(input.at < uchar>(r, c), 1.5);
}
//////////////////////////////////////////////////////////////////////
namedWindow("after power law transformation with gama <1", 0);
imshow("after power law transformation with gama <1", outputgama1);
waitKey(0);
namedWindow("after power law transformation with gama >1", 0);
imshow("after power law transformation with gama >1", outputgama2);
waitKey(0);
}