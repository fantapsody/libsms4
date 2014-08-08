#include "sms4.h"

void sms4_encrypt_init(sms4_key_t *key)
{
}

void sms4_encrypt_8blocks(sms4_key_t *key, const unsigned char *in, unsigned char *out)
{
	sms4_encrypt(key, in         , out         );
	sms4_encrypt(key, in + 16    , out + 16    );
	sms4_encrypt(key, in + 16 * 2, out + 16 * 2);
	sms4_encrypt(key, in + 16 * 3, out + 16 * 3);
	sms4_encrypt(key, in + 16 * 4, out + 16 * 4);
	sms4_encrypt(key, in + 16 * 5, out + 16 * 5);
	sms4_encrypt(key, in + 16 * 6, out + 16 * 6);
	sms4_encrypt(key, in + 16 * 7, out + 16 * 7);
}

void sms4_encrypt_16blocks(sms4_key_t *key, const unsigned char *in, unsigned char *out)
{
	sms4_encrypt_8blocks(key, in, out);
	sms4_encrypt_8blocks(key, in + 16 * 8, out + 16 * 8);
}

