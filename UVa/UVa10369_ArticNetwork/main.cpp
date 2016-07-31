#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mkp make_pair

vector< pair<int, int> > v;
vector<int> v2;

int distsq(pair<int, int> p1, pair<int, int> p2){
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

int setComponent;
vector<int> pset;
void initSet(int n){
    setComponent = n;
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
        setComponent--;
        pset[i1] = j1;
    }
}

int component(int d){
    initSet(v.size());
    for(int i = 0; i < v.size(); i++){
        for(int j = i + 1; j < v.size(); j++){
            if(distsq(v[i], v[j]) <= d){
                unionSet(i, j);
            }
        }
    }
    return setComponent;
}

bool cmp(int i, int val){
    return component(i) > val;
}

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int nn = 0; nn < n; nn++){
        v.clear();
        v2.clear();

        int s, p;
        scanf("%d%d", &s, &p);
        for(int i = 0; i < p; i++){
            int x, y;
            scanf("%d%d", &x, &y);
            v.pb(mkp(x, y));
        }

        set<int> ss;
        for(int i = 0; i < v.size(); i++){
            for(int j = i + 1; j < v.size(); j++){
                ss.insert(distsq(v[i], v[j]));
            }
        }

        v2.resize(ss.size());
        copy(ss.begin(), ss.end(), v2.begin());

        int l = lower_bound(v2.begin(), v2.end(), s, cmp) - v2.begin();

        printf("%.2lf\n",sqrt(v2[l]));
    }
    return 0;
}
