#include <opencv2/highgui/highgui.hpp>
#include <iostream>

int main()
{
    cv::Mat image;
    cv::VideoCapture cap("sample.avi");

    cv::namedWindow("Video", 1);
    while(true)
    {
        cap >> image;
        cv::imshow("Video", image);
        cv::waitKey(33);
    }
}
