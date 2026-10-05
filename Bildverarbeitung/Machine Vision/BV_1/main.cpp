#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("Auge.jpg");
    
    cout << "width: " << img.cols << endl;
    cout << "height: " << img.rows << endl;

    imshow("Bild", img);
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    imshow("Grau", gray);
    waitKey(0);
    

    return 0;
}