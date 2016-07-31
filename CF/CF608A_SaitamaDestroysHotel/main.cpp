#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, s;
    scanf("%d %d", &n, &s);
    int maxF = s;
    int maxT = 0;
    int maxDif = 0;
    for(int i = 0; i < n; i++){
        int f, t;
        scanf("%d %d", &f, &t);
        if(t - (s - f) > maxDif){
            maxDif = t - (s - f);
            maxT = t;
            maxF = f;
        }
    }
    printf("%d\n", maxT  + maxF);
    return 0;
}
