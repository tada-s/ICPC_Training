#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mkp make_pair

vector< pair<double, pair<int, int> > > e;
vector< pair<double, double> > p;

vector<int> pset;

double dist(int i, int j){
    return sqrt((p[i].first - p[j].first) * (p[i].first - p[j].first) + (p[i].second - p[j].second) * (p[i].second - p[j].second));
}

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
    pset[findSet(i)] = pset[findSet(j)];
}

int main(){
    bool firstPrint = true;
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for(int tt = 0; tt < t; tt++){
        p.clear();
        e.clear();
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            float x, y;
            scanf("%f %f", &x, &y);
            p.pb(mkp(x, y));
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                e.pb(mkp(dist(i, j), mkp(i, j)));
            }
        }

        double totalPeso = 0;
        initSet(n);
        sort(e.begin(), e.end());
        for(int i = 0; i < e.size(); i++){
            int u = e[i].second.first;
            int v = e[i].second.second;
            double w = e[i].first;
            if(findSet(u) != findSet(v)){
                unionSet(u, v);
                totalPeso += w;
            }
        }
        if(!firstPrint) printf("\n");
        printf("%.2f\n", totalPeso);
        firstPrint = false;
    }

    return 0;
}
