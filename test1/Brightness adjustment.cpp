#include"iostream"
using namespace std;
#include<opencv2/opencv.hpp>
using namespace cv;
void bright_inc(Mat input, Mat output);
void bright_dec(Mat input, Mat output);
int b_value = 0;
int d_value = 0;
int r;
int c;
int main()
{
Mat keys = imread("keylist.jpg");
Mat imageb = imread("low.jpg", 0);//bright adjustment image
Mat image_bright(imageb.rows, imageb.cols, CV_8UC1);//image after
cout << "for key list press 1" << endl;
namedWindow("key list", 0);
imshow("key list", keys);
int key;
while (true) {
key = waitKey();
cout << key << endl;
switch (key)
{
case 27://esc
return -1;
case 49://1
namedWindow("key list", 0);
imshow("key list", keys);
break;
case 50://2
bright_inc(imageb, image_bright);
break;
case 51://3
bright_dec(imageb, image_bright);
break;
}
}
return 0;
}
void bright_inc(Mat input, Mat output)
{
destroyAllWindows();
namedWindow("orginal", 0);
imshow("orginal", input);
namedWindow("bright_inc", 0);
createTrackbar("BrightnessBar", "bright_inc", &b_value, 100);
for ( r = 0; r < input.rows; r++)
{
for (c = 0; c < input.cols; c++)
{
if (input.at<uchar>(r, c) + b_value > 255)
output.at<uchar>(r, c) = 255;
else
output.at<uchar>(r, c) = input.at<uchar>(r, c) + b_value;
}
}
imshow("bright_inc", output);
}
void bright_dec(Mat input, Mat output)
{
destroyAllWindows();
namedWindow("orginal", 0);
imshow("orginal", input);
namedWindow("bright_dec", 0);
createTrackbar("BrightnessBar", "bright_dec", &d_value, 100);
for ( r = 0; r < input.rows; r++)
{
for (c = 0; c < input.cols; c++)
{
if (input.at<uchar>(r, c) - d_value < 0)
output.at<uchar>(r, c) = 0;
else
output.at<uchar>(r, c) = input.at<uchar>(r, c) - d_value;
}
}
imshow("bright_dec", output);
}