#include <bits/stdc++.h>

using namespace std;


#define pb push_back

typedef struct {
    int key;
    int left;
    int right;
} node;
#define EMPTY -1
#define mod_X % 9999991
typedef long long ll;
vector<node> v;
vector<ll> size;
ll dp[25][25];

int f(int a, int b){
    if(dp[a][b] != EMPTY){
        return dp[a][b];
    }else{
        if(a == 0  || b == 0) dp[a][b] = 1;
        else dp[a][b] = (f(a - 1, b) + f(a, b - 1)) mod_X;
        return dp[a][b];
    }
}


void push(int key, int n){
    if(v.size() == 0){
        node m = {key, EMPTY, EMPTY};
        v.pb(m);
        size.pb(0);
    }
    size[n]++;
    if(v[n].key == key) return;
    if(key < v[n].key){
        if(v[n].left == EMPTY){
            node m = {key, EMPTY, EMPTY};
            v.pb(m);
            size.pb(0);
            v[n].left = v.size() - 1;
        }else{
            push(key, v[n].left);
        }
    }else{
        if(v[n].right == EMPTY){
            node m = {key, EMPTY, EMPTY};
            v.pb(m);
            size.pb(0);
            v[n].right = v.size() - 1;
        }else{
            push(key, v[n].right);
        }
    }
}

ll g(int n){
    ll l = 1;
    ll r = 1;
    ll a = 0;
    ll b = 0;
    if(v[n].left != EMPTY){
        l = g(v[n].left);
        a = size[v[n].left] + 1;
    }
    if(v[n].right != EMPTY){
        r = g(v[n].right) mod_X;
        b = size[v[n].right] + 1;
    }
    return (f(a, b) * ((l * r) mod_X)) mod_X;
}

int main(){
    //freopen("input.txt", "r", stdin);
    for(int i = 0; i < 21; i++){
        for(int j = 0; j < 21; j++){
            dp[i][j] = EMPTY;
        }
    }

    int t;
    scanf("%d", &t);
    for(int tt = 0; tt < t; tt++){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            int x;
            scanf("%d", &x);
            push(x, 0);
        }
        printf("%d\n", g(0));
        v.clear();
        size.clear();
    }
    return 0;
}
