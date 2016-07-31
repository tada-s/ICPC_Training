#include <bits/stdc++.h>

using namespace std;

#define pb push_back

vector<int> v;
int x;

bool adjacent[5 + 1][5 + 1];
bool edge[5 + 1][5 + 1];


void dfs(int node, int depth){
    if(depth == 9){
        v.pb(x);
    }else{
        for(int i = 1; i <= 5; i++){
            if(adjacent[node][i] && !edge[node][i]){
                edge[node][i] = true;
                edge[i][node] = true;
                x = x * 10 + i;
                dfs(i, depth + 1);
                x = x / 10;
                edge[i][node] = false;
                edge[node][i] = false;
            }
        }
    }
}

int main(){
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            edge[i][j] = false;
            if(i != j){
                adjacent[i][j] = true;
            }
        }
    }
    adjacent[4][1] = false;
    adjacent[1][4] = false;
    adjacent[4][2] = false;
    adjacent[2][4] = false;

    x = 1;
    dfs(1, 1);

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        printf("%d\n", v[i]);
    }

    return 0;
}
