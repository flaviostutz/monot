#include <opencv2/objdetect.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

class FaceDetector {
  private:
    CascadeClassifier faceCascade;
    VideoCapture capture;
    Mat frame;
    cv::Size imageSize;
    std::vector<Rect> faces;
	public:
		FaceDetector();
		~FaceDetector();

		void start_detector(int videoDeviceNumber, cv::Size imageSize);
    std::vector<Rect> detect_faces();
    void stop_detector();
    void displayLastResult();
};
