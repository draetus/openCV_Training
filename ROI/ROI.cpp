#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main()
{
    cv::Mat image, gray;

    image = cv::imread("../data/lena.jpg", CV_LOAD_IMAGE_COLOR);

    //converte para escala de cinza
    cv::cvtColor( image, gray, CV_BGR2GRAY );


    //define a ROI
    cv::Mat ROI(gray, cv::Rect(100, 100, 300, 300));
   
    cv::Mat img2, img3;
    
    img2 = ROI; //ira modificar o conteúdo original
    img3 = ROI.clone(); //Nao modifica o conteudo

    return 0;
}
