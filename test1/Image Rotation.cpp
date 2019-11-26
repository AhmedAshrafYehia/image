#include"iostream"
using namespace std;
#include<opencv2/opencv.hpp>
using namespace cv;
int r;
int c;
int main()
{
Mat input = imread("R.jpg", 0);
Mat ImR90(input.cols, input.rows, CV_8UC1);//image after R90
Mat ImR270(input.cols, input.rows, CV_8UC1);//image after R270
Mat ImR180(input.rows, input.cols, CV_8UC1);//image after R180
namedWindow("imageR", 0);
imshow("imageR", input);
int c90 = 0;
for (r = 0; r < input.rows; r++)
{
int r90 = input.rows - 1;
for (c = 0; c < input.cols; c++)
{
ImR90.at<uchar>(r, c) = input.at<uchar>(r90, c90);
r90--;
}
c90++;
}
namedWindow("image Rotation 90", 0);
imshow("image Rotation 90", ImR90);
waitKey(0);
}