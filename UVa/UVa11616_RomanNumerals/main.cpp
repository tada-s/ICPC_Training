#include <bits/stdc++.h>

using namespace std;

int value(char c){
    switch(c){
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return -1;
    }
}

//int v[7] = {1, 5, 10, 50, 100, 500, 1000};
char r[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

void printRoman(int digit, int position){
    if(digit == 9){
        printf("%c%c", r[2 * position - 2], r[2 * position]);
        digit = 0;
    }else if(digit >= 5){
        printf("%c", r[2 * position - 1]);
        digit -= 5;
    }else if(digit == 4){
        printf("%c%c", r[2 * position - 2], r[2 * position - 1]);
        digit = 0;
    }
    for(int i = 0; i < digit; i++){
        printf("%c", r[2 * position - 2]);
    }
}

int main(){
    char str[128];
    while(scanf("%s", str) != EOF){
        int sum = 0;
        if(isdigit(str[0])){
            int l = strlen(str);
            for(int i = 0; str[i] != '\0'; i++){
                printRoman(str[i] - '0', l - i);
            }
            printf("\n");
        }else{
            for(int i = 0; str[i] != '\0'; i++){
                if(str[i + 1] != '\0'){
                    if(value(str[i]) < value(str[i + 1])){
                        sum += value(str[i + 1]) - value(str[i]);
                        i++;
                    }else{
                        sum += value(str[i]);
                    }
                }else{
                    sum += value(str[i]);
                }
            }
            printf("%d\n", sum);
        }
    }
    return 0;
}
