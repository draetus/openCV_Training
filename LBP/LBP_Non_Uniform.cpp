#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

int main(int argc, char** argv)
{
    if ( argc != 2 )
    {
        std::cout << "Usage: ./mod_pix_val <Image_Path>\n";
        return -1;
    }

    cv::Mat image;
    image = cv::imread(argv[1], 1);

    if (!image.data)
    {
        std::cout << "No image found...";
        return -1;
    }

    cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);

    int pixelValue = 0;

    cv::namedWindow("Modified Pixel in Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Modified Pixel In Image", image);
    cv::waitKeyEx(0);
   
    for (int i=1; i<image.cols; i++)
    {
        for (int j=1; j<image.rows; j++)
        {
            std::cout << "Column: " << i << "Row: " << j << std::endl;

            pixelValue += (image.at<uchar>(i-1,j-1) <= image.at<uchar>(i,j)) ? 1 : 0;
            pixelValue += (image.at<uchar>(i-1,j) <= image.at<uchar>(i,j)) ? 2 : 0;
            pixelValue += (image.at<uchar>(i-1,j+1) <= image.at<uchar>(i,j)) ? 4 : 0;
            pixelValue += (image.at<uchar>(i,j+1) <= image.at<uchar>(i,j)) ? 8 : 0;
            pixelValue += (image.at<uchar>(i+1,j+1) <= image.at<uchar>(i,j)) ? 16 : 0;
            pixelValue += (image.at<uchar>(i+1,j) <= image.at<uchar>(i,j)) ? 32 : 0;
            pixelValue += (image.at<uchar>(i+1,j-1) <= image.at<uchar>(i,j)) ? 64 : 0;
            pixelValue += (image.at<uchar>(i,j-1) <= image.at<uchar>(i,j)) ? 128 : 0;
            
            image.at<uchar>(i,j) = pixelValue;
            pixelValue = 0;
        }
        cv::imshow("Modified Pixel In Image", image);
        cv::waitKeyEx(1);

    }
    std::cout << pixelValue;
    
    cv::imshow("Modified Pixel In Image", image);
    cv::waitKeyEx(0);


    return 0;
}
