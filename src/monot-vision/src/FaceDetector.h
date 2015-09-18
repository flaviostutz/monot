
class FaceDetector {
  private:
    CascadeClassifier faceCascade;
    VideoCapture capture;
    Mat frame;
    Size imageSize;
    std::vector<Rect> faces;
	public:
		FaceDetector();
		~FaceDetector();

		void start_detector(int videoDeviceNumber);
    std::vector<Rect> FaceDetector::detect_faces();
    void stop_detector();
    void displayLastResult();
};
