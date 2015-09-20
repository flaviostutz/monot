#include <stdio.h>
#include <unistd.h>
#include "Controller.h"

int main(int argc, char *argv[]) {
	// int rc;

	printf("Initializing Monot Vision...\n");

	class Controller* controller = new Controller("vision-controller", "localhost", 1883);

	while(1) {
		// rc = controller->loop();
		// if(rc){
			// controller->reconnect();
		// }
		controller->step();

		//usleep(100000);
	}

	return 0;
}
