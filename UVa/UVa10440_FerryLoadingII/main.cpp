#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);

    int c;
    scanf("%d", &c);
    while(c--){
        int n, t, m;
        scanf("%d%d%d", &n, &t, &m);
        int arrive[1440 * 2] = {0};
        int bestTime[1440 * 2] = {0};
        int trip[1440 * 2] = {0};
        for(int i = 0; i < m; i++){
            scanf("%d", &arrive[i + n]);
        }

        for(int i = n; i < n + m; i++){
            int minTime = 1<<29;
            int minTrip = 100000;
            for(int j = i - n; j < i; j++){
                //printf("%d %d %d %d\n", bestTime[j], minTime, trip[j], minTrip);
                if(bestTime[j] <= minTime && trip[j] < minTrip){
                    minTime = bestTime[j];
                    minTrip = trip[j];
                }
            }
            bestTime[i] = max(arrive[i], minTime) + 2 * t;
            trip[i] = minTrip + 1;
            //printf("%d %d!\n", bestTime[i], trip[i]);
        }

        //printf("stm = %d %d %d\m", n, t, m);
        printf("%d %d\n", bestTime[n + m - 1] - t, trip[n + m - 1]);

    }
    return 0;
}
