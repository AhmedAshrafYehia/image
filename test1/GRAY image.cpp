#include<opencv2/opencv.hpp>
#include"iostream"
using namespace std;
using namespace cv;
int main()
{ Mat image1,image2,image,grayimage;
image = imread("C:\\Users\\Public\\Pictures\\Sample Pictures\\koala.jpg");
if (image.empty())
{ cout << "no image" << endl;
system("pause");
return -1;
}
namedWindow("display win");
imshow("display win", image);
waitKey(0);
cvtColor(image, grayimage, COLOR_BGR2GRAY);
namedWindow("gray win");
imshow("gray win", grayimage);
waitKey(0);
imwrite("gray image2.jpg", grayimage);
return 0;
}