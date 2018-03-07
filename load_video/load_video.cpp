#include <opencv2/highgui/highgui.hpp>
#include <iostream>

int main(int argc, char** argv)
{
	if ( argc != 2 )
	{
		printf("Usage: ./load_video <Image_Path>\n");
		return -1;
	}

    cv::Mat image;
    cv::VideoCapture cap(argv[1]);

    cv::namedWindow("Video", 1);
    while(true)
    {
        cap >> image;
        cv::imshow("Video", image);
        cv::waitKey(33);
    }
}
