#include <opencv2/highgui/highgui.hpp>
#include <iostream>

int main()
{
    //carregando imagem
    cv::Mat image;
    image = cv::imread("lena.jpg", CV_LOAD_IMAGE_COLOR);

    //salvando imagem
    cv::imwrite("processed.png", image);

    cv::imshow( "janela_id", image);

    cv::waitKey(0);
    return 0;
}
