#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    int k;
    scanf("%d", &k);
    while(k != 0){
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < k; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            if(y > m && x > n){
                printf("NE\n");
            }else if(y < m && x > n){
                printf("SE\n");
            }else if(y > m && x < n){
                printf("NO\n");
            }else if(y < m && x < n){
                printf("SO\n");
            }else{
                printf("divisa\n");
            }
        }
        scanf("%d", &k);
    }
    return 0;
}
