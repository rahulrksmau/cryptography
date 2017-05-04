#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char keyMatrix[5][5];


char* upperAndReplace(char *plaintext){
    int i, len = strlen(plaintext);
    for(i=0; i<len; i++){
        plaintext[i]= toupper(plaintext[i]);
        if(plaintext[i]=='J'){
            plaintext[i] = 'I';
        }
    }
    return plaintext;
}
char* removeC(char* line, char noreq){
    int len = strlen(line), i, j= 0;
    char* newLine = (char*)malloc(len*sizeof(char));
    for(i=0; i<len; i++){
        if(line[i] != noreq ){
            newLine[j] = line[i];
            j++;
        }
    }
    newLine[j] = '\0';
    return newLine;
}

void generateKeyMatrix(char* key){
    int i, len =strlen(key) ,a =0, b =0;
    int alpha[26]= {0};
    for(i=0 ; i<len; i++){
        alpha[key[i]-65]++;
        if(alpha[key[i]-65]==1){
            keyMatrix[a][b++] = key[i];
                if(b==5){
                    b = 0;
                    a++;
                }
        }
    }
    alpha[9]=1;
    for(i=0; i<26; i++){
        if(alpha[i]==0){
            keyMatrix[a][b++] = i+ 'A';
                if(b==5){
                    b = 0;
                    a++;
                }
        }
    }
}

void display(){

    int i,j;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++)
            printf("%c ",keyMatrix[i][j]);
        printf("\n");
    }
}

void position(char ch, int* r, int* c){
    int i,j;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++)
            if(keyMatrix[i][j]==ch){
                *r = i;
                *c = j;
                break;
                }
    }
}

char* encrypt(char *plaintext , char *key){
    int i, len;
    int r1 ,r2, c1, c2;
    r1 = r2 = c1 = c2 = 0;
    plaintext = upperAndReplace(plaintext);
    plaintext = removeC(plaintext, ' ');
    len = strlen(plaintext);
    key = upperAndReplace(key);
    key = removeC(key, ' ');

    printf("Key is :");
    printf("%s\n",key);

    generateKeyMatrix(key);
    display();
    printf("len ->%d\n",len);
    if(len%2 != 0){
        plaintext[len] = 'X';
    }
    plaintext[len+1] = '\0';
    printf("\nPlain text is :");
    printf("%s\n",plaintext);
    len = strlen(plaintext);
printf("len ->%d\n",len);
   for(i=0; i<len; i+=2){
    position(plaintext[i], &r1, &c1);
    position(plaintext[i+1], &r2, &c2 );

        if(c1==c2){
            plaintext[i] = keyMatrix[(++r1)%5][c1];
            plaintext[i+1]=keyMatrix[(++r2)%5][c2];

        }
        else if(r1==r2){
            plaintext[i] =keyMatrix[r1][(++c1)%5];
            plaintext[i+1] =keyMatrix[r1][(++c2)%5];

        }
        else{
            plaintext[i]= keyMatrix[r1][c2];
            plaintext[i+1]=keyMatrix[r2][c1];

        }
    }

   // plaintext[len+1] = '\0';
    return plaintext;
}



