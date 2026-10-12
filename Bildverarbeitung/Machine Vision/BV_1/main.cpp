#include <opencv2/opencv.hpp>
#include <iostream>
#include "help.h"

using namespace std;
using namespace cv;


void Ex_1(Mat img)
{
    // b) 
    cout << "width: " << img.cols << endl;
    cout << "height: " << img.rows << endl;
    cout << "size: " << img.size() << endl;
    cout << "type: " << img.type() << endl;

    // c)
    imwrite("Bild_png.png", img);
    imwrite("Bild_bmp.bmp", img);

    Mat img_png = imread("Bild_png.png");
    Mat img_bmp = imread("Bild_bmp.bmp");

    imshow("Original", img);
    imshow("PNG", img_png);
    imshow("BMP", img_bmp);

    waitKey(0);
}

void Ex_2(Mat img)
{
    // 1.2
    // a)
    Mat gray = manual_gray(img);

    // b)
    Mat quant = quantize_img(img, 2);
    //imwrite("Quantisiert", quant);
    imshow("Quantisiiert", quant);

    // d)
    Mat gray2;
    cvtColor(img, gray2, COLOR_GRAY2BGR);
    imshow("gray", gray2);

    // e)
    int sum = 0;
    for(int y = 0; y < gray2.rows; y++)
    {
        for(int x = 0; x < gray2.cols; x++)
        {
            sum += gray2.at<uchar>(y,x);
        }
    }

    float mean = sum/(300/300);
}


int main()
{
    // 1.1
    // a)
    Mat img = imread("Auge.jpg");
    Ex_1(img);

    //1.2


    //Easy_gray(img);
    //manual_gray(img);

    //compare(Easy_gray(img), manual_gray(img));


    waitKey(0);
    return 0;
}