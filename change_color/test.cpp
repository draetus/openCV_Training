#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

int main(int argc, char** argv)
{
    if ( argc != 3 )
    {
        std::cout << "Usage: ./test <Image_Path> (b(lue)/g(reen)/r(ed))\n";
        return -1;
    }

    cv::Mat original_image;
    original_image = cv::imread(argv[1], 1);

    if (!original_image.data)
    {
        std::cout << "No image found...";
        return -1;
    }


    cv::Mat channel[3];
    int x,y;

    switch(*argv[2])
    {
        case 'b':
            x = 1;
            y = 2;
            break;

        case 'g':
            x = 0;
            y = 2;
            break;

        case 'r':
            x = 0;
            y = 1;
            break;
    }

    cv::split(original_image, channel);

    channel[x]= cv::Mat::zeros(original_image.rows, original_image.cols, CV_8UC1);
    channel[y]= cv::Mat::zeros(original_image.rows, original_image.cols, CV_8UC1);

    cv::merge(channel, 3, original_image);

    cv::namedWindow("LBP Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("LBP Image", original_image);
    cv::waitKeyEx(0);
} 
