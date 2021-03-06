#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <stdio.h>

#include <mosquitto.h>
#include <mosquittopp.h>
#include "FaceDetector.h"

using namespace std;
using namespace cv;

#include <mosquittopp.h>

class Controller : public mosqpp::mosquittopp {
	private:
		class FaceDetector* faceDetector;
	public:
		Controller(const char *id, const char *host, int port);
		~Controller();

		void step();
		void on_connect(int rc);
		void on_disconnect(int rc);
		void on_publish(int mid);
		void on_message(const struct mosquitto_message *message);
		void on_subscribe(int mid, int qos_count, const int *granted_qos);
		bool send_message(const char* topic, const char* message);
};
