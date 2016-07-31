#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair
#define pb push_back

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

int main(){
    //freopen("input.txt", "r", stdin);

    int n;
    scanf("%d", &n);
    while(n != -1){
        if(n != 0){
            initSet(n);

            vector< pair< pair<float, float>, float> > v;

            for(int i = 0; i < n; i++){
                float x, y, r;
                scanf("%f %f %f", &x, &y, &r);
                for(int j = 0; j < v.size(); j++){
                    float d = sqrt( (v[j].first.first - x) * (v[j].first.first - x) + (v[j].first.second - y) * (v[j].first.second - y) );
                    if(((r + v[j].second > d && abs(r - v[j].second) < d)) || (r == v[j].second && d == 0)){
                        unionSet(i, j);
                    }
                }
                v.pb(mkp(mkp(x, y), r));
            }
            for(int i = 0; i < pset.size(); i++){
                findSet(i);
            }

            sort(pset.begin(), pset.end());

            int maxC = 0;
            int c = 0;
            for(int i = 0; i < pset.size() - 1; i++){
                if(pset[i] == pset[i + 1]){
                    c++;
                }else{
                    maxC = max(maxC, c);
                    c = 0;
                }
            }
            maxC = max(maxC, c);
            maxC++;

            printf("The largest component contains %d %s.\n", maxC, (maxC == 1) ? "ring" : "rings");
        }else{
            printf("The largest component contains 0 rings.\n");
        }
        scanf("%d", &n);
    }
    return 0;
}
