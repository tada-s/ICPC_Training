#include <bits/stdc++.h>

using namespace std;

int n, t;
int v[20];
int vMax[20];

int getMaxSum(int current, int remain, int rDepth){
    if(current == t){
        return 0;
    }else{
        int maxSum = 0;
        for(int i = current; i < t; i++){
            if(v[i] <= remain){
                int sum = v[i] + getMaxSum(i + 1, remain - v[i], rDepth + 1);
                if(sum > maxSum){
                    maxSum = sum;
                }
            }
        }
        return maxSum;
    }
}

int main(){
    char str[100];


    while(scanf("%d %d", &n, &t) != EOF){
        for(int i = 0; i < t; i++){
            scanf("%d", &v[i]);
        }

        int maxSum = getMaxSum(0, n, 0);
        int sum = 0;
        for(int i = 0; sum != maxSum; i++){
            printf("%d ", vMax[i]);
            sum += vMax[i];
        }
        printf("sum:%d\n", maxSum);
    }
}
