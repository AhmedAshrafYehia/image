#include"iostream"
using namespace std;
#include<opencv2/opencv.hpp>
using namespace cv;
int r;
int c;
int main()
{
Mat image1 = imread("x1.jpg", 0);
Mat image2 = imread("xx1.jpg", 0);
Mat image_blind(image1.rows, image1.cols, CV_8UC1);
namedWindow("image1", 0);
imshow("image1", image1);
namedWindow("image2", 0);
imshow("image2", image2);
resize(image2, image2, Size(image1.cols, image1.rows));
for ( r = 0; r < image1.rows; r++)
{
for ( c = 0; c< image1.cols; c++)
{
image_blind.at<uchar>(r, c) = image1.at<uchar>(r, c)*0.7 +
image2.at<uchar>(r, c)*0.3;
}
}
namedWindow("blinding", 0);
imshow("blinding", image_blind);
waitKey(0);
return 0;
}