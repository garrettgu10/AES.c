#include "aes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    uint8_t input[1024];
    uint8_t iv[16];
    for(int i = 0; i < 16; i++){
        iv[i] = rand() & 0xff;
    }
    for(int i = 0; i < 1024; i++){
        input[i] = i;
    }
    for(int i= 0; i < 1024; i++){
        printf("%02x ", input[i]);
    }
    printf("\n----------------------\n");
    uint8_t key[16] = {
        0x2b, 0x28, 0xab, 0x09,
        0x7e, 0xae, 0xf7, 0xcf,
        0x15, 0xd2, 0x15, 0x4f,
        0x16, 0xa6, 0x88, 0x3c
    };

    uint8_t temp[1024];
    aes_encrypt_pcbc(input, key, iv, 1024 / 16, temp);
    for(int i= 0; i < 1024; i++){
        printf("%02x ", temp[i]);
    }
    printf("\n----------------------\n");
    aes_decrypt_pcbc(temp, key, iv, 1024 / 16, input);

    for(int i= 0; i < 1024; i++){
        printf("%02x ", input[i]);
        if(input[i] != (i & 0xff)) {
            printf("ERROR");
        }
    }
}