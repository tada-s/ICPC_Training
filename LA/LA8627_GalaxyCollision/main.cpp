#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair
#define pb push_back
#define repSTL(c, iter) for(typeof(c.begin()) iter = c.begin(); iter != c.end(); iter++)
#define INF 1<<29

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define maxPoint (50000)
vii v;
vi al[maxPoint];
bool visited[maxPoint];

ii bipartite(int n){
    ii p;
    p.first = 1;
    p.second = 0;
    visited[n] = true;
    for(int i = 0; i < al[n].size(); i++){
        int u = al[n][i];
        if(!visited[u]){
            ii auxP = bipartite(u);
            p.first += auxP.second;
            p.second += auxP.first;
        }
    }
    return p;
}

long long distsqr(ii p1, ii p2){
    return (p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second);
}

void generateGraph(vi& v1, vi& v2){
    for(int i = 0; i < v1.size(); i++){
        for(int j = 0; j < v2.size(); j++){
            int p1 = v1[i];
            int p2 = v2[j];
            if(distsqr(v[p1], v[p2]) <= 25 && p1 != p2){
                al[p1].pb(p2);
                al[p2].pb(p1);
//printf("conect: %c %c %d\n", p1 + 'A', p2 + 'A', distsqr(v[p1], v[p2]));
            }
        }
    }
}

void maketestcase(){
    srand(10);
    int s1 = 10;
    int s2 = 10;
    FILE* fp = fopen("input.txt", "w");
    fprintf(fp, "%d\n", s1+s2);
    vii vs1, vs2;

    int sqh = 20;
    int sqv = 20;

    while(vs1.size() < s1){
        int x = rand()%sqh+1;
        int y = rand()%sqv+1;
        bool goodSeparation = true;
        for(int i = 0; i < vs1.size(); i++){
            if(distsqr(vs1[i],mkp(x,y)) <= 25){
                goodSeparation = false;
            }
        }
        if(goodSeparation){
            vs1.pb(mkp(x,y));
        }
    }
    while(vs2.size() < s2){
        int x = rand()%sqh+1;
        int y = rand()%sqv+1;
        bool goodSeparation = true;
        for(int i = 0; i < vs2.size(); i++){
            if(distsqr(vs2[i],mkp(x,y)) <= 25){
                goodSeparation = false;
            }
        }
        if(goodSeparation){
            vs2.pb(mkp(x,y));
        }
    }
    for(int i = 0; i < vs1.size(); i++){
        fprintf(fp, "%d %d\n", vs1[i].first, vs1[i].second);
    }
    for(int i = 0; i < vs2.size(); i++){
        fprintf(fp, "%d %d\n", vs2[i].first, vs2[i].second);
    }
    fclose(fp);
}

int main(){
    //maketestcase();
    //freopen("input.txt", "r", stdin);
    int n;
    while(scanf("%d", &n) != EOF){
        v.clear();
        for(int i = 0; i < n; i++){
            al[i].clear();
            visited[i] = false;
        }
        for(int i = 0; i < n; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            v.pb(mkp(x,y));
        }

        map<ii, vi> m;
        for(int i = 0; i < n; i++){
            int x = v[i].first;
            int y = v[i].second;
            m[mkp(x/5, y/5)].pb(i);
        }
        int ix[5] = {0, 1, 1, 1, 0};
        int iy[5] = {1, 1, 0, -1, -1};
        repSTL(m, iter){
            generateGraph(iter->second,iter->second);
            ii p = iter->first;
            for(int i = 0; i < 5; i++){
                int x = p.first + ix[i];
                int y = p.second + iy[i];
                typeof(m.begin()) iter2 = m.find(mkp(x,y));
                if(iter2 != m.end()){
                    generateGraph(iter->second, iter2->second);
                }
            }
        }
        m.clear();

        int minS = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                ii p = bipartite(i);
                minS += min(p.first, p.second);
            }
        }
        printf("%d\n", minS);
    }
    return 0;
}
