#include <bits/stdc++.h>

using namespace std;

vector<int> setSize;
vector<int> pset;

void initSet(int n){
    pset.resize(n);
    setSize.resize(n);
    for(int i = 0; i < n; i++){
        pset[i] = i;
        setSize[i] = 1;
    }
}

int findSet(int i){
    if(pset[i] != i){
        pset[i] = findSet(pset[i]);
    }
    return pset[i];
}

void unionSet(int i, int j){
    int pi = findSet(i);
    int pj = findSet(j);
    if(pi != pj){
        setSize[pj] += setSize[pi];
        pset[pi] = pj;
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for(int tt = 0; tt < t; tt++){
        int n, m;
        scanf("%d %d", &n, &m);
        initSet(n + 1);
        for(int i = 0; i < m; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            unionSet(a, b);
        }

        int s = 0;
        for(int i = 0 ; i < setSize.size(); i++){
            s = max(s, setSize[i]);
        }

        printf("%d\n", s);
    }
    return 0;
}
