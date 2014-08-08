all:
	gcc -Wall -O3 src/sms4_common.c src/sms4_setkey.c src/sms4_enc.c src/sms4_enc_nblks.c src/sms4_speed.c -o sms4speed_c

test:
	gcc -O3 -Wall src/sms4_common.c src/sms4_setkey.c src/sms4_enc.c src/sms4_enc_nblks.c src/sms4_test.c -o sms4test_c

		

clean:
	rm -fr *.o
	rm -fr sms4speed*
	rm -fr sms4test*

