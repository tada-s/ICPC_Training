#include <bits/stdc++.h>

using namespace std;

#define INF 1<<29

#define pb push_back
#define EMPTY -1
vector<int> v;
int dp[50+2][50+2];

int minCost(int l, int u){
    if(dp[l][u] != EMPTY){
        return dp[l][u];
    }else{
        if(u - l == 1){
            return 0;
        }else{
            int minC = INF;
            for(int i = l + 1; i < u; i++){
                minC = min(minC, minCost(l, i) + minCost(i, u));
            }
            minC = v[u] - v[l] + minC;
            dp[l][u] = minC;
            return dp[l][u];
        }
    }
}

int main(){
    int l;
    scanf("%d", &l);
    while(l != 0){
        int n;
        scanf("%d", &n);

        v.pb(0);
        for(int i = 0; i < n; i++){
            int x;
            scanf("%d", &x);
            v.pb(x);
        }
        v.pb(l);

        for(int i = 0; i <= n+1; i++){
            for(int j = 0; j <= n+1; j++){
                dp[i][j] = EMPTY;
            }
        }
        printf("The minimum cutting is %d.\n", minCost(0, n+1));
        v.clear();

        scanf("%d", &l);
    }

}


