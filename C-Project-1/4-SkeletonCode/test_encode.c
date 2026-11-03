#include <stdio.h>
#include "encode.h"
#include "types.h"

int main( int argc char *argv[])
{
    EncodeInfo encInfo;
    if(argc<4){
        printf("Insufficient inputs\n");
        return 1;
    }
    if(check_operation_type(argv[1][1])==e_encode){
        read_and_validate_encode_args(argv,&encInfo);


    }
    else{
        printf("Unsupported opration\n");
    }
    //call check_operation_type(argv[1][1])==e_encode);
    //Status read_and_validate_encode_args(argv)

    return 0;
}

OperationType check_operation_type(char opt){
    if(opt=='e'){
        return e_encode;
    }
    else if(opt=='d'){
        return e_decode;
    }
    else{
        return  e_unsupported;
    }
}

// if opt is 'e'
    // return e_encode
    // if opt is 'd'
    // return e_decode
    // else
    // return e_unsupoorted