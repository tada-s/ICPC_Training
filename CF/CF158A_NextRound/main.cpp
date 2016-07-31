#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int v[50 + 1];
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    int c = 0;
    for(int i = 0; i < n; i++){
        if(v[i] >= v[k - 1] && v[i] != 0){
            c++;
        }
    }

    printf("%d\n", c);
    return 0;
}
