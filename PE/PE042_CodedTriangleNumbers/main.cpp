#include <bits/stdc++.h>

using namespace std;

int t(int n){
    return ( n*(n+1) ) / 2;
}

bool isTriangleNumber(int n){
    for(int i = 1; t(i) <= n; i++){
        if(t(i) == n) return true;
    }
    return false;
}

int main(){
    FILE *fp = NULL;
    fp = fopen("p042_words.txt", "r");
    if(fp == NULL){
        return 1;
    }else{
        int c = 0;
        char str[1000] = "";
        while(!feof(fp)){
            fscanf(fp, "\"%[A-Z]\",", str);
            int sum = 0;
            for(int i = 0; str[i] != '\0'; i++){
                sum += str[i] - 'A' + 1;
            }
            if(isTriangleNumber(sum)){
                c++;
            }
        }
        fclose(fp);
        printf("%d", c);
    }
    return 0;
}
