#include "help.h"

using namespace cv;
using namespace std;

Mat Easy_gray(Mat img)
{
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    imshow("Grau", gray);

    return gray;
}

Mat manual_gray(Mat img)
{
    Mat gray2(img.rows, img.cols, CV_8UC1);

    Vec3b pixel;

    for(int i = 0; i < img.cols; i++)
    {
        for(int j = 0; j < img.rows; j++)
        {
            pixel = img.at<Vec3b>(i,j);
            int B = pixel[0];
            int G = pixel[1];
            int R = pixel[2];
            int sum = B + G + R;

            gray2.at<uchar>(i,j) = sum/img.channels();
        }
    }

    imshow("manuelles grau", gray2);

    return gray2;
}


vector<pair<int, int>> compare(const Mat& img1, const Mat& img2)
{
    vector<pair<int, int>> values;

    if (img1.size() != img2.size() || img1.type() != CV_8UC1 || img2.type() != CV_8UC1)
    {
        return {{-1, -1}};
    }

    Mat comp;
    cvtColor(img1, comp, COLOR_GRAY2BGR);

    for (int i = 0; i < img1.rows; i++)
    {
        for (int j = 0; j < img1.cols; j++)
        {
            uchar pixel1 = img1.at<uchar>(i, j);
            uchar pixel2 = img2.at<uchar>(i, j);

            if (abs(int(pixel1) - int(pixel2)) > 10)
            {
                values.emplace_back(i, j);
                comp.at<Vec3b>(i, j) = Vec3b(0, 0, 255);
            }
        }
    }

    imshow("compared", comp);
    return values;
}

Mat quantize_img(Mat img, int bits)
{
    int levels = 1 << bits;

    Mat quantized = img.clone();

    for(int i = 0; i < img.rows; i++)
    {
        for(int j = 0; j < img.cols; j++)
        {
            uchar pixel = img.at<uchar>(i,j);

            int level = pixel * levels/256;

            quantized.at<uchar>(i,j) = static_cast<uchar>(level*255/(levels - 1));
        }
    }

    return quantized;
}