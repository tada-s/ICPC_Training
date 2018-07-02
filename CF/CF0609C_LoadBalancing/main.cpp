#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    int m[100000 + 1];
    for(int i = 0; i < n; i++){
        scanf("%d", &m[i]);
    }

    int totalLoad = 0;
    for(int i = 0; i < n; i++){
        totalLoad += m[i];
    }

    sort(m, m + n);

    int second = 0;
    for(int i = 0; i < n - totalLoad % n; i++){
        second += abs(m[i] - totalLoad / n);
    }
    for(int i = n - totalLoad % n; i < n; i++){
        second += abs(m[i] - totalLoad / n - 1);
    }

    printf("%d\n", second / 2);

    return 0;
}
