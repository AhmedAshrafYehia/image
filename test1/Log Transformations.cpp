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
Mat output(input.rows, input.cols, CV_8UC1);
double cons = 255 / (log10(1 + 255));
////////////////////////////apply log transformation//////////////////////////
for (int r = 0; r < input.rows; r++)
for (int c = 0; c < input.cols; c++)
{
output.at<uchar>(r, c) = cons * log10f(1 + input.at < uchar>(r, c));
}
namedWindow("after log transformation", 0);
imshow("after log transformation", output);
waitKey(0);
}