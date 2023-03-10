#include <stdio.h>
#include <mosquitto.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int rc;
	struct mosquitto *mosq;
	char target[20];

	mosquitto_lib_init();

	mosq = mosquitto_new("publisher-test", true, NULL);

	rc = mosquitto_connect(mosq, "localhost", 1883, 60);
	if (rc != 0)
	{
		printf("Client could not connect to broker! Error Code: %d\n", rc);
		mosquitto_destroy(mosq);
		return -1;
	}
	printf("We are now connected to the broker!\n");

	sprintf(target, "%s:%s:%s", argv[1], argv[2], argv[3]);

	mosquitto_publish(mosq, NULL, "control", strlen(target), target, 0, false);

	mosquitto_disconnect(mosq);
	mosquitto_destroy(mosq);

	mosquitto_lib_cleanup();

	printf("developer1 modified1");
	printf("developer1 modified2");
	printf("developer1 modified3");
	printf("developer1 modified4");
	printf("developer1 modified5");

	printf("commit release1");
	printf("resovled hotfix");
	return 0;
}
