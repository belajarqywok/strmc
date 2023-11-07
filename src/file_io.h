/**
 * 
 * 
 *  File I/O
 * 
 * 
*/
#include <stdio.h>
#include <string.h>

/*
 *  Open File
*/
FILE* _fileops(char* filename, char* permission)
{
    FILE* file;
    file = fopen(filename, permission);

    return file;
}

/**
 * 
 *  Write File Method
 * 
*/
void write_file(int* result_text, int length_result_text, char* output_file, char type)
{
    FILE* file = _fileops(output_file, "w");

    char hex[] = "hex";
    char text[] = "text";

    if (type == *hex) {
        for (int i = 0; i < length_result_text; i++) {
            fprintf(file, "%x ", result_text[i]);
        }

    } else if (type == *text) {
        for (int i = 0; i < length_result_text; i++) {
            fprintf(file, "%c", result_text[i]);
        } 
    }

    fclose(file);
}

/**
 * 
 *  Read Plainfile Method
 * 
*/
char* read_plainfile(char* input_file)
{
    char* buffer;
    long file_size;
    size_t result;

    FILE* file = _fileops(input_file, "r");

    // seek to the end of the file
    fseek(file, 0, SEEK_END);  

    // get the file size
    file_size = ftell(file); 

    // seek back to the beginning of the file
    rewind(file);

    // allocate memory for buffer
    buffer = (char*) malloc(file_size * sizeof(char));  

    // read the file into the buffer
    result = fread(buffer, 1, file_size, file);

    fclose(file);

    return buffer;
}

/**
 * 
 *  Read Hexfile Method
 * 
*/
struct read_cipherfile_struct
{
    int* hexs;
    int hexs_length;
};

struct read_cipherfile_struct read_cipherfile(char* input_file)
{
    char hex_char;
    char hex_char_next;

    long file_size;

    FILE* file = _fileops(input_file, "r");

    // seek to the end of the file
    fseek(file, 0, SEEK_END);  

    // get the file size
    file_size = ftell(file); 

    // seek back to the beginning of the file
    rewind(file);

    struct read_cipherfile_struct* HX;

    HX = (struct read_cipherfile_struct*) 
        malloc(sizeof(struct read_cipherfile_struct)
    );

    // file hex allocation
    int F_HEX_i = 0;

    int* F_HEX = (int*) malloc(
        sizeof(int) * file_size
    );

    // check and changed to an infinite loop with a break statement
    while(1) { 
        hex_char = fgetc(file);

        // declaring a character array with a string
        char hex_char_allo[2] = {hex_char, '\0'}; 
        char forbidden_char[] = " ";

        // added check for EOF
        if(hex_char != *forbidden_char && hex_char != EOF) {  
            char hexstring[] = "0x";
            hex_char_next = fgetc(file);

            // added check for EOF
            if(hex_char_next != *forbidden_char && hex_char_next != EOF) {

                // declaring a character array with a string
                char hex_char_next_allo[2] = {hex_char_next, '\0'};

                strcat(hexstring, hex_char_allo);
                strcat(hexstring, hex_char_next_allo);

            } else strcat(hexstring, hex_char_allo);
            
            int hexnumber = (int) strtol(hexstring, NULL, 0);

            F_HEX[F_HEX_i] = hexnumber;
            F_HEX_i += 1;

        // added check for EOF
        } else if (hex_char == EOF) break;

        else continue;
    }

    // added file close statement
    fclose(file); 

    HX -> hexs = F_HEX;
    HX -> hexs_length = F_HEX_i;

    return *HX;
}
