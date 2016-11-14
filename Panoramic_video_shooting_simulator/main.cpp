#include "opencv2/highgui/highgui.hpp"
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdlib.h>
#include <stdio.h>

#include <vector>
#include <iostream>

using namespace cv;

int main(int argc, char* argv[])
{
	IplImage* image = 0;
	char* filename = const_cast<char*>("image.jpg");

	image = cvLoadImage(filename, 1);

	printf("[i] image: %s\n", filename);
	assert(image != 0);

	cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("ROI", CV_WINDOW_AUTOSIZE);

	int x = 0;//500
	int y = 50;
	int width = 300;
	int height = 200;
	while (true)
	{
		cvRectangle(image, cvPoint(x, y), cvPoint(x + width, y + height), cvScalar(200), 1, 8);

		if (x + width > image->width)
			cvRectangle(image, cvPoint(0, y), cvPoint((x + width) - image->width, y + height), cvScalar(200), 1, 8);

		cvShowImage("original", image);
		if (x + width < image->width)
		{
			cvSetImageROI(image, cvRect(x, y, width, height));
			IplImage *sub_img = cvCreateImage(cvGetSize(image),
				image->depth,
				image->nChannels);
			cvCopy(image, sub_img, NULL);


			cvShowImage("ROI", sub_img);
			cvShowImage("Result", sub_img);
		}
		else
		{
			cvSetImageROI(image, cvRect(x, y, width, height));
			IplImage *first = cvCreateImage(cvGetSize(image),
				image->depth,
				image->nChannels);
			cvCopy(image, first, NULL);
			cvSetImageROI(image, cvRect(0, y, (x + width) - image->width, height));
			IplImage *second = cvCreateImage(cvGetSize(image),
				image->depth,
				image->nChannels);
			cvCopy(image, second, NULL);

			cvShowImage("ROI", first);
			if (second->width!=0)
				cvShowImage("IOR", second);

			cv::Mat firstPath = cv::cvarrToMat(first);
			cv::Mat secondPath = cv::cvarrToMat(second);
			Mat resultPath;

			hconcat(firstPath, secondPath, resultPath);
			IplImage copy = resultPath;
			IplImage* result = &copy;
			cvShowImage("Result", result);
		}

		cvResetImageROI(image);
		int key=cvWaitKey(0);
		if (key == 2424832)//2424832 - влево
		{
			x--;
			if (x < 0)
				x += image->width;
		}
		if (key == 2555904)//2555904 - вправо
		{
			x++;
			if (x >= image->width)
				x -= image->width;
		}
		if (key == 27)//27 - escape
		{
			cvReleaseImage(&image);
			cvDestroyAllWindows();
			return 0;
		}
		image = cvLoadImage(filename, 1);
	}
	/*if (x + width < image->width)
	{
	cvSetImageROI(image, cvRect(x, y, width, height));
	IplImage *sub_img = cvCreateImage(cvGetSize(image),
	image->depth,
	image->nChannels);
	cvCopy(image, sub_img, NULL);


	cvShowImage("ROI", sub_img);
	}
	else
	{
	cvSetImageROI(image, cvRect(x, y, width, height));
	IplImage *first = cvCreateImage(cvGetSize(image),
	image->depth,
	image->nChannels);
	cvCopy(image, first, NULL);
	cvSetImageROI(image, cvRect(0, y, (x + width) - image->width, height));
	IplImage *second = cvCreateImage(cvGetSize(image),
	image->depth,
	image->nChannels);
	cvCopy(image, second, NULL);

	cvShowImage("ROI", first);
	cvShowImage("IOR", second);

	cv::Mat firstPath = cv::cvarrToMat(first);
	cv::Mat secondPath = cv::cvarrToMat(second);
	Mat resultPath;

	hconcat(firstPath, secondPath, resultPath);
	IplImage copy = resultPath;
	IplImage* result = &copy;
	cvShowImage("Result", result);
	}

	cvResetImageROI(image);*/
}