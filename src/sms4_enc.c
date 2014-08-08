#include "sms4.h"
#include "sms4_lcl.h"


#define L32(x)						\
	((x) ^						\
	ROT32((x),  2) ^				\
	ROT32((x), 10) ^				\
	ROT32((x), 18) ^				\
	ROT32((x), 24))

#define ROUND(x0, x1, x2, x3, x4, i)			\
	x4 = x1 ^ x2 ^ x3 ^ *(rk + i);			\
	x4 = S32(x4);					\
	x4 = x0 ^ L32(x4)


void sms4_encrypt(sms4_key_t *key, const unsigned char *in, unsigned char *out)
{
	uint32_t *rk = key->rk;
	uint32_t x0, x1, x2, x3, x4;

	x0 = GET32(in     );
	x1 = GET32(in +  4);
	x2 = GET32(in +  8);
	x3 = GET32(in + 12);

	ROUNDS(x0, x1, x2, x3, x4);

	PUT32(x0, out     );
	PUT32(x4, out +  4);
	PUT32(x3, out +  8);
	PUT32(x2, out + 12);

	x0 = x1 = x2 = x3 = x4 = 0;
}

