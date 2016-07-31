#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    while(n){
        if(n % 2 == 0 && !(n == 2)){
            printf("%d\n", n + n / 2);
            for(int i = 1; i <= n - 1; i++){
                printf("%d %d\n", i, i + 1);
            }
            printf("%d %d\n", n, 1);

            for(int i = 1; i <= n / 2; i ++){
                printf("%d %d\n", i, i + n / 2);
            }
        }else{
            printf("Impossible\n");
        }
        scanf("%d", &n);
    }
    return 0;
}
