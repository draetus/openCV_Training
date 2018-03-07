#include <opencv2/highgui/highgui.hpp>
#include <iostream>

int main(int argc, char** argv)
{
	if ( argc != 2 )
	{
		printf("Usage: ./load_image <Image_Path>\n");
		return -1;
	}

    //carregando imagem
    cv::Mat image;
    image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);

    //salvando imagem
    cv::imwrite("processed.png", image);

    cv::imshow( "janela_id", image);

    cv::waitKey(0);
    return 0;
}
