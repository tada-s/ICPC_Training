#include <bits/stdc++.h>

using namespace std;

bool isVowel(char c){
    switch(c){
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

int getVowelRange(char str[]){
    int n = strlen(str);
    int nv = 0;
    for(int i = 0; i < n; i++){
        if(isVowel(str[i])){
            nv++;
        }
    }

    if(isVowel(str[0])){
        if(nv == 1){
            return n;
        }

        int v0;
        if(nv % 2 == 0){
            v0 = nv / 2;
        }else{
            v0 = nv / 2 + 1;
        }
        nv = 0;
        for(int i = 0; i < n; i++){
            if(isVowel(str[i])){
                nv++;
                if(nv == v0){
                    for(int j = i + 1; j < n; j++){
                        if(isVowel(str[j])){
                            return j - i;
                        }
                    }
                }
            }
        }
    }else{
        if(nv == 0){
            return 1;
        }else{
            return 0;
        }
    }
}

int main(){
    char str[100000 + 2];
    while(scanf("%s", str) != EOF){
        printf("%d\n", getVowelRange(str));
    }
    return 0;
}
