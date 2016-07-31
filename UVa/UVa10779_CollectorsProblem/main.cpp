#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define pb push_back
#define mkp make_pair
#define II ({int a; scanf("%d",&a);a;})
#define LL ({ll a; scanf("%lld",&a);a;})
#define repab(v,a,b) for(__typeof(b) v = a; v <= b; v++)
#define repba(v,a,b) for(__typeof(b) v = b; v >= a; v--)
#define rep(v,n) for(__typeof(n) v = 0; v <= n; v++)
#define repstl(i, c) for(__typeof(c.begin()) i = c.begin(); i != c.end(); i++)
#define all(x) x.begin(), x.end()
#define INF 1 << 29
#define EPS 1e-9

int n,m;
int stk[11][27];
int stkc[11];
int stkleft[11][27];
priority_queue<ii> pq;




void initPQ(){
    rep(j,n){
        if(stk[0][j] > 1){
            stkleft[0][j]++;
            pq.push(mkp(stk[0][j],j));
        }
    }
    repab(i,1,n){
        rep(j,n){
            if(stk[i][j] > 1){
                stkleft[i][j]++;
                pq.push(mkp(stk[0][j],j));
            }
        }
    }
    rep(i,n){
        rep(j,n){
            if(stk[i][j] = 0) stkleft[i][j] = 1;
        }
    }
}

void deal(){
    while(!pq.empty()){
        ii s = pq.top(); pq.pop();
        repab(i,1,n){
            if(stkleft[i][s.second] > 0)
        }
    }
}

void process(){
    initPQ();
    deal();
}

void input(){
    n = II;
    m = II;
    rep(i,n){
        int k = II;
        stkc[i]++;
        rep(j,k){
            int l = II;
            stk[i][l-1]++;
        }
    }
}

void init(){
    rep(i,10){
        stkc[i] = 0;
        rep(j,26){
            stk[i][j] = 0;
            stkleft[i][j] = 0;
        }
    }
}

void main(){
    #define debug 0
    #if debug
    freopen("input.txt","r",stdin);
    #endif
    int t = II;
    rep(tt, t){
        input();
        process();
    }
}
