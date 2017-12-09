#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int setNumber = 1;

    int c, s;
    while(scanf("%d%d", &c, &s) != EOF){
        int v[10] = {0};
        for(int i = 0; i < s; i++){
            scanf("%d", &v[i]);
        }

        sort(v, v + s);


        int sum = 0;
        vector<int> chamber[5];
        int chamberSum[5] = {0};

        if(s < c){
            for(int i = 0; i < s; i++){
                chamberSum[i] += v[i];
                chamber[i].push_back(v[i]);
                sum += v[i];
            }
        }else{
            for(int i = s - 1; i >= (s - c); i--){
                chamberSum[i - ((s - c))] += v[i];
                chamber[i - ((s - c))].push_back(v[i]);
                sum += v[i];
            }
            for(int i = (s - c) - 1; i >= 0; i--){
                chamberSum[((s - c) - 1) - i] += v[i];
                chamber[((s - c) - 1) - i].push_back(v[i]);
                sum += v[i];
            }
        }
        double average = sum / (1.0 * c);

        double imbalance = 0;
        for(int i = 0; i < c; i++){
            imbalance += abs((double)chamberSum[i] - average);
        }

        printf("Set #%d\n", setNumber++);
        for(int i = 0; i < c; i++){
            printf(" %d:", i);
            for(int j = 0; j < chamber[i].size(); j++){
                printf(" %d", chamber[i][j]);
            }
            printf("\n");
        }
        printf("IMBALANCE = %.5lf\n", imbalance);
        printf("\n");

        /*for(int i = 0; i < 5; i++){
            chamber[i].clear();
        }*/
    }

    return 0;
}
