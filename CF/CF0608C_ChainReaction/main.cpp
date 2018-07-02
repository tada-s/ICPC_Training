#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair
#define pb push_back

vector< pair<int, int> > v;

#define EMPTY -99999
int dp[100000];

int getLeftClosestBeacon(int pos){
    return lower_bound(v.begin(), v.end(), mkp(pos,0)) - v.begin() - 1;
}

int getmin(int i){
    if(i == -1){
        return 0;
    }
    if(dp[i] == EMPTY){
        dp[i] = 1 + getmin(getLeftClosestBeacon(v[i].first - v[i].second));
    }
    return dp[i];
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v.pb(mkp(a, b));
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        dp[i] = EMPTY;
    }

    int maxB = 0;
    for(int i = 0; i < n; i++){
        maxB= max(maxB, getmin(i));
    }

    printf("%d", n - maxB);
    return 0;
}
