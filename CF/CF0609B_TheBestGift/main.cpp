#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int genrefreq[10 + 1];
    for(int i = 0; i <= 10; i++){
        genrefreq[i] = 0;
    }

    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        genrefreq[x]++;
    }

    int result = 0;
    for(int i = 0; i <= m; i++){
        for(int j = i + 1; j <= m; j++){
            result += genrefreq[i] * genrefreq[j];
        }
    }

    printf("%d", result);

    return 0;
}
