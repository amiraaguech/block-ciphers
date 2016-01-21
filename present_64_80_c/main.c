
#include <stdio.h>
#include "constants.h"
#include "cipher.h"

int main () {
	#if defined(PRESENT_KEY_SIZE) && (PRESENT_KEY_SIZE==80)
		/*
		 * PRESENT 64/80
		 */
		u8 inputKey[] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
		u8 keys[PRESENT_BLOCK_SIZE/8*(PRESENT_ROUNDS+1)];
		u8 plainText[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

		encryptKeySchedule(inputKey, keys);

		printf("PlainText: %x, %x, %x, %x, %x, %x, %x, %x\n", 
			plainText[0], plainText[1], plainText[2], plainText[3], 
			plainText[4], plainText[5], plainText[6], plainText[7]);

		encrypt(plainText, keys);
		// cipherText is: 0x5ca2e27f 0x111a8fc8
		printf("After encryption: %x, %x, %x, %x, %x, %x, %x, %x\n", 
			plainText[0], plainText[1], plainText[2], plainText[3], 
			plainText[4], plainText[5], plainText[6], plainText[7]);
		
		decrypt(plainText, keys);
		printf("After decryption: %x, %x, %x, %x, %x, %x, %x, %x\n", 
			plainText[0], plainText[1], plainText[2], plainText[3], 
			plainText[4], plainText[5], plainText[6], plainText[7]);
	#else
	#if defined(PRESENT_KEY_SIZE) && (PRESENT_KEY_SIZE==128)
		/*
		 * PRESENT 64/128
		 */
	#endif
	#endif
	return 0;
}