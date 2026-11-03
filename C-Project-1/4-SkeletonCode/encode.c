#include <stdio.h>
#include "encode.h"
#include "types.h"

/* Function Definitions */

/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in our case)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 */
uint get_image_size_for_bmp(FILE *fptr_image)
{
    uint width, height;
    // Seek to 18th byte
    fseek(fptr_image, 18, SEEK_SET);

    // Read the width (an int)
    fread(&width, sizeof(int), 1, fptr_image);
    printf("width = %u\n", width);

    // Read the height (an int)
    fread(&height, sizeof(int), 1, fptr_image);
    printf("height = %u\n", height);

    // Return image capacity
    return width * height * 3;
}

/* 
 * Get File pointers for i/p and o/p files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
// Status open_files(EncodeInfo *encInfo)
// {
//     // Src Image file
//     encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");
//     // Do Error handling
//     if (encInfo->fptr_src_image == NULL)
//     {
//     	perror("fopen");
//     	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);

//     	return e_failure;
//     }

//     // Secret file
//     encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
//     // Do Error handling
//     if (encInfo->fptr_secret == NULL)
//     {
//     	perror("fopen");
//     	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);

//     	return e_failure;
//     }

//     // Stego Image file
//     encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "w");
//     // Do Error handling
//     if (encInfo->fptr_stego_image == NULL)
//     {
//     	perror("fopen");
//     	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);

//     	return e_failure;
//     }

//     // No failure return e_success
//     return e_success;
// }
Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo){



    int n=strlen(argv[2]);
    if(n<4){
        printf("Invalid source image\n");
        return e_failure;
    }
    char ch[4]=".bmp";
    for(int i=0;i<4;i++){
        if(argv[2][n-4+i]!=ch[i]){
             return e_failure;
        }

    }
    encInfo->src_image_fname = argv[2];
    encInfo->secret_fname = argv[3];
    if(argv[4]==NULL){
        encInfo->stego_image_fname = "default.bmp";
    }
    else{
        encInfo->stego_image_fname = argv[4];
    }

    int n1=strlen(encInfo->stego_image_fname);
    if(n1<4){
        printf("Invalid output image\n");
        return e_failure;
    }
    for(int i=0;i<4;i++){
        if(encInfo->stego_image_fname[n1-4+i]!=ch[i]){
             return e_failure;
        }

    }
    if(open_files(encInfo)==e_failur){
        return e_failure;
    }
    else{
        return e_success;
    }











//   argument 2 =  check the argv[2] must be having ".bmp" extn
//         if yes,encinfo->src_image_fname = argv[2];
//             if yes then open the file in read mode argv[2];
//             encInfo->fptr_src_image = fopen()
//             if file not present, return e_failure;
//         if not,return e_failure;

//  argument 3 = check the argv[3] is valid file;
//         encLnfo->secret_fname =argv[3]
//         is the file is present or not;
//         if present,encInfo->fptr_secret = fopen()
//         if not,return e_failure;

//  argument 4 = check the argv[4] is Null or not;
//         if not null,encinfo->stego_image_fname = argv[4]
//         if NULL,encinfo->stego_image_fname = "default.bmp";

//  check the file extn is only of ".bmp".
//         if not ,return e_failure;

// open the file in write mode,and store the file pionter to structure member.

}
Status do_encoding(EncodeInfo *encInfo){
    //check_capacity(encInfo)==efailure
    //print the error msg,return e_failure
    //if success continue;
   //call copy_bmp_header( encInfo->fptr_src_image,encInfo->fptr_stego_image)==e_failure
   //else print the error msg of e_failure

   //encode_magic_string(MAGIC_STRING)==e_failure
   printf errpr msg,return e_failure

   //char *dot = strchr(argv[3],'.')
   //strcpy(extn_secret_file,dot)
   //Status encode_secret_file_extn_size(strlen(encode_secret_file),encInfo);
   
}
Status check_capacity(EncodeInfo *encInfo){
    //get_image_size_for_bmp(encInfo->fptr_src_image) >
    //((get_file_size(encInfo->fptr_secret)+14)*8)
    //return e_success
    //else
    //return e_failure
}
Unit get_file_size(FILE *fptr){
     //fseek() to SEEK_END
     //return ftell()
}
Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image){
    //rewind(),src and secret files
    //declare a buff of 54 bytes,char buff[54]
    //read 54 bytes from src image to buff
    //write 54 bytes from buff to dest image
}
Status encode_magic_string(const char *magic_string, EncodeInfo *encInfo){
    //declare a buff of 8 bytes
 //run a loop for lenght of magic string   #* run will be twice
    //read 8 bytes fromsrc_image int buff
    //encode_byte_to_lsb(magic_string[],buffer)
    //write 8 byte of encoded data from buff to dest_image

}
status encode_byte_to_lsb(char data, char *image_buffer){

 //run a loop for 8 times 
    // check that nth bit is set or not
        if set,clear the lsb of image_buffer[] 0th index;
        if clear,clear the lsb of image_buffer[] 0th index;

        return e_success or e_failure;

}
Status encode_secret_file_extn_size(uint size, EncodeInfo *encInfo){
    //declare a buff of 32 bytes
    // read 32 bytes of buff from src_image
    //encode buff to dest_image
    //return e_failure
}
Status encode_byte_to_lsb(uint size, char *image_buffer){
    run a loop for 32 times 
    // check that nth bit is set or not
        if set,clear the lsb of image_buffer[] 0th index;
        if clear,clear the lsb of image_buffer[] 0th index;

        return e_success or e_failure;

}

Status encode_secret_file_extn(const char *file_extn, EncodeInfo *encInfo){
//declare a buff of 8 bytes
 //run a loop for lenght of file_extn   #* run will be twice
    //read 8 bytes fromsrc_image int buff
    //encode_byte_to_lsb(file_extn[],buffer)
    //write 8 byte of encoded data from buff to dest_image

    return e_failure
}