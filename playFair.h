#ifndef PLAYFAIR_H
#define PLAYFAIR_H
//Playfair encryption
char* encrypt(char*, char*);

char* upperAndReplace(char*);
void position(char , int* , int*);
void generateKeyMatrix(char*);
void display();
char* removeC(char* , char );

char* dycrypt(char*, char*);



// Ceasar Encryption
char* encryptCeasar(char*, int);
char* decryptCeasar(char* , int);

// monolithic
char* monolithicEncrypt(char *);
char* monolithicDecrypt(char*);

// Vigenere
int* keyConvert(char*);
char* vigenereEncrypt(char*, char*);
char* vigenereDecrypt(char*, char*);


#endif // PLATFAIR_H
