#include<opencv2/opencv.hpp>
#include"iostream"
#include"math.h"
using namespace std;
using namespace cv;
/////Round function made by Mohamed Saber Mohamed sec1////////////////
int Round(float in)
{ int x = (int)in;
if((in-x)>=0.5)
return (x + 1);
else
return x;
}
int main()
{
Mat input = imread("x.jpg", 0);
Mat zoom(input.rows *2, input.cols * 2, CV_8UC1);
Mat zoom2;
namedWindow("input", 1);
imshow("input", input);
waitKey(0);
float ri = input.rows;
float ci = input.cols;
float rz= zoom.rows;
float cz= zoom.cols;
float sc = (ci-1)/ cz;
float sr = (ri - 1) / rz;
for (int r=0;r<zoom.rows;r++)
{
for (int c = 0; c< zoom.cols; c++)
{
float rzz = sr * r;
float czz = sc * c;
int x = Round(rzz);
int y = Round(czz);
zoom.at<uchar>(r, c) = input.at<uchar>(x, y);
}
}
namedWindow("our zoom image", 1);
imshow("our zoom image", zoom);
waitKey(0);
//////////////////zoom by using function resize//////////////
resize(input, zoom2, Size(), 2, 2, 0);
namedWindow("Function zoom image", 1);
imshow("Function zoom image", zoom2);
cout << "input size= " << input.size << endl;
cout << "zoom size= " << zoom.size << endl;
cout << "zoom2 size= " << zoom2.size << endl;
waitKey(0);
return 0;
}