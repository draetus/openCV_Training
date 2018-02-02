#include <opencv2/opencv.hpp>
#include <iostream>

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

    cv::cvtColor(image, image, CV_BGR2GRAY);
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
    return 0;
}
