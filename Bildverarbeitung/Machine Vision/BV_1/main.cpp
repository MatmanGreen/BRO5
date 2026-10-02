#include <opencv2/opencv.hpp>
#include <iostream>
#include <filesystem>

int main()
{
    std::cout << "OpenCV: " << CV_VERSION << '\n';
    std::cout << "Ordner: " << std::filesystem::current_path() << '\n';

    std::cout << "Datei existiert: "
              << std::filesystem::exists("Auge.jpg") << '\n';

    std::cout << "OpenCV erkennt Bildformat: "
              << cv::haveImageReader("Auge.jpg") << '\n';

    cv::Mat img = cv::imread("Auge.jpg");

    if (img.empty())
    {
        std::cerr << "FEHLER: imread konnte Auge.jpg nicht laden.\n";
        return 1;
    }

    std::cout << "Bild geladen: "
              << img.cols << " x " << img.rows << '\n';

    cv::imshow("Bild", img);
    cv::waitKey(0);

    return 0;
}