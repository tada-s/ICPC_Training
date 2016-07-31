#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair
#define pb push_back

vector<int> pset(200000);
    int initSet(int n){
    for(int i = 0; i < n; i++){
        pset[i] = i;
    }
}

int findSet(int i){
    return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}

int unionSet(int i, int j){
    pset[findSet(i)] = findSet(j);
}



int main(){
    //freopen("input.txt", "r", stdin);
    int m, n;
    scanf("%d %d", &m, &n);
    while(!( m == 0 && n == 0)){
        vector< pair<int, pair<int, int> > > roads;
        int total = 0;
        for(int i = 0; i < n; i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            roads.pb( mkp(w,mkp(u,v)) );
            total += w;
        }
        sort(roads.begin(), roads.end());
        initSet(m);
        int ans = 0;
        for(int i = 0; i < n; i++){
            int w = roads[i].first;
            int u = roads[i].second.first;
            int v = roads[i].second.second;
            if(findSet(u) != findSet(v)){
                unionSet(u,v);
                ans += w;
            }
        }
        roads.clear();
        printf("%d\n", total - ans);
        scanf("%d %d", &m, &n);
    }

    return 0;
}
