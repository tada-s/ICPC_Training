#include <bits/stdc++.h>

using namespace std;

map<pair<int,int>, int> m;
///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
vector< pair<int, int> > v;
vector<int> roots;
/*    for(typeof(m.begin) iter = m.begin(); iter != m.end(); iter++){
        v.pb(iter->first);
    }-*/

bool cmp1(pair<int, int> p1, pair<int, int> p2){
    if(p1.second < p2.second) return true;
    else if(p1.second == p2.second){
        if(p1.first > p2.first){
            return true;
        }
    }
}

int q(int x, int y){

}

void solve(){
    for(int i = 0; i < roots.size(); i++){
        int j = roots[i];
        int query = q(v[j].first, v[j].second);
        if(query != EMPTY){
            printf("%d\n", query);
            return;
        }
    }
    printf("*\n");
}

void generate(){
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size() - 1; i++){
        if(v[i].first == v[i + 1].fisrt){
            G[i].pb(i + 1);
            G[i + 1].pb(i);
            unionSet(i, i + 1);
        }
    }
    sort(v.begin(), v.end(), cmp1);
    for(int i = 0; i < v.size() - 1; i++){
        if(v[i].second == v[i + 1].second){
            G[i].pb(i + 1);
            G[i + 1].pb(i);
            se(i, i + 1);
        }
    }

    bitset<MAXM> b;
    b.reset();
    for(int i = 0; i < v.size(); i++){
        stack s;
        if(!b.test(i)){
            roots.pb(i);
            s.push(i);
            while(!s.empty()){
                int node = s.pop();
                if(!b.test(node)){
                    b.set(node);
                    for(int j = 0; j < G[node].size(); j++){
                        s.push(g[node][j]);
                    }
                }
            }
        }
    }
}

void reset(){
    m.clear();
}

int main(){
    int m, q;
    scanf("%d %d", &m, &q);
    while(!(m == 0 && q == 0)){
        for(int i = 0; i < m; i++){
            int x, y, a;
            scanf("%d %d %d", &x, &y, &a);
            //v.pb(mkp(mkp(x,y),a));
            m[mkp(x,y)] = a;
        }

        generate();

        //querys
        for(int i = 0; i < q; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            solve(x, y);
        }
        printf("-\n");

        reset();

        scanf("%d %d", &m, &q);
    }
    return 0;
}
