/**
 * 
 * 
 *  Decryption Method
 *  
 * 
*/

#include <stdio.h>
#include <string.h>

#include "logic.h"
#include "file_io.h"


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
    int* logic_xor = logic(

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
    
}