#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair

int main(){
    int n;
    scanf("%d", &n);
    while(n != 0){
        map<pair<int, int>, bool> m;
        int unpaired = 0;
        for(int i = 0; i < n; i++){
            int a, b;
            scanf("%d%d", &a, &b);

            if(a < b) swap(a, b);
            unpaired += m[mkp(a,b)] ? 1 : -1;
            m[mkp(a,b)] = !m[mkp(a,b)];
        }
        printf("%s\n", (unpaired == 0) ? "YES" : "NO");

        scanf("%d", &n);
    }
    return 0;
}
