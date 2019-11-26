#include"iostream"
using namespace std;
#include<opencv2/opencv.hpp>
using namespace cv;
int main()
{
Mat input = imread("x1.jpg", 0);
namedWindow("orginal", 0);
imshow("orginal", img);
waitKey(0);
Mat output(input.rows, input.cols, CV_8UC1);
for (int i = 0; i < input.rows; i++)
for (int j = 0; j < input.cols; j++)
output.at<uchar>(i, j) = 255 - input.at<uchar>(i, j);
namedWindow("output", 0);
imshow("output", output);
waitKey(0);
return 0;
}