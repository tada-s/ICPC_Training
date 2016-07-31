#include <bits/stdc++.h>

using namespace std;

int component;
vector<int> pset;
void initSet(int n){
    component = n;
    pset.resize(n);
    for(int i = 0; i < n; i++){
        pset[i] = i;
    }
}

int findSet(int i){
    if(pset[i] != i){
        pset[i] = findSet(pset[i]);
    }
    return pset[i];
}

void unionSet(int i, int j){
    int i1 = findSet(i);
    int j1 = findSet(j);
    if(i1 != j1){
        component--;
        pset[i1] = j1;
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    int caseN = 1;
    while(!(n == 0 && m == 0)){
        initSet(n + 1);
        for(int i = 0; i < m; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            unionSet(a, b);
        }
        printf("Case %d: %d\n", caseN++, component - 1);
        scanf("%d%d", &n, &m);
    }
    return 0;
}
