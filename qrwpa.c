#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#include "qr.h"

void print_wifi_wpa_qr(const char *ssid, const char *pass, output_type_e type)
{
	char buf[1024];
	snprintf(buf, sizeof(buf), "WIFI:T:WPA;S:%s;P:%s;;", ssid, pass);
	parseMessage(NULL, buf, NULL, type);
}

int main(int argc, char *argv[])
{
	int opt;
	output_type_e type = TYPE_UNICODE;
	const char *ssid = NULL;
	const char *pass = NULL;

	while ((opt = getopt(argc, argv, "s:p:a")) != -1) {
		switch (opt) {
		case 's':
			ssid = optarg;
			break;
		case 'p':
			pass = optarg;
			break;
		case 'a':
			type = TYPE_ANSI;
			break;
		case 'o':
			type = TYPE_UNICODE;
			break;
		default: /* '?' */
			fprintf(stderr, "Usage: %s [-s ssid] [-p password] [-a(ansi)]\n", argv[0]);
			exit(EXIT_FAILURE);
		}
	}

	if (ssid && pass) {
		print_wifi_wpa_qr(ssid, pass, type);
	} else {
		fprintf(stderr, "Usage: %s [-s ssid] [-p password] [-a(ansi)]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	return 0;
}
