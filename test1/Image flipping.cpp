#include"iostream"
using namespace std;
#include<opencv2/opencv.hpp>
using namespace cv;
int r;
int c;
int main()
{
Mat image1 = imread("x1.jpg",0);
Mat image_flipped(image1.rows, image1.cols, CV_8UC1);
namedWindow("imagef", 0);
imshow("imagef", image1);
for (r = 0; r < image1.rows; r++)
{
int cf = image1.cols - 1;
for (c = 0; c< image1.cols; c++)
{
image_flipped.at<uchar>(r, c) = image1.at<uchar>(r, cf);
cf--;
}
}
namedWindow("flipped", 0);
imshow("flipped", image_flipped);
waitKey(0);
return 0;
}