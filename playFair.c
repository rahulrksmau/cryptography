
void playfairCryptoghraphy{
     char key[25], plainText[1000], *plaintext, *cipher;
     int len, i;
     printf("\nEnter Key:\n");
                gets(key);
                printf("Enter plain Text :\n");
                gets(plainText);
                cipher = encrypt( plainText, key );
                len = strlen(cipher);
                printf("Cipher Text is :\n");
                for(i=0; i<len; i+=2){
                    printf("%c%c",cipher[i],cipher[i+1]);
                    printf(" ");
                }

                plaintext = decrypt(cipher, key);
                printf("\nPlain text: \n");
                printf("%s",plaintext);
}

