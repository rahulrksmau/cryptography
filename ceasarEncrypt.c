#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char* encryptCeasar(char* plaintext, int shift){
    int len, i, n;
    len = strlen(plaintext);
    for(i=0; i<len; i++){
        n= plaintext[i];
        if(n>64 && n<91){
             plaintext[i] = (plaintext[i]-65 + shift)%26 + 65;
            }
        else if(n>96 && n<123){
             plaintext[i] = (plaintext[i]-97 + shift)%26 + 97;
            }
    }
   // printf("Cipher text is :\n");
   // printf("%s", plaintext);
    return plaintext;
}

char* decryptCeasar(char* cipher , int shift){
    int len, i, n;
    len = strlen(cipher);
    for(i=0; i<len; i++){
        n= cipher[i];
        if(n>64 && n<91){
             cipher[i] = (cipher[i]-65 +(26-shift))%26 + 65;
            }
        else if(n>96 && n<123){
             cipher[i] = (cipher[i]-97 + (26-shift))%26 + 97;
            }
    }
   // printf("\nPlain text is :\n");
   // printf("%s", cipher);

    return cipher;
}
