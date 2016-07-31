#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> pset(10010);
void initSet(int _size){ for(int i = 0 ; i < _size; i++) pset[i] = i; }
int findSet(int i){ return (pset[i]==i) ?  i : (pset[i] = findSet(pset[i])); }
void unionSet(int i, int j) { pset[findSet(i)]=findSet(j); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

struct road{
    int x,y,c;
};

bool cmp_road(road r1, road r2){
    return r1.c < r2.c;
}

int main()
{
    int t,n,m,a,e,cost;
    road r;
    vector<road> roads;
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    for(int tt = 0; tt < t; tt++){
        scanf("%d %d %d",&n,&m,&a);
        for(int i = 0; i < m; i++){
            scanf("%d %d %d",&r.x,&r.y,&r.c);
            if(r.c < a && r.x != r.y) roads.push_back(r);

        }
        sort(roads.begin(), roads.end(), cmp_road);
        e=0;
        cost = 0;
        initSet(n+2);
        for(int i = 0; i < roads.size(); i++){
            r = roads[i];
            if(!isSameSet(r.x, r.y)){
                unionSet(r.x,r.y);
                cost += r.c;
                e++;
            }
        }
        cost += a * (n - e);
        printf("Case #%d: %d %d\n", tt+1, cost, n - e);
        roads.clear();
    }

    return 0;
}
