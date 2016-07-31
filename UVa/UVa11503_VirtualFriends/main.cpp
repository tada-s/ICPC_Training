#include <bits/stdc++.h>

using namespace std;

vector<int> pset;
vector<int> sset;

void initSet(int n){
    pset.resize(n);
    sset.resize(n);
    for(int i = 0; i < n; i++){
        pset[i] = i;
        sset[i] = 1;
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
        sset[pi] += sset[pj];
        pset[pj] = pi;
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for(int tt = 0; tt < t; tt++){
        int number = 0;
        map<string, int> map1;
        int f;
        scanf("%d", &f);
        initSet(2 * f);
        for(int i = 0; i < f; i++){
            char str1[20 + 1], str2[20 + 1];
            scanf("%s%s", str1, str2);
            if(map1.find(str1) == map1.end()){
                map1[str1] = number++;
            }
            if(map1.find(str2) == map1.end()){
                map1[str2] = number++;
            }
            unionSet(map1[str1], map1[str2]);
            printf("%d\n", sset[findSet(map1[str2])]);
        }

    }
    return 0;
}
