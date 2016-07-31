#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
#define pb push_back

#define n ('Z' - 'A' + 1)
int m[n][n];
bool visited[n];
vi ts;

void init(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            m[i][j] = 0;
        }
        visited[i] = false;
    }
}

void toposort(int node){
    visited[node] = true;
    for(int i = 0; i < n; i++){
        if(m[node][i] == 1 && !visited[i]){
            toposort(i);
        }
    }
    ts.pb(node);
}

void update(string& str1, string& str2){
    int l = min(str1.size(), str2.size());
    for(int i = 0; i < l; i++){
        if(str1[i] != str2[i]){
            int c1 = str1[i] - 'A';
            int c2 = str2[i] - 'A';
            m[c1][c2] = 1;
            break;
        }
    }
}

int findroot(){
    for(int i = 0; i < n; i++){
    bool isRoot = false;
    for(int j = 0; j < n; j++){
        if(m[i][j] == 1){
            isRoot = true;
            break;
        }
        }
        for(int j = 0; j < n; j++){
            if(m[j][i] == 1){
                isRoot = false;
                break;
            }
        }
        if(isRoot) return i;
    }
    return 0;
}

int main(){
    //freopen("input.txt", "r", stdin);
    vector<string> v;
    char str[20+1];
    init();
    scanf("%s", str);
    while(str[0] != '#'){
        v.pb(str);
        scanf("%s", str);
    }
    for(int i = 0; i < v.size()-1; i++){
        update(v[i], v[i+1]);
    }
    toposort(findroot());
    for(int i = ts.size()-1; i >= 0; i--){
        printf("%c", ts[i]+'A');
    }
    printf("\n");
    return 0;
}
