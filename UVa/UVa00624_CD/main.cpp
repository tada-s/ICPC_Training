#include <bits/stdc++.h>

using namespace std;

int n, t;
int v[20];
int sum;
int maxSum;
bool selected[20];
bool bestselected[20];

void backtracking(int i){
    if(sum > maxSum && sum <= n){
        for(int j = 0; j < 20; j++){
            bestselected[j] = selected[j];
        }
        maxSum = sum;
    }

    if(i == t){
        return;
    }

    selected[i] = true;
    sum += v[i];
    backtracking(i + 1);

    sum -= v[i];
    selected[i] = false;
    backtracking(i + 1);
}

int main(){
    //freopen("input.txt", "r", stdin);
    while(scanf("%d%d", &n, &t) != EOF){
        for(int i = 0; i < t; i++){
            scanf("%d", &v[i]);
        }

        for(int i = 0; i < t; i++){
            selected[i] = false;
            bestselected[i] = false;
        }
        maxSum = 0;
        sum = 0;
        backtracking(0);
        for(int i = 0; i < t; i++){
            if(bestselected[i]){
                printf("%d ", v[i]);
            }
        }
        printf("sum:%d\n", maxSum);
    }

    return 0;
}
