#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair

vector<int> pset;

int initSet(int n){
    pset.resize(n);
    for(int i = 0; i < n; i++){
        pset[i] = i;
    }
}

int findSet(int i){
    return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}

void unionSet(int i, int j){
    pset[findSet(i)] = findSet(j);
}

int main(){
    //freopen("input.txt", "r", stdin);

    bool firstTime = true;
    int n;
    while(scanf("%d", &n) != EOF){
        if(!firstTime){
            printf("\n");
        }

        int sum = 0;
        for(int i = 0; i < n - 1; i++){
            int a, b, x;
            scanf("%d%d%d", &a, &b, &x);
            sum += x;
        }

        printf("%d\n", sum);

        priority_queue< pair< int, pair<int, int> > > q;
        int k;
        scanf("%d", &k);
        for(int i = 0; i < k; i++){
            int a, b, x;
            scanf("%d%d%d", &a, &b, &x);
            q.push(mkp(-x, mkp(a, b)));
        }

        int m;
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            int a, b, x;
            scanf("%d%d%d", &a, &b, &x);
            q.push(mkp(-x, mkp(a, b)));
        }

        initSet(n + 1);

        int total = 0;
        int e = 0;
        while(e != n - 1 && !q.empty()){
            pair< int, pair<int, int> > edge = q.top();
            q.pop();
            if(findSet(edge.second.first) != findSet(edge.second.second)){
                unionSet(edge.second.first, edge.second.second);
                e++;
                total += -edge.first;
            }
        }

        printf("%d\n", total);

        firstTime = false;
    }
    return 0;
}
