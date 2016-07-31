#include <bits/stdc++.h>

using namespace std;

int ft[200001];
int n;

int lsone(int x){
    return x & -x;
}

int change(int k, int value){
    for(; k <= n; k += lsone(k)){
        ft[k] += value;
    }
}

int rsq(int a){
    int sum = 0;
    for(; a; a -= lsone(a)){
        sum += ft[a];
    }
    return sum;
}

int query(int x, int y){
    return rsq(y) - rsq(x - 1);
}

int main(){
    //freopen("input.txt", "r", stdin);
    int c = 1;
    int v[200001];
    scanf("%d", &n);
    while(n != 0){
        for(int i = 1; i <= n; i++){
            int x;
            scanf("%d", &x);
            v[i] = x;
        }
        for(int i = 0; i <= n; i++){
            ft[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            change(i, v[i]);
        }

        if(c > 1) putchar('\n');
        printf("Case %d:\n", c++);
        char str[5];
        int a, b;
        scanf("%s", str);
        while(strcmp(str,"END") != 0){
            scanf("%d%d", &a, &b);
            if(str[0] == 'S'){
                change(a, b - v[a]);
                v[a] = b;
            }else if(str[0] == 'M'){
                printf("%d\n", query(a, b));
            }

            scanf("%s", str);
        }
        scanf("%d", &n);
    }
    return 0;
}
