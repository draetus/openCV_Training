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

    cv::Mat original_image;
    original_image = cv::imread(argv[1], 1);

    cv::Mat LBP_image(original_image.rows, original_image.cols, CV_8UC1, cv::Scalar(0));
    cv::Mat gray_image;
    
    
    if (!original_image.data)
    {
        std::cout << "No image found...";
        return -1;
    }

    cv::cvtColor(original_image, gray_image, cv::COLOR_BGR2GRAY);
    LBP_image = gray_image.clone();

    int pixelValue = 0;

    cv::namedWindow("Modified Pixel in Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Modified Pixel In Image", original_image);
    cv::waitKeyEx(0);
   
    for (int i=1; i<original_image.rows; i++)
    {
        for (int j=1; j<original_image.cols; j++)
        {
            std::cout << "Column: " << i << "Row: " << j << std::endl;

            pixelValue += (gray_image.at<uchar>(i-1,j-1) <= gray_image.at<uchar>(i,j)) ? 1 : 0;
            pixelValue += (gray_image.at<uchar>(i-1,j) <= gray_image.at<uchar>(i,j)) ? 2 : 0;
            pixelValue += (gray_image.at<uchar>(i-1,j+1) <= gray_image.at<uchar>(i,j)) ? 4 : 0;
            pixelValue += (gray_image.at<uchar>(i,j+1) <= gray_image.at<uchar>(i,j)) ? 8 : 0;
            pixelValue += (gray_image.at<uchar>(i+1,j+1) <= gray_image.at<uchar>(i,j)) ? 16 : 0;
            pixelValue += (gray_image.at<uchar>(i+1,j) <= gray_image.at<uchar>(i,j)) ? 32 : 0;
            pixelValue += (gray_image.at<uchar>(i+1,j-1) <= gray_image.at<uchar>(i,j)) ? 64 : 0;
            pixelValue += (gray_image.at<uchar>(i,j-1) <= gray_image.at<uchar>(i,j)) ? 128 : 0;

            
            LBP_image.at<uchar>(i,j) = pixelValue;
            pixelValue = 0;
        }
        cv::imshow("Modified Pixel In Image", LBP_image);
        cv::waitKeyEx(1);

    }
    std::cout << pixelValue;
    
    cv::imshow("Modified Pixel In Image", LBP_image);
    cv::waitKeyEx(0);

    return 0;
}
