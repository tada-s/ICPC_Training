#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair
typedef pair<int, int > ii;

bool isInBound(int i, int j){
    if(!(0 <= i && i < 8)) return false;
    if(!(0 <= j && j < 8)) return false;
    return true;
}

int ix[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int iy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int sssp(int i1, int j1, int i2, int j2){
    int d = 0;

    #define NOTVISITED -1
    int visited[8][8];
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            visited[i][j] = NOTVISITED;
        }
    }

    queue<ii> q;
    q.push(mkp(i1, j1));
    visited[i1][j1] = 0;
    while(!q.empty()){
        ii p = q.front();
        q.pop();
        if(p.first == i2 && p.second == j2){
            return visited[i2][j2];
        }else{
            for(int i = 0; i < 8; i++){
                int x = ix[i] + p.first;
                int y = iy[i] + p.second;
                if(isInBound(x, y)){
                    if(visited[x][y] == NOTVISITED){
                        q.push(mkp(x, y));
                        visited[x][y] = visited[p.first][p.second] + 1;
                    }
                }
            }
        }
    }
    return d;
}

int main(){
    char s1[3];
    char s2[3];
    while(scanf("%s %s", s1, s2) != EOF){
        printf("To get from %s to %s takes %d knight moves.\n", s1, s2, sssp(s1[0] - 'a', s1[1] - '1', s2[0] - 'a', s2[1] - '1'));
    }

    return 0;
}
