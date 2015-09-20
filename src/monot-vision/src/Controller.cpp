#include "Controller.h"

Controller::Controller(const char* id, const char* host, int port) : mosquittopp(id) {
	printf("Initializing MQTT connections...\n");
	mosqpp::lib_init();        // Mandatory initialization for mosquitto library
	loop_start();
	connect_async(host,	port,	60); //keepalive interval

	faceDetector = new FaceDetector();
	faceDetector->start_detector(-1, *new Size(240,180));
//	faceDetector->start_detector(-1, *new Size(120,90));
};

void Controller::step() {
	//send vision data to mqtt
	std::vector<Rect> faces = faceDetector->detect_faces();
	printf("Faces detected: %zu.\n", faces.size());

	faceDetector->displayLastResult();

	//publish detection data to mqtt topic

	//format faces data part
	char facesStr[faces.size() * 50];
	sprintf(facesStr, " ");
	char comma[1];
	for (size_t i = 0; i < faces.size(); i++) {
		if(i+1<faces.size()) comma[0]=',';
		else comma[0]=' ';
		sprintf(facesStr, "%s {\"x\":%d, \"y\":%d, \"width\":%d, \"height\":%d}%s", facesStr, faces[i].x, faces[i].y, faces[i].width, faces[i].height, comma);
	}

	//format overall message data
	char message[faces.size() * 50 + 50];
	sprintf(message, "{\"facesCount\":%zu, \"detectedFaces\":[%s]}", faces.size(), facesStr);

	send_message("agents/monot-vision/sensor-facedetector", message);
}

void Controller::on_connect(int rc) {
	printf("Connected with code %d.\n", rc);
	if(rc == 0) {
		subscribe(NULL, "agents/monot-vision/actuator#");
	}
}

void Controller::on_message(const struct mosquitto_message* message) {
	// double temp_celsius, temp_farenheit;
	// char buf[51];
	//
	// if(strcmp(message->topic, "agents/monot-vision/actuator-facedetector")) {
	// 	memset(buf, 0, 51*sizeof(char));
	// 	/* Copy N-1 bytes to ensure always 0 terminated. */
	// 	memcpy(buf, message->payload, 50*sizeof(char));
	// 	temp_celsius = atof(buf);
	// 	temp_farenheit = temp_celsius*9.0/5.0 + 32.0;
	// 	snprintf(buf, 50, "%f", temp_farenheit);
	// 	publish(NULL, "temperature/farenheit", strlen(buf), buf);
	// }
}

bool Controller::send_message(const char* topic, const char* message) {
	// Send message - depending on QoS, mosquitto lib managed re-submission this the thread
	//
	// * NULL : Message Id (int *) this allow to latter get status of each message
	// * topic : topic to be used
	// * length of the message
	// * message
	// * qos (0,1,2)
	// * retain (boolean) - indicates if message is retained on broker or not
	// Should return MOSQ_ERR_SUCCESS
	printf("Publishing MQTT message. topic=%s; message=%s\n", topic, message);
	int ret = publish(NULL,topic,strlen(message),message,1,true);
	return (ret == MOSQ_ERR_SUCCESS);
}

void Controller::on_subscribe(int mid, int qos_count, const int *granted_qos) {
	printf("Subscribed. %d\n", mid);
}

void Controller::on_publish(int mid) {
	printf("Published message %d\n", mid);
}

void Controller::on_disconnect(int rc) {
	printf("Disconnected. %d\n", rc);
}

Controller::~Controller() {
	faceDetector->stop_detector();
	loop_stop();
	mosqpp::lib_cleanup();    // Mosquitto library cleanup
}
