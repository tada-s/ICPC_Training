#include <bits/stdc++.h>

using namespace std;

#define sFriends 1
#define sEnemies 2
#define aFriends 3
#define aEnemies 4

vector<int> pset;

void initSet(int n){
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
    pset[findSet(i)] = findSet(j);
}

bool isSameSet(int i, int j){
    return findSet(i) == findSet(j);
}

vector<int> enemy;

bool areEnemies(int x, int y){
    return enemy[findSet(x)] == findSet(y);
}

bool areFriends(int x, int y){
    return isSameSet(x, y);
}

void setEnemies(int i, int j){
    if(i == j || areFriends(i, j)){
        printf("-1\n");
    }else{
        if(enemy[findSet(i)] != -1){
            unionSet(j, enemy[findSet(i)]);
        }
        if(enemy[findSet(j)] != -1){
            unionSet(i, enemy[findSet(j)]);
        }
        enemy[findSet(i)] = findSet(j);
        enemy[findSet(j)] = findSet(i);
    }
}

void setFriends(int i, int j){
    if(areEnemies(i, j)){
        printf("-1\n");
    }else{
        int ei = enemy[findSet(i)];
        int ej = enemy[findSet(j)];

        unionSet(i, j);

        if(ei != -1 && ej != -1){
            unionSet(ei, ej);
        }
        if(ei != -1){
            enemy[findSet(ei)] = findSet(i);
            enemy[findSet(i)] = findSet(ei);
        }
        if(ej != -1){
            enemy[findSet(ej)] = findSet(j);
            enemy[findSet(j)] = findSet(ej);
        }
    }
}



int main(){
    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    initSet(n);
    enemy.resize(n, -1);

    int c, x, y;
    scanf("%d%d%d", &c, &x, &y);
    while(!(c == 0 && x == 0 && y == 0)){
        switch(c){
        case sFriends:
            setFriends(x, y);
            break;
        case sEnemies:
            setEnemies(x, y);
            break;
        case aFriends:
            printf("%d\n", (areFriends(x, y)) ? 1 : 0);
            break;
        case aEnemies:
            printf("%d\n", (areEnemies(x, y)) ? 1 : 0);
            break;
        }

        scanf("%d%d%d", &c, &x, &y);
    }
    return 0;
}
