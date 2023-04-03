/**
 * 
 *  Logic Lib (XOR) Lib
 *  
 * 
*/



#include <stdlib.h>

#include "rc4lib/rc4.h"


int* enc_logic(char* key, int key_length, char* plaintext, int plaintext_length) {


    int* result = (int*) malloc(
        sizeof(int) * plaintext_length
    );


    int* keystream = RC4(key, key_length, plaintext_length);

    for(int i = 0; i < plaintext_length; i++) {

        result[i] = (int) (plaintext[i] ^ keystream[i]);
    }


    // free keystream (RC4) memory allocation
    free(keystream);

    return result;

}


int* dec_logic(char* key, int key_length, int* plaintext, int plaintext_length) {


    int* result = (int*) malloc(
        sizeof(int) * plaintext_length
    );


    int* keystream = RC4(key, key_length, plaintext_length);

    for(int i = 0; i < plaintext_length; i++) {

        result[i] = (int) (plaintext[i] ^ keystream[i]);
    }


    // free keystream (RC4) memory allocation
    free(keystream);

    return result;

}