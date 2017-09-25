//Estruturas basicas usadas pela biblioteca
#include <opencv2/core/core.hpp>
//Funcoes (abrir janela, ler do teclado, etc...)
#include <opencv2/highgui/highgui.hpp>
//putText foi movido para imgproc.hpp
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
int main(int argc, char** argv)
{
	cout << "Hello World";

    //cv::Mat::zeros -> Matriz de zeros( imagem preta )
    //640, 480 -> Dimensoes da imagem (tamanho)
    //CV_8UC3 -> a imagem tera 3 colunas e cada coluna sera 1 char com 1 byte(8 bits)
    cv::Mat img = cv::Mat::zeros( 640, 480, CV_8UC3 );

	string msg("Ola OpenCV");

    //Coloca o texto na imagem 
    //img -> Imagem que vai receber o texto
    //msg -> texto que vai ser inserido na imagem
    //Point -> Coordenada localizada na imagem em que o texto vai ser inserido
    //5 -> Espessura da fonte
    //1 -> Tamanho da fonte
    //Scalar(255,255,255) Cor (Estilo BGR) = Branco, Ex: Scalar(0,0,255) = Vermelho
    cv::putText ( img, msg, cv::Point(100, 100), 5, 1, cv::Scalar(255,255,255) );
    //Cria uma janela
    //"ola_window" -> Identificador da janela
    //CV_WINDOW_AUTOSIZE -> Regulamento automatico de tamanho da janela
    cv::namedWindow( "ola_window", CV_WINDOW_AUTOSIZE );

    //Mostra imagem
    //"ola_window" -> identificador da janela que sera aberta
    //img -> imagem que sera aberta
    cv::imshow ( "ola_window", img);
    cv::waitKey(0);
	return 0;
}
