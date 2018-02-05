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
/*
    cv::Vec3b col5 = image.at<cv::Vec3b>(14,10);

    cv::Vec3b col = cv::Vec3b(0,0,0);
    for (int i=0; i<100; i++)
    {
        for (int j=0; j<100; j++)
        {
            image.at<cv::Vec3b>(cv::Point(i,j)) = col;
        }
    }




    cv::namedWindow("Modified Pixel in Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Modified Pixel In Image", image);
    cv::waitKeyEx(0);
*/   

    cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);

    bool pixelValue[8], atual;
    int transicoes = 0;

    cv::namedWindow("Modified Pixel in Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Modified Pixel In Image", image);
    cv::waitKeyEx(0);
   
    for (int i=1; i<image.cols; i++)
    {
        for (int j=1; j<image.rows; j++)
        {
            std::cout << "Column: " << i << "Row: " << j << std::endl;

            pixelValue[0] = (image.at<uchar>(i-1,j-1) <= image.at<uchar>(i,j)) ? 1: 0;
            pixelValue[1] = (image.at<uchar>(i-1,j) <= image.at<uchar>(i,j)) ? 1 : 0;
            pixelValue[2] = (image.at<uchar>(i-1,j+1) <= image.at<uchar>(i,j)) ? 1 : 0;
            pixelValue[3] = (image.at<uchar>(i,j+1) <= image.at<uchar>(i,j)) ? 1 : 0;
            pixelValue[4] = (image.at<uchar>(i+1,j+1) <= image.at<uchar>(i,j)) ? 1 : 0;
            pixelValue[5] = (image.at<uchar>(i+1,j) <= image.at<uchar>(i,j)) ? 1 : 0;
            pixelValue[6] = (image.at<uchar>(i+1,j-1) <= image.at<uchar>(i,j)) ? 1 : 0;
            pixelValue[7] = (image.at<uchar>(i,j-1) <= image.at<uchar>(i,j)) ? 1 : 0;
            atual = pixelValue[0];

            for (int k=1; k<8; k++)
            {
                if (pixelValue[k] != atual)
                {
                    transicoes++;
                    atual = pixelValue[k];
                }
            }

            if (transicoes <3)
            {
                image.at<uchar>(i,j) = 0;
                for (int k=0; k<8; k++)
                {
                    image.at<uchar>(i,j) += (pixelValue[k]) ? std::pow(2, k) : 0;
                }
            }
            else
            {
                image.at<uchar>(i,j) = 5;
            }

            for (int k=0; k<8; k++)
            {
                pixelValue[k] = 0;
            }
            transicoes = 0;
        }
        cv::imshow("Modified Pixel In Image", image);
        cv::waitKeyEx(1);

    }
    std::cout << pixelValue;
    
    cv::imshow("Modified Pixel In Image", image);
    cv::waitKeyEx(0);


    return 0;
}
