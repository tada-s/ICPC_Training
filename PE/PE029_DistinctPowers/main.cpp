#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ipow(ll b, ll n){
    if(n == 0) return 1;
    ll aux = pow(b, n/2);
    if(n%2 == 0){
        return aux * aux;
    }else{
        return aux * aux * b;
    }
}

ll ibase(ll n){
    for(int i = 2; i <= n; i++){
        for(int j = 0; pow(i,j) <= n; j++){
            if(pow(i,j) == n){
                return i;
            }
        }
    }
    return n;
}

ll iexp(ll n){
    for(int i = 2; i <= n; i++){
        for(int j = 0; pow(i,j) <= n; j++){
            if(pow(i,j) == n){
                return j;
            }
        }
    }
    return n;
}

int main(){
    int mat[601][601];
    for(int i = 0; i <= 600; i++){
        for(int j = 0; j <= 600; j++){
            mat[i][j] = 0;
        }
    }
    int c = 0;
    for(int a = 2; a <= 100; a++){
        int x = ibase(a);
        int e = iexp(a);
        for(int b = 2; b <= 100; b++){
            if(mat[x][e*b] == 0){
                mat[x][e*b] = 1;
                c++;
            }
        }
    }
    printf("%d",c);
    return 0;
}
