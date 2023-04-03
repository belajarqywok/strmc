/**
 * 
 * 
 *  Encryption Lib
 *  
 * 
*/



#include <stdio.h>
#include <string.h>

#include "logic.h"
#include "file_io.h"


void encrypt(char* argv[]) {


    // plainfile
    char* plainfile = read_plainfile(argv[2]);

    int plainfile_length = strlen(
        plainfile
    );


    // secret key
    char* key = argv[4];

    int key_length = strlen(
        key
    );


    // result file
    char* result_file = argv[6];


    // XOR logic (Lib: logic.h)
    int* logic_xor = enc_logic(

        // key params
        key,
        key_length,

        // plaintext params
        plainfile,
        plainfile_length
    );


    // write file method (Lib: "file_io.h")
    char hex[] = "hex";

    write_file(
        logic_xor, plainfile_length,
        result_file, *hex
    );


    // free XOR logic memory allocation
    free(logic_xor);
    free(plainfile);

    // printf("Status: Encryption Success!!!.\n");

}



void decrypt (char* argv[]) {

    // cipherfile
    struct read_cipherfile_struct cipherfile = read_cipherfile(argv[2]);


    // secret key
    char *key = argv[4];

    int key_length = strlen(
        key
    );


    // result file
    char *result_file = argv[6];


    // encrypt and decrypt XOR logic
    int* logic_xor = dec_logic(

        // key params
        key,
        key_length,

        // plaintext params
        cipherfile.hexs,
        cipherfile.hexs_length
    );


    // write file method (Lib: "file_io.h")
    char text[] = "text";

    write_file(
        logic_xor, cipherfile.hexs_length,
        result_file, *text
    );

    free(logic_xor);

    // printf("Status: Decryption Success!!!.\n");
    
}