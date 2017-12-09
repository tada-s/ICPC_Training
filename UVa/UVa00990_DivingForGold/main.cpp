#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair
#define pb push_back
#define UNDEF -1

int t, w;
int n;
int dp[30][1000 + 1];
int graph[30][1000 + 1][2];
vector< pair<int, int> > treasures;

int maxGold(int treasure, int time){
    if(treasure == n || time < 0){
        return 0;
    }

    if(dp[treasure][time] == UNDEF){

        int gold = 0;
        if(gold < maxGold(treasure + 1, time)){
            gold = maxGold(treasure + 1, time);
            graph[treasure][time][0] = treasure + 1;
            graph[treasure][time][1] = time;
        }
        if(time - 3 * w * treasures[treasure].first > 0){
            if(gold < maxGold(treasure + 1, time - 3 * w * treasures[treasure].first) + treasures[treasure].second){
                gold = maxGold(treasure + 1, time - 3 * w * treasures[treasure].first) + treasures[treasure].second;
                graph[treasure][time][0] = treasure + 1;
                graph[treasure][time][1] = time - 3 * w * treasures[treasure].first;
            }
        }
        dp[treasure][time] = gold;
    }
    return dp[treasure][time];
}

int printGold(){
    int c = 0;
    int time = t;
    for(int t = 0; t < n; t++){
        if(graph[t][time][1] != time){
            c++;
            time = graph[t][time][1];
        }
    }
    printf("%d\n", c);
    time = t;
    for(int t = 0; t < n; t++){
        if(graph[t][time][1] != time){
            printf("%d %d\n", treasures[t].first, treasures[t].second);
            time = graph[t][time][1];
        }
    }
}

int main(){
    int dataset = 0;
    //freopen("input.txt", "r", stdin);
    while(scanf("%d%d", &t, &w) != EOF){
        if(dataset++){
            printf("\n");
        }
        for(int i = 0; i < 30; i++){
            for(int j = 0; j < 1000 + 1; j++){
                dp[i][j] = UNDEF;
                graph[i][j][0] = UNDEF;
                graph[i][j][1] = UNDEF;
            }
        }
        treasures.clear();
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            int d, v;
            scanf("%d%d", &d, &v);
            treasures.pb(mkp(d, v));
        }
        printf("%d\n", maxGold(0, t));
        printGold();
    }
    return 0;
}
