#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int p[20000];
        for(int i = 0; i < n; i++){
            scanf("%d", &p[i]);
        }

        sort(p, p + n);

        int discount = 0;
        for(int i = n - 3; i >= 0; i -= 3){
            discount += p[i];
        }

        printf("%d\n", discount);
    }
    return 0;
}
