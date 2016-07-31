#include <iostream>
#include <stdio.h>
using namespace std;

char const* key1 = "1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.";
char const* key2 = "234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./";

char getOriginalKey(char c){
    for(int i = 0; key2[i] != '\0'; i++){
        if(c == key2[i]) return key1[i];
    }
    return c;
}

int main()
{
    char c;
    while((c = getchar())!=EOF){
        putchar(getOriginalKey(c));
    }
    return 0;
}
