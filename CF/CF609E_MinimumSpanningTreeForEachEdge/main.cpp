#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair
#define pb push_back

vector<int> pset;

void initSet(int n){
    pset.resize(n);
    for(int i = 0; i < n; i++){
        pset[i] = i;
    }
}

void findSet(int i){
    if(pset[i] != i){
        pset[i] = findSet(pset[i]);
    }
    return pset[i];
}

void unionSet(int i, int j){
    pset[findSet(i)] = findSet(j);
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector< pair< int, pair<int, int> > > v;
    for(int i = 0; i < m; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        v.pb(mkp(w, mkp(u, v)));
    }
    sort(v.begin(), v.end());

    vector< pair< int, pair<int, int> > > spanningTree;
    vector< pair< int, pair<int, int> > > otherComponent;
    long long totalW = 0;
    for(int i = 0; i < n; i++){
        if(findSet(v[i].second.first) != findSet(v[i].second.second)){
            spanningTree.pb(v[i]);
            totalW += v[i].first;
        }else{

        }
    }


}
