#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    while(n != -1){
        int v[10];
        for(int i = 0; i < n; i++){
            scanf("%d", &v[i]);
        }
        sort(v, v + n);
        if(n % 2 == 1){
            printf("%d\n", v[n / 2]);
        }else{
            printf("%d\n", (v[n / 2 - 1] + v[n / 2]) / 2);
        }
        scanf("%d", &n);
    }
    return 0;
}
