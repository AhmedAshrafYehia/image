#include"iostream"
using namespace std;
#include<opencv2/opencv.hpp>
using namespace cv;
int r;
int c;
int j;
int main()
{
Mat input = imread("hist.jpg", 0);
Mat output(input.rows, input.cols, CV_8UC1); namedWindow("ImageBhistogramEq", 0);
imshow("ImageBhistogramEq", input);
float hist[256] = { 0 };
float hist2[256] = { 0 };
float prob[256];
float comm[256];
/////////////////////////////////histogram////////////////////////////
for (int g = 0; g<256; g++)
{
for (r = 0; r<input.rows; r++)
{
for (c = 0; c<input.cols; c++)
{
if (input.at<uchar>(r, c) == g)
hist[g] = hist[g] + 1;
}
}
}
///////////////////prob////////////////////////////////
for (j = 0; j < 256; j++)
{
prob[j] = hist[j] / input.total(); ;
}
///////////////////commulative//////////
comm[0] = prob[0];
cout << comm[0] << endl;
for (j = 1; j < 256; j++)
{
comm[j] = comm[j - 1] + prob[j];
}
////////////////////////////////map to image////////////////////////
for (r = 0; r < input.rows; r++)
{
for (c = 0; c < input.cols; c++)
{
output.at<uchar>(r, c) = comm[input.at<uchar>(r, c)] * 255.0;
}
}
namedWindow("ImageAhistogramEq", 0);
imshow("ImageAhistogramEq", output);
waitKey(0);
}