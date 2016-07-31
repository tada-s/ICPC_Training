#include <bits/stdc++.h>

using namespace std;

int main(){
    char c;
    c = getchar();
    while(c != '#'){

        bool even = true;
        while(isdigit(c)){
            putchar(c);
            if(c == '1') even = !even;
            c = getchar();
        }
        if( (c == 'e' && even) || (c == 'o' && !even)){
            putchar('0');
        }else{
            putchar('1');
        }

        putchar('\n');
        getchar();
        c = getchar();
    }
    return 0;
}
