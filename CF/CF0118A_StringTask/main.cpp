#include <bits/stdc++.h>

using namespace std;

bool isVowel(char c){
    c = tolower(c);
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
        return true;
    else
        return false;
}

int main(){
    char str[100 + 1];
    char str2[200 + 1];

    scanf("%s", str);
    int j = 0;
    int l = strlen(str);
    for(int i = 0; i < l; i++){
        if(!isVowel(str[i])){
            str2[j] = '.';
            str2[j+1] = tolower(str[i]);
            j += 2;
        }
    }
    str2[j] = '\0';
    printf("%s\n", str2);

    return 0;
}
