/**
 * 
 *  Main
 * 
*/


#include <stdio.h>
#include <stdlib.h>

#include "lib/encrypt.h"
#include "lib/logging.h"


typedef unsigned char bool;


int main (int argc, char* argv[]) {


    /**
     * 
     *  Examples :
     *      main -f plain.txt -k test -o cipher.txt encrypt
     *      main --file plain.txt --key test --output cipher.txt encrypt
     * 
     *      main -f cipher.txt -k test -o plain.txt decrypt
     *      main --file cipher.txt --key test --output plain.txt decrypt
     * 
    */



    /**
     *  Plainfile And Cipherfile Option
     *  Option: [-f | --file]
    */
    const bool file_opt = (
        
        !strcmp(argv[1], "-f") ||
        !strcmp(argv[1], "--file")
    );



    /**
     *  Key Option
     *  Option: [-k | --key]
    */
    const bool key_opt = (

        !strcmp(argv[3], "-k") ||
        !strcmp(argv[3], "--key")
    );



    /**
     *  Output File Option
     *  Option: [-o | --output]
    */
    const bool output_opt = (

        !strcmp(argv[5], "-o") ||
        !strcmp(argv[5], "--output")
    );



    /**
     *  Encrypt And Decrypt Condition
     *  Option: [encrypt | decrypt]
    */
    if ((bool) file_opt && key_opt && output_opt) {

        // encrypt method (Lib: "lib/encrypt.h")
        if ((bool) !strcmp(argv[7], "encrypt")) encrypt(argv);
        
        // decrypt method (Lib: "lib/decrypt.h")
        else if ((bool) !strcmp(argv[7], "decrypt")) decrypt(argv);

    } else help_log();


    return 0;
    
    
}