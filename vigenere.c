#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

char* removeChar(char* text){
    char *newtext ;
    int i,j,len = strlen(text);
    newtext = (char*)calloc(len , sizeof(char));
    j = 0;
    for(i=0; i<len; i++){
        if(text[i]>='a' && text[i]<='z' ){
            newtext[j] = text[i];
            j++;}
        else if(text[i]>='A' && text[i]<='Z'){
            newtext[j] = text[i];
            j++;}
    }
    newtext[j] = '\0';
    return newtext;
}

char* vigenereEncrypt(char* plaintext ,char* key ){
    int i,len1,len =strlen(key) ;
    int arr[len] , n;
    for(i=0 ; i<len; i++){
        arr[i] = key[i]-'a';
    }
    plaintext = removeChar(plaintext);
    puts(plaintext);
    len1 = strlen(plaintext);
    char *cipher= (char*)calloc(len1 , sizeof(char));
    for(i=0, n=0; i<len1; i++){
        n = n%len;
        cipher[i] = (plaintext[i]-'a' + arr[n] )%26;
        n++;
        cipher[i] = cipher[i]+'a';
    }
    cipher[i] = '\0';
    return cipher;
}

char* vigenereDecrypt(char* cipher , char* key){
    int i,len1,len =strlen(key) ;
    int arr[len] , n;

    for(i=0 ; i<len; i++){
        arr[i] = key[i]-'a';
    }
    len1 = strlen(cipher);
    char *plaintext= (char*)calloc(len1 , sizeof(char));

    for(i=0, n=0; i<len1; i++){
        n = n%len;
        plaintext[i] = (cipher[i]-'a' - arr[n] + 26)%26;
        n++;
        plaintext[i] = plaintext[i]+'a';
       // printf("%c->%d",plaintext[i],plaintext[i]);
    }
    plaintext[i] = '\0';
    //puts(plaintext);
    return plaintext;
}

