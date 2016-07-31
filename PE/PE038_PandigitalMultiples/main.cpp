#include <bits/stdc++.h>

using namespace std;

bool isPandigital(char* str){
    int digit[10];
    for(int i = 0; i < 10; i++) digit[i] = 0;

    int i = 0;
    while(str[i] != '\0'){
        digit[str[i] - '0']++;
        i++;
    }

    if(digit[0] != 0) return false;
    for(int i = 1; i < 10; i++){
        if(digit[i] != 1) return false;
    }
    return true;
}

int getPandigitalMultiple(int n){
    int m = 1;
    char str[20] = "";
    char auxstr[10];
    while(strlen(str) < 9){
        sprintf(auxstr, "%d", m*n);
        strcat(str, auxstr);
        if(strlen(str) == 9){
            if(isPandigital(str)){
                return m;
            }
        }
        m++;
    }
    return -1;
}

int getConcatenatedMultiples(int x, int m){
    char str[20] = "";
    char auxstr[10];
    for(int i = 1; i <= m; i++){
        sprintf(auxstr, "%d", i*x);
        strcat(str, auxstr);
    }
    return atoi(str);
}

int main(){
    int max = 0;
    for(int i = 1e3; i < 1e4; i++){
        int n = getPandigitalMultiple(i);
        if(n > 1){
            max = getConcatenatedMultiples(i, n);
        }
    }
    printf("%d", max);
    return 0;
}
