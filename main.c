#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char key[25], plainText[1000], *plaintext, *cipher;
    int i,len, ch;
    char choice;
    int shift;
    printf("Enter the Cryptography technique: \n");
    printf("1).Playfair  Cryptography .  \n");
    printf("2).Ceasar  Cryptography .  \n");
    printf("3).Monoalphabetic  Cryptography .  \n");
    printf("4).Vigenere  Cryptography .  \n");
    do{
        printf("Enter choice : ");
        scanf("%d",&ch);
        while(getchar()!='\n');
        switch(ch){
         case 1:    printf("\n---------------*Playfair Cryptoghaphy Technique*---------------\n");
                    printf("\n----*Encryption*----\n");
                    printf("\nEnter Key:\n");
                    gets(key);
                    printf("Enter plain Text :\n");
                    gets(plainText);
                    cipher = encrypt( plainText, key );
                    len = strlen(cipher);
                    printf("\nCipher Text is :\n");
                    for(i=0; i<len; i+=2){
                        printf("%c%c",cipher[i],cipher[i+1]);
                        printf(" ");
                    }
                     printf("\n");
                    printf("\n----*Decryption*----\n");
                    plaintext = decrypt(cipher, key);
                    printf("\n\nPlain text: \n");
                    printf("%s\n",plaintext);
                break;
         case 2:    printf("\n---------------*Ceasar Cryptoghaphy Technique*---------------\n");
                    printf("\n----*Encryption*----\n");
                    printf("\nEnter plain Text :\n");
                    gets(plainText);
                    printf("Enter shift :\n");
                    scanf("%d%*c",&shift);
                    cipher = encryptCeasar(plainText, shift);
                    printf("\nCipher Text is :\n");
                    printf("%s", cipher);
                    printf("\n----*Decryption*----\n");
                    plaintext = decryptCeasar(cipher , shift);
                    printf("\nPlain Text is :\n");
                    printf("%s", plaintext);
                    printf("\n\nUsing Key -> %d \n",shift);
            break;
         case 3:    printf("\n---------------*Monoalphabetic Cryptoghaphy Technique*---------------\n");
                    printf("\n----*Encryption*----\n");
                    printf("Enter the plain text :");
                    gets(plainText);
                    cipher = monolithicEncrypt(plainText);
                    printf("\nCipher Text is :\n");
                    printf("%s", cipher);
                    printf("\n----*Decryption*----\n");
                    plaintext = monolithicDecrypt(cipher );
                    printf("\nPlain Text is :\n");
                    printf("%s", plaintext);

            break;

         case 4:
                    printf("\n---------------*Vigenere Cryptoghaphy Technique*---------------\n");
                    printf("\n----*Encryption*----\n");
                    printf("Enter the key : ");
                    gets(key);
                    printf("\nEnter the message : ");
                    gets(plainText);
                    cipher = vigenereEncrypt(plainText , key);
                    printf("\nCipher Text is :\n");
                    puts(cipher);
                    printf("\n----*Decryption*----\n");
                    plaintext = vigenereDecrypt(cipher, key );
                    printf("\nPlain Text is :\n");
                    puts(plaintext);

            break;
         default :
            break;

        }
    printf("\nAgain press y for repeat......: ");
    scanf("%c",&choice);
    }while(choice == 'y');
    return 0;
}
