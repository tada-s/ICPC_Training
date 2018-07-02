#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    char str[100];
    scanf("%s", str);
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < n/2; i++){
        if(str[i] == '4' || str[i] == '7'){
            sum1 += str[i] - '0';
        }else{
            printf("NO");
            return 0;
        }
    }
    for(int i = n/2; i < n; i++){
        if(str[i] == '4' || str[i] == '7'){
            sum2 += str[i] - '0';
        }else{
            printf("NO");
            return 0;
        }
    }
    printf((sum1 == sum2) ? "YES" : "NO");
    return 0;
}
