#include <bits/stdc++.h>

using namespace std;

int cycle(char str[]){
    bool flag;
    int n = strlen(str);
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            flag = false;
            for(int j = 0; j < i && !flag; j++){
                for(int k = j; k < n; k += i){
                    if(str[j] != str[k]){
                        flag = true;
                        break;
                    }
                }
                if(flag == true){
                    break;
                }
            }
            if(flag == false){
                return i;
            }
        }
    }
    return -1;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        char str[128];
        scanf("%s", str);
        printf("%d\n", cycle(str));
        if(i < n - 1){
            printf("\n");
        }
    }
    return 0;
}
