#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include "sms4.h"


int main(int argc, char **argv)
{
	sms4_key_t sms4_key;
	unsigned char user_key[16] = {
		0x11,  0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88,
		0x11,  0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88,
	};
	size_t buflen = SMS4_BLOCK_SIZE * 8 * 3 * 1000 * 1000;	
	unsigned char *buf = NULL;
	unsigned char *p;
	int i;	


	if (!(buf = (unsigned char *)malloc(buflen))) {
		fprintf(stderr, "malloc failed\n");
		return -1;
	}

	sms4_set_encrypt_key(&sms4_key, user_key);
	
	for (i = 0, p = buf; i < buflen/(SMS4_BLOCK_SIZE * 16); i++, p += SMS4_BLOCK_SIZE * 16) {
		sms4_encrypt_16blocks(&sms4_key, p, p);
	}	
	
	return 0;
}

