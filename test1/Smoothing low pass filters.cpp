#include"iostream"
#include"math.h"
using namespace std;
#include<opencv2/opencv.hpp>
using namespace cv;
int r, c;
int main()
{
Mat input = imread("x4.jpg", 0);
namedWindow("orginal", 0);
imshow("orginal", input);
waitKey(0);
Mat output(input.rows, input.cols, CV_8UC1,Scalar(0));
Mat outputT5(input.rows, input.cols, CV_8UC1);
Mat outputc(input.rows, input.cols, CV_8UC1);
Mat outputp(input.rows, input.cols, CV_8UC1);
Mat outputc5(input.rows, input.cols, CV_8UC1);
////////////////////////////3*3 filter///////////////////////////////
for (r= 1; r < input.rows-1; r++)
for (c = 1; c < input.cols-1; c++)
{
output.at<uchar>(r, c) = 1.0/9.0 *(input.at<uchar>(r - 1, c- 1) +
input.at<uchar>(r - 1, c) + input.at<uchar>(r - 1, c + 1)+
input.at<uchar>(r, c - 1) + input.at<uchar>(r, c) +
input.at<uchar>(r, c + 1) + input.at<uchar>(r + 1, c - 1) + input.at<uchar>(r + 1, c) + input.at<uchar>(r + 1, c + 1));
}
//////////////5*5 tradtional filter///////////////////////////////
for (int i = 2; i < input.rows - 2; i++)
for (int j = 2; j < input.cols - 2; j++)
{
outputT5.at<uchar>(i, j) = 1.0 / 25.0 *(
input.at<uchar>(i - 2, j - 2) + input.at<uchar>(i - 2, j - 1) + input.at<uchar>(i - 2, j) + input.at<uchar>(i - 2, j + 1) + input.at<uchar>(i - 2, j + 2) +input.at<uchar>(i - 1, j - 2) + input.at<uchar>(i - 1, j - 1) + input.at<uchar>(i - 1, j) + input.at<uchar>(i - 1, j + 1) + input.at<uchar>(i - 1, j + 2) +
input.at<uchar>(i, j - 2) + input.at<uchar>(i, j - 1) + input.at<uchar>(i, j) + input.at<uchar>(i, j + 1) +
input.at<uchar>(i, j + 2) + input.at<uchar>(i + 1, j - 2) + input.at<uchar>(i + 1, j - 1) + input.at<uchar>(i + 1, j) + input.at<uchar>(i + 1, j + 1) + input.at<uchar>(i + 1, j + 2) + input.at<uchar>(i + 2, j - 2) + input.at<uchar>(i + 2, j - 1) + input.at<uchar>(i + 2, j) + input.at<uchar>(i + 2, j + 1) + input.at<uchar>(i + 2, j + 2));
}
////////////////5*5 Circular filter///////////////////////////////
for (int i = 2; i < input.rows - 2; i++)
for (int j = 2; j < input.cols - 2; j++)
{
outputc5.at<uchar>(i, j) = 1.0 / 21.0 *(
input.at<uchar>(i - 2, j - 2)*0 + input.at<uchar>(i - 2, j - 1)*1 + input.at<uchar>(i - 2, j)*1 + input.at<uchar>(i - 2, j + 1)*1 + input.at<uchar>(i - 2, j + 2)*0 + input.at<uchar>(i - 1, j - 2)*1 + input.at<uchar>(i - 1, j - 1)*1 + input.at<uchar>(i - 1, j)*1 + input.at<uchar>(i - 1, j + 1)*1 + input.at<uchar>(i - 1, j + 2)*1 +
input.at<uchar>(i , j - 2)*1 + input.at<uchar>(i , j - 1)*1 + input.at<uchar>(i , j)*1 + input.at<uchar>(i , j + 1)*1 + input.at<uchar>(i , j + 2)*1 + input.at<uchar>(i + 1, j - 2)*1 + input.at<uchar>(i + 1, j - 1)*1 + input.at<uchar>(i + 1, j)*1 + input.at<uchar>(i + 1, j + 1)*1 + input.at<uchar>(i + 1, j + 2)*1 +
input.at<uchar>(i + 2, j - 2)*0 + input.at<uchar>(i + 2, j - 1)*1 + input.at<uchar>(i + 2, j)*1 + input.at<uchar>(i + 2, j + 1)*1 + input.at<uchar>(i + 2, j + 2)*0);
}
///////////////Pyramidal filter///////////////////////////////
for (int i = 2; i < input.rows - 2; i++)
for (int j = 2; j < input.cols - 2; j++)
{
outputp.at<uchar>(i, j) = 1.0 / 81.0 *(
input.at<uchar>(i - 2, j - 2)*1 + input.at<uchar>(i - 2, j - 1)*2 + input.at<uchar>(i - 2, j)*3 + input.at<uchar>(i - 2, j + 1)*2 + input.at<uchar>(i - 2, j + 2)*1 + input.at<uchar>(i - 1, j - 2)*2 + input.at<uchar>(i - 1, j - 1)*4 + input.at<uchar>(i - 1, j)*6 + input.at<uchar>(i - 1, j + 1)*4 + input.at<uchar>(i - 1, j + 2)*2 +
input.at<uchar>(i , j - 2)*3 + input.at<uchar>(i , j - 1)*6 + input.at<uchar>(i , j)*9 + input.at<uchar>(i , j + 1)*6 + input.at<uchar>(i , j + 2)*3 + input.at<uchar>(i + 1, j - 2)*2 + input.at<uchar>(i + 1, j - 1)*4 + input.at<uchar>(i + 1, j)*6 + input.at<uchar>(i + 1, j + 1)*4 + input.at<uchar>(i + 1, j + 2)*2 +
input.at<uchar>(i + 2, j - 2)*1 + input.at<uchar>(i + 2, j - 1)*2 + input.at<uchar>(i + 2, j)*3 + input.at<uchar>(i + 2, j + 1)*2 + input.at<uchar>(i + 2, j + 2)*1);
}
///////////////////////cone filter///////////////////////////////
for (int i = 2; i < input.rows - 2; i++)
for (int j = 2; j < input.cols - 2; j++)
{
outputc.at<uchar>(i, j) = 1.0 / 25.0 *(
input.at<uchar>(i - 2, j - 2)*0 + input.at<uchar>(i - 2, j - 1)*0 + input.at<uchar>(i - 2, j)*1 + input.at<uchar>(i - 2, j + 1)*0 + input.at<uchar>(i - 2, j + 2)*0 + input.at<uchar>(i - 1, j - 2)*0 + input.at<uchar>(i - 1, j - 1)*2 + input.at<uchar>(i - 1, j)*2 + input.at<uchar>(i - 1, j + 1)*2 + input.at<uchar>(i - 1, j + 2)*0 +
input.at<uchar>(i , j - 2)*1 + input.at<uchar>(i , j - 1)*2 + input.at<uchar>(i , j)*5 + input.at<uchar>(i , j + 1)*2 + input.at<uchar>(i , j + 2)*1 + input.at<uchar>(i + 1, j - 2)*0 + input.at<uchar>(i + 1, j - 1)*2 + input.at<uchar>(i + 1, j)*2 + input.at<uchar>(i + 1, j + 1)*2 + input.at<uchar>(i + 1, j + 2)*0 +
input.at<uchar>(i + 2, j - 2)*0 + input.at<uchar>(i + 2, j - 1)*0 + input.at<uchar>(i + 2, j)*1 + input.at<uchar>(i + 2, j + 1)*0 + input.at<uchar>(i + 2, j + 2)*0);
}
namedWindow("output", 0);
imshow("output", output);
waitKey(0);
namedWindow("output tradtional 5", 0);
imshow("output tradtional 5", outputT5);
waitKey(0);
namedWindow("output prymidial", 0);
imshow("output prymidial", outputp);
waitKey(0);
namedWindow("output cone", 0);
imshow("output cone", outputc);
waitKey(0);
namedWindow("output circle", 0);
imshow("output circle", outputc5);
waitKey(0);
return 0;
}