#include <stdio.h>

cipher[] = { 'z','x', 'c', 'v','b','n','m','l','k','j','h','g','f','d','s','a','q','w','e','r','t','y','u','i','o','p' };

char* monolithicEncrypt(char* plaintext){
    int i,n,len = strlen(plaintext);
    for(i=0; i<len; i++){
          if(plaintext[i]>96 && plaintext[i]<123 )
            n= plaintext[i]- 'a';
          else if(plaintext[i]>64 && plaintext[i]<91 )
            n= plaintext[i]- 'A';
          else
            continue;
        plaintext[i] = cipher[n];
    }
    return plaintext;
}

char*  monolithicDecrypt(char* ciphertext ){
    int i,j,len = strlen(ciphertext);
    for(i=0; i<len; i++){
            j=0;
            if(ciphertext[i]>96 && ciphertext[i]<123)
                while(ciphertext[i]!= cipher[j])
                    j++;
            else
                continue;
            ciphertext[i] = j+'a';
    }
return ciphertext;
}
