#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>

int main(void) {
	CURL *handle = curl_easy_init();
		if (!handle) {
		fprintf(stderr, "Error encountered\n");
		return EXIT_FAILURE;
	}
	#ifndef VERIFY
	#define VERIFY
	curl_easy_setopt(handle, CURLOPT_SSL_VERIFYPEER, 0L);
	#endif
	curl_easy_setopt(handle, CURLOPT_URL, "https://curl.se");
	CURLcode status = curl_easy_perform(handle);
	if (status != CURLE_OK) {
		return EXIT_FAILURE;
	}
	curl_easy_cleanup(handle);
	return EXIT_SUCCESS;
}