#include <bits/stdc++.h>

/*
START TAG
Graph
Strongly Connected Component
Directed Acyclic Graph
END TAG
*/

using namespace std;

#define pb push_back
#define UNDEF (-1)

vector<int> g[5000];

int component[5000];
int num[5000];
int low[5000];
bool inStack[5000];
stack<int> currentStack;

int visitNumber = 0;
int componentNumber = 0;

void tarjan(int u){
    num[u] = visitNumber;
    low[u] = visitNumber;
    inStack[u] = true;
    currentStack.push(u);
    visitNumber++;

    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];

        if(num[v] == UNDEF){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }else if(inStack[v]){
            low[u] = min(low[u], num[v]);
        }
    }

    if(num[u] == low[u]){
        int v;
        do{v = currentStack.top(); currentStack.pop();
            inStack[v] = false;
            component[v] = componentNumber;
        }while(v != u);

        componentNumber++;
    }
}

int main(){
    //freopen("input.txt", "r", stdin);

    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);
    s--;
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].pb(b);
    }

    for(int i = 0; i < n; i++){
        num[i] = UNDEF;
        inStack[i] = false;
    }
    visitNumber = 0;
    componentNumber = 0;

    for(int i = 0; i < n; i++){
        if(num[i] == UNDEF){
            tarjan(i);
        }
    }

    //printf("components: %d\n", componentNumber);

    int sources = 0;
    map<int, int> inDegree;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < g[i].size(); j++){
            int v = g[i][j];

            if(component[i] != component[v]){
                inDegree[component[v]]++;
            }
        }
    }
    for(int i = 0; i < componentNumber; i++){
        if(inDegree[i] == 0 && i != component[s]){
            sources++;
        }
    }

    printf("%d\n", sources);

    return 0;
}
