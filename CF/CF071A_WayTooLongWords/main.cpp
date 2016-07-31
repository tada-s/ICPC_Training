#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    char str[100 + 1];
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        if(strlen(str) > 10){
            printf("%c%d%c\n", str[0], strlen(str) - 2, str[strlen(str) - 1]);
        }else{
            printf("%s\n", str);
        }
    }
    return 0;
}
