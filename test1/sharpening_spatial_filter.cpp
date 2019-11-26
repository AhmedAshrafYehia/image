#include<iostream>
#include<opencv2\opencv.hpp>
using namespace std;
using namespace cv;
int i,j,p_mag,s_mag;
int main()
{
	Mat input=imread("2.png",0);
    Mat prewitt_horizontal_out(input.rows,input.cols,CV_8UC1);
    Mat prewitt_vertical_out(input.rows,input.cols,CV_8UC1);
	Mat sobel_horizontal_out(input.rows,input.cols,CV_8UC1);
	Mat sobel_vertical_out(input.rows,input.cols,CV_8UC1);
	namedWindow("Before filtering",0);
	imshow("Before filtering",input);
	for(i=1;i<input.rows-1;i++)
	{
		for(j=1;j<input.cols-1;j++)
		{
///////////////////////////////////////Prewitt horizontal law////////////////////////////////////////////////
			prewitt_horizontal_out.at<uchar>(i,j)=abs((input.at<uchar>(i-1,j-1)*1)+
				                                      (input.at<uchar>(i-1,j)*1)+
											          (input.at<uchar>(i-1,j+1)*1)+
											          (input.at<uchar>(i+1,j-1)*-1)+
											          (input.at<uchar>(i+1,j)*-1)+
											          (input.at<uchar>(i+1,j+1)*-1));
			
///////////////////////////////////prewitt vertical law/////////////////////////////////////////////////////
			prewitt_vertical_out.at<uchar>(i,j)=abs((input.at<uchar>(i-1,j-1)*1)+
				                                    (input.at<uchar>(i-1,j+1)*-1)+
												    (input.at<uchar>(i,j-1)*1)+
													(input.at<uchar>(i,j+1)*-1)+
													(input.at<uchar>(i+1,j-1)*1)+
													(input.at<uchar>(i+1,j+1)*-1));
////////////////////////////////the prewitt magnitude///////////////////////////////////////////////////////
			p_mag=sqrtf(((prewitt_horizontal_out.at<uchar>(i,j))*(prewitt_horizontal_out.at<uchar>(i,j)))+
				       ((prewitt_vertical_out.at<uchar>(i,j))*(prewitt_vertical_out.at<uchar>(i,j))));
			if(p_mag>100) 
		       p_mag=255;
			else p_mag=0;
   }
	}
for(i=1;i<input.rows-1;i++)
	{
		for(j=1;j<input.cols-1;j++)
		{
///////////////////////////////////////////////sobel horizontal law/////////////////////////////////////////
			sobel_horizontal_out.at<uchar>(i,j)=abs((input.at<uchar>(i-1,j-1)*1)+
				                                      (input.at<uchar>(i-1,j)*2)+
											          (input.at<uchar>(i-1,j+1)*1)+
											          (input.at<uchar>(i+1,j-1)*-1)+
											          (input.at<uchar>(i+1,j)*-2)+
											          (input.at<uchar>(i+1,j+1)*-1));
			
///////////////////////////////////////////sobel vertical law///////////////////////////////////////////////
			sobel_vertical_out.at<uchar>(i,j)=abs((input.at<uchar>(i-1,j-1)*1)+
				                                    (input.at<uchar>(i-1,j+1)*-1)+
												    (input.at<uchar>(i,j-1)*2)+
													(input.at<uchar>(i,j+1)*-2)+
													(input.at<uchar>(i+1,j-1)*1)+
													(input.at<uchar>(i+1,j+1)*-1));
////////////////////////////////the sobel magnitude/////////////////////////////////////////////////////////
			s_mag=sqrtf(((sobel_horizontal_out.at<uchar>(i,j))*(sobel_horizontal_out.at<uchar>(i,j)))+
				       ((sobel_vertical_out.at<uchar>(i,j))*(sobel_vertical_out.at<uchar>(i,j))));
			if(s_mag>100) 
		       s_mag=255;
			else s_mag=0;
   }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

namedWindow("After p_horizontal",0);
imshow("After p_horizontal",prewitt_horizontal_out);
namedWindow("After p_vertical",0);
imshow("After p_vertical",prewitt_vertical_out);
namedWindow("After s_horizontal",0);
imshow("After s_horizontal",sobel_horizontal_out);
namedWindow("After s_vertical",0);
imshow("After s_vertical",sobel_vertical_out);
waitKey(0);
return 0;
}