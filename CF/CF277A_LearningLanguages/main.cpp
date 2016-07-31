#include <bits/stdc++.h>

using namespace std;

vector<int> pset;
int component;

void initSet(int n){
    pset.resize(n);
    for(int i = 0; i < n; i++){
        pset[i] = i;
    }
    component = n;
}

int findSet(int i){
    if(pset[i] != i){
        pset[i] = findSet(pset[i]);
    }
    return pset[i];
}

void unionSet(int i, int j){
    if(findSet(i) != findSet(j)) component--;
    pset[findSet(i)] = pset[findSet(j)];
}

int language[100][100];

int main(){
    int n, m;
    bool isallzero = true;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            language[i][j] = false;
        }
    }
    for(int i = 0; i < n; i++){
        int k;
        scanf("%d", &k);
        if(k != 0) isallzero = false;
        for(int j = 0; j < k; j++){
            int x;
            scanf("%d", &x);
            language[i][x - 1] = true;
        }
    }

    initSet(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(language[i][k] == true && language[j][k] == true){
                    unionSet(i, j);
                }
            }
        }
    }
    if(isallzero) printf("%d\n", n);
    else printf("%d", component - 1);

    return 0;
}
