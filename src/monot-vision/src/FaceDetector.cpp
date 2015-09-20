#include "FaceDetector.h"

FaceDetector::FaceDetector() {
};
FaceDetector::~FaceDetector() {
};

void FaceDetector::start_detector(int videoDeviceNumber, cv::Size imageSize) {
  this->imageSize = imageSize;
  if(!faceCascade.load("haarcascade_frontalface_default.xml")) {
    printf("Error loading face cascade\n");
    throw;
  };

  this->capture.open(-1);
  if(!this->capture.isOpened()) {
    printf("Error opening video capture\n");
    throw;
  }
}

std::vector<Rect> FaceDetector::detect_faces() {
  Mat frame;
  if(this->capture.read(frame)) {
    if(frame.empty()) {
      printf("Empty captured frame");
      throw;
    }

    cvtColor(frame, frame, COLOR_BGR2GRAY);
    resize(frame, frame, this->imageSize);
    equalizeHist(frame, this->frame);

    faceCascade.detectMultiScale(this->frame, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, *new Size(30, 30));
    return faces;

  } else {
    printf("Cannot read frame");
    throw;
  }
}

void FaceDetector::stop_detector() {
  this->capture.release();
}

void FaceDetector::displayLastResult() {
  for (size_t i = 0; i < this->faces.size(); i++) {
    Point center(faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2);
    ellipse(frame, center, Size(faces[i].width/2, faces[i].height/2), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);
  }
  imshow("Last result", frame);
}
