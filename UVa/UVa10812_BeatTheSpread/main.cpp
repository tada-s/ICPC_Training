#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if(a < b || (a + b) % 2 != 0){
            printf("impossible\n");
        }else{
            printf("%d %d\n", (a + b) / 2, (a - b) / 2);
        }
    }
    return 0;
}
