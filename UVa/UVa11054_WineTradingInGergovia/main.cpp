#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    while(n != 0){
        int a[100000];
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        long long accum = 0;
        long long cost = 0;
        for(int i = 0; i < n; i++){
            cost += accum > 0 ? accum : -accum;
            accum += a[i];
        }
        printf("%ld\n", cost);
        scanf("%d", &n);
    }
    return 0;
}
