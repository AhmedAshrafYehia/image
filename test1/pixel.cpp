#include <opencv2/opencv.hpp>
#include "iostream"
using namespace std;
using namespace cv;
int main()
{
    Mat image1, image2;
    image1 = imread("x.jpg", 0);
    image2 = imread("x.jpg", 1);
    namedWindow("win_Gray", 0);
    imshow("win_Gray", image1);
    cout << "gray Image Matrix" << endl
         << endl
         << endl
         << endl;
    cout << image1 << endl;
    waitKey(0);
    namedWindow("win_RGB", 1);
    imshow("win_RGB", image2);
    cout << "rgb Image Matrix" << endl
         << endl
         << endl
         << endl;
    cout << image2 << endl;
    waitKey(0);
    destroyAllWindows(); //destroys all the windows we created to free memory.
    return 0;
}