#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    #define INF 20000000
    int t,l,d,u,v,c;
    int edge[110][110];
#define debug 0
#if debug
    FILE* fp = fopen("output.txt","w");
    freopen("input.txt","r",stdin);
#endif
    scanf("%d",&t);
    for(int tt=0; tt < t; tt++){
        scanf("%d %d",&l,&d);
        for(int i = 0; i < l; i++){
            for(int j = 0; j < l; j++){
                edge[i][j] = INF;
            }
        }
        for(int i = 0; i < l; i++){
            edge[i][i] = 0;
        }
        for(int i = 0; i < d; i++){
            scanf("%d %d %d",&u,&v,&c);
            edge[u-1][v-1] = min(c,edge[u-1][v-1]);
            edge[v-1][u-1] = edge[u-1][v-1];
        }
        for(int k = 0; k < l; k++){
            for(int i = 0; i < l; i++){
                for(int j = 0; j < l; j++){
                    edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
                }
            }
        }
        bool equidistant;
        int minMaxD = INF;
        int eqD = -1;
        for(int i = 0; i < l; i++){
            equidistant = true;
            for(int j = 1; j < 5; j++){
                if(edge[i][j] != edge[i][j-1]){
                    equidistant = false;
                    break;
                }
            }
            if(equidistant){
                if(edge[i][0] == INF){
                    eqD = -1;
                    break;
                }
                int maxD = 0;
                for(int j = 0; j < l; j++){
                    if(edge[i][j] > maxD){
                        maxD = edge[i][j];
                    }
                }
                if(maxD < minMaxD){
                    eqD = edge[i][0];
                    minMaxD = maxD;
                }
            }
        }
#if debug
        for(int i = 0; i < l; i++){
            for(int j = 0; j < l; j++){
                fprintf(fp,"%d, ",edge[i][j]);
            }
            fputc('\n',fp);
        }
#endif
        if(minMaxD == INF) printf("Map %d: -1\n",tt+1);
        else printf("Map %d: %d\n",tt+1,eqD);
    }
#if debug
    fclose(fp);
#endif
    return 0;
}
