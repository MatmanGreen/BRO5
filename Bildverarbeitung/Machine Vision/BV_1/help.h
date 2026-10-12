#ifndef HELP_H
#define HELP_H

#include <opencv2/opencv.hpp>
#include <vector>


cv::Mat Easy_gray(cv::Mat img);
cv::Mat manual_gray(cv::Mat img);
std::vector<std::pair<int, int>> compare(const cv::Mat& img1, const cv::Mat& img2);
cv::Mat quantize_img(cv::Mat img, int bits);

#endif