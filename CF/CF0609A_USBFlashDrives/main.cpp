#include <bits/stdc++.h>


using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int a[1000 + 1];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        a[i] = -a[i];
    }

    sort(a, a + n);

    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum -= a[i];
        if(sum >= m){
            printf("%d\n", i + 1);
            break;
        }
    }

    return 0;
}
