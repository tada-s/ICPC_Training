#include <bits/stdc++.h>

using namespace std;

int n, k;
int flightCost[10][10][30];
int flightCostSize[10][10];
int dp[10][1000];

#define pb push_back
#define UNDEF -1
#define INF (1<<29)

int bestFlight(int city, int day){
    if(day == k){
        if(city == n - 1){
            return 0;
        }else{
            return INF;
        }
    }

    if(dp[city][day] == UNDEF){
        int bestCost = INF;
        for(int i = 0; i < n; i++){
            if(i != city){
                if(flightCostSize[city][i] != 0){
                    int cost = flightCost[city][i][ day % flightCostSize[city][i] ];
                    if(cost != 0){
                        bestCost = min(bestCost, bestFlight(i, day + 1) + cost);
                    }
                }
            }
        }
        dp[city][day] = bestCost;
    }
    return dp[city][day];
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int scenario = 1;
    scanf("%d%d", &n, &k);
    while(!(n == 0 && k == 0)){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < k; j++){
                dp[i][j] = UNDEF;
            }
            for(int j = 0; j < n; j++){
                flightCostSize[i][j] = 0;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){

                }else{
                    int d;
                    scanf("%d", &d);
                    flightCostSize[i][j] = d;
                    for(int k = 0; k < d; k++){
                        int cost;
                        scanf("%d", &cost);
                        //printf("%d,%d,%d\n",i, j, k);
                        flightCost[i][j][k] = cost;
                    }
                }
            }
        }

        printf("Scenario #%d\n", scenario++);
        if(bestFlight(0, 0) == INF){
            printf("No flight possible.\n");
        }else{
            printf("The best flight costs %d.\n", bestFlight(0, 0));
        }
        printf("\n");
        scanf("%d%d", &n, &k);
    }

    return 0;
}
