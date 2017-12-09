#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("input.txt", "r",  stdin);

    int n;
    scanf("%d", &n);
    int v[50000 + 2];
    v[0] = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &v[i]);
    }
    v[n + 1] = v[n] + 1;

    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        int k;
        scanf("%d", &k);
        int l = 1;
        int u = n;
        int mid;
        while(l <= u){
            mid = (l + u) / 2;
            if(v[mid] <= k - 1){
                l = mid + 1;
            }else{
                u = mid - 1;
            }
        }
        if(u == 0){
            printf("X ");
        }else{
            printf("%d ", v[u]);
        }

        l = 1;
        u = n;
        while(l <= u){
            mid = (l + u) / 2;
            if(v[mid] < k + 1){
                l = mid + 1;
            }else{
                u = mid - 1;
            }
        }
        if(l == n + 1){
            printf("X\n");
        }else{
            printf("%d\n", v[l]);
        }

    }
    return 0;
}
