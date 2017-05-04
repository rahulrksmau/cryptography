#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char keyMatrix[5][5];

char* decrypt(char* ciphertext, char* key){
    int i, len;
    int r1 ,r2, c1, c2;
    r1 = r2 = c1 = c2 = 0;
    key = generateKeyMatrix(key);
    printf("\nKey Matrix :\n");
    display();
    printf("\nCipher text :\n");
    printf("%s",ciphertext);
    len = strlen(ciphertext);
    for(i=0; i<len; i+=2){

    position(ciphertext[i], &r1, &c1);
    position(ciphertext[i+1], &r2, &c2 );

        if(c1==c2){
                if(r1== 0 || r2 == 0){
                    if(r1 == 0){
                        r1 = 5;
                    }
                    if(r2 == 0){
                        r2 = 5;
                    }
                }
            ciphertext[i] = keyMatrix[(--r1)%5][c1];
            ciphertext[i+1]=keyMatrix[(--r2)%5][c2];

        }
        else if(r1==r2){
                if(c1== 0 || c2 == 0){
                    if(c1 == 0){
                        c1 = 5;
                    }
                    if(c2 == 0){
                        c2 = 5;
                    }
                }
            ciphertext[i] =keyMatrix[r1][(--c1)%5];
            ciphertext[i+1] =keyMatrix[r1][(--c2)%5];

        }
        else{
            ciphertext[i]= keyMatrix[r1][c2];
            ciphertext[i+1]=keyMatrix[r2][c1];

        }
    }
    ciphertext[len+1] = '\0';
    return ciphertext;
}
