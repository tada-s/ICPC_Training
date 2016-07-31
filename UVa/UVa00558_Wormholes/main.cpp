#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;


int main()
{
    int c,n,m,x,y,t;
    vector<pair<int,int> > e[2010];
    scanf("%d",&c);
    for(int cc = 0; cc < c; cc++){
        scanf("%d %d",&n,&m);
        for(int i = 0; i < m; i++){
            scanf("%d %d %d",&x,&y,&t);
            e[x].push_back(make_pair(y,t));
        }
        #define INF 2000000000
        vector<int> dist(n, INF) ; dist[0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(vector<pair<int,int> >::iterator iter = e[j].begin(); iter != e[j].end(); iter++){
                    dist[iter->first] = min(dist[iter->first], dist[j] + iter->second);
                }
            }
        }
        bool negativeCycle= false;
        for(int j = 0; j < n; j++){
            for(vector<pair<int,int> >::iterator iter = e[j].begin(); iter != e[j].end(); iter++){
                if(dist[iter->first] > dist[j] + iter->second){
                    negativeCycle = true;
                    break;
                }
            }
            if(negativeCycle) break;
        }
        if(negativeCycle) printf("possible\n");
        else printf("not possible\n");


        for(int i = 0; i < n; i++) e[i].clear();
    }
    return 0;
}
