#ifndef LIBSM_SMS4_H
#define LIBSM_SMS4_H

#define SMS4_KEY_LENGTH		16
#define SMS4_BLOCK_SIZE		16
#define SMS4_NUM_ROUNDS		32

#include <sys/types.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	uint32_t rk[SMS4_NUM_ROUNDS];
} sms4_key_t;

void sms4_set_encrypt_key(sms4_key_t *key, const unsigned char *user_key);
void sms4_set_decrypt_key(sms4_key_t *key, const unsigned char *user_key);
void sms4_encrypt(sms4_key_t *key, const unsigned char *in, unsigned char *out);
void sms4_encrypt_8blocks(sms4_key_t *key, const unsigned char *in, unsigned char *out);
void sms4_encrypt_16blocks(sms4_key_t *key, const unsigned char *in, unsigned char *out);

#define sms4_decrypt(key,in,out)  sms4_encrypt(key,in,out)
#define sms4_decrypt_8blocks(key,in,out) sms4_encrypt_8blocks(key,in,out)
#define sms4_decrypt_16blocks(key,in,out) sms4_encrypt_16blocks(key,in,out)

#ifdef __cplusplus
}
#endif
#endif

