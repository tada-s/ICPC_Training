#include <bits/stdc++.h>

using namespace std;

#define NOTDEFINED -1
#define EXISTMULTIPLE -2

int main(){
    int a[100000 + 1];
    int b[100000 + 1];
    int f[100000 + 1];
    int finv[100000 + 1];
    for(int i = 0; i < 100000 + 1; i++){
        f[i] = NOTDEFINED;
        finv[i] = NOTDEFINED;
    }

    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++){
        scanf("%d", &f[i]);
    }
    for(int i = 1; i <= n; i++){
        if(finv[f[i]] == NOTDEFINED){
            finv[f[i]] = i;
        }else{
            finv[f[i]] = EXISTMULTIPLE;
        }
    }

    for(int i = 1; i <= m; i++){
        scanf("%d", &b[i]);
    }

    bool impossible = false;
    bool ambiguity = false;
    for(int i = 1; i <= m; i++){
        if(finv[b[i]] == NOTDEFINED){
            impossible = true;
            ambiguity = false;
            printf("Impossible\n");
            break;
        }else if(finv[b[i]] == EXISTMULTIPLE){
            ambiguity = true;
        }else{
            a[i] = finv[b[i]];
        }
    }
    if(ambiguity == true){
        printf("Ambiguity\n");
    }else if(!impossible){
        printf("Possible\n%d", a[1]);
        for(int i = 2; i <= m; i++){
            printf(" %d", a[i]);
        }
    }
    return 0;
}
