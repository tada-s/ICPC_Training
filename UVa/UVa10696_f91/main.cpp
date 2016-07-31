#include <bits/stdc++.h>

using namespace std;

int f91(int n){
    return (n > 100) ? n-10 : f91(f91(n+11));
}

int main(){
    int n;
    scanf("%d", &n);
    while(n != 0){
        printf("f91(%d) = %d\n", n, f91(n));
        scanf("%d", &n);
    }
    return 0;
}
