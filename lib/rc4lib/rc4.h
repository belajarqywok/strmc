/**
 * 
 *  RC4 (Ron's Code / Rivest's Cipher) Lib
 * 
*/

#include <stdlib.h>

#include "ksa.h"
#include "prng.h"


int* RC4(char* key, int key_length, int plaintext_length) {

    /**
     *  KSA result  
    */
    int* ksa_result  = KSA(

        key,
        key_length
    );


    /**
     *  PRNG result
    */
    int* prng_result = PRNG(

        ksa_result, 
        plaintext_length
    );


    // free KSA memory allocation
    free(ksa_result);
    
    return prng_result;

}