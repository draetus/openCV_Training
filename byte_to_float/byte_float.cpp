#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

int main()
{
    cv::Mat img = cv::Mat(480, 640, CV_8UC3);
    cv::Mat gray, float_gray;

    cv::cvtColor(img, gray, CV_BGR2GRAY);

    //Conversao 8UC1 to 32FC1
    gray.convertTo(float_gray, CV_32F);
}
