#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    char c,b=1;
    c = getchar();
    while(c != EOF){
        if(c == '\"'){
            if(b){
                putchar('`');
                putchar('`');
                b = 0;
            }else{
                putchar('\'');
                putchar('\'');
                b = 1;
            }
        }else{
            putchar(c);
        }
        c = getchar();
    }
    return 0;
}
