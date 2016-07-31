#include <bits/stdc++.h>

using namespace std;

int code(char c){
    switch(c){
    case 'B':
    case 'P':
    case 'F':
    case 'V':
        return 1;
    case 'C':
    case 'S':
    case 'K':
    case 'G':
    case 'J':
    case 'Q':
    case 'X':
    case 'Z':
        return 2;
    case 'D':
    case 'T':
        return 3;
    case 'L':
        return 4;
    case 'M':
    case 'N':
        return 5;
    case 'R':
        return 6;
    default:
        return -1;
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    char str[64];
    printf("%9s%-25s%s\n", " ", "NAME", "SOUNDEX CODE");
    while(scanf("%s", str) != EOF){
        char sndx[5] = "A000";
        sndx[0] = str[0];
        int k = 1;
        for(int i = 1; str[i] != '\0'; i++){
            if(code(str[i]) != -1 && code(str[i]) != code(str[i-1])){
                sndx[k] = code(str[i]) + '0';
                k++;
                if(k == 4){
                    break;
                }
            }
        }
        printf("%9s%-25s%s\n", " ", str, sndx);
    }
    printf("%19s%s\n", " ", "END OF OUTPUT");
    return 0;
}
