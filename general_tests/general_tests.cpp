#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main(int argc, char** argv)
{
    //Matriz identidade (diagonal principal com zeros)
    cv::Mat E = cv::Mat::eye(1000,1000,CV_64F);

    //Inicializacao
    cv::Mat C = (cv::Mat_<double>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);

    //Copiando uma linha
    cv::Mat RowCLone = C.row(1).clone();
    
    //Copiando uma coluna
    cv::Mat ColClone = C.col(2).clone();

    cv::namedWindow( "janela", CV_WINDOW_AUTOSIZE );

    cv::imshow( "janela", E);
    cv::waitKey(0);

    cv::Mat Row = C.row(1);
    Row.at<double>(0,1) = 3.14;
    C.row(0) = C.row(0) + C.row(2)*3;
    
    return 0;
}
