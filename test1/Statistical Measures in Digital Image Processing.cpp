#include<opencv2/opencv.hpp>
#include"iostream"
using namespace std;
using namespace cv;
int main()
{
Mat input = imread("xx.jpg", 0);
cout << "no of rows= " << input.rows << endl << "no of colls= "
<< input.cols << endl << "size= " << input.size << endl << "no of channels= " << input.channels() << endl << "pixel depth= " << input.depth() << endl;
namedWindow("win1", 0);
imshow("win1", input);
int min = input.at<uchar>(0, 0);
int max = input.at<uchar>(0, 0);
float sum = 0;
float average;
int r;
int c;
//////////////////////////min max value//////////////////////////
for (r = 0; r < input.rows; r++)
{
for (c = 0; c < input.cols; c++)
{
if (input.at<uchar>(r, c) < min)
min = input.at<uchar>(r, c);
if (input.at<uchar>(r, c) > max)
max = input.at<uchar>(r, c);
sum = input.at<uchar>(r, c) + sum;
}
}
average = sum / input.total();
/////////////////////////////output///////////////////////
cout << "min value = " << min << endl;
cout << "max value = " << max << endl;
cout << "average = " << average << endl;
waitKey(0);
/////////////////change diagonal pixels to white/////////////////
for ( r = 0; r < input.rows; r++)
{
for (c = 0; c < input.cols; c++)
{
if (r == c)
input.at<uchar>(r, c) = 255;
}
}
namedWindow("win2",0);
imshow("win2", input);
waitKey(0);
imwrite("modifed.jpg", input);
return 0;
}