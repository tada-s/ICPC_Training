#include <bits/stdc++.h>

using namespace std;

int n;
int v[17];
bool isUsed[17];
bool isPrime[16 + 15 + 1];

void fillVector(int i){
    if(i == n - 1 && isPrime[v[i] + v[0]]){
        printf("%d", v[0]);
        for(int i = 1; i < n; i++){
            printf(" %d", v[i]);
        }
        printf("\n");
        return;
    }

    for(int number = 2; number <= n; number++){
        if(!isUsed[number]){
            if(isPrime[v[i] + number]){
                isUsed[number] = true;
                v[i + 1] = number;
                fillVector(i + 1);
                isUsed[number] = false;
            }
        }
    }
}

void initIsPrime(){
    for(int i = 2; i <= 16 + 15; i++){
        bool flag = true;
        for(int j = 2; j < i; j++){
            if(i % j == 0){
                flag = false;
                break;
            }
        }
        isPrime[i] = flag;
    }
}

int main(){
    initIsPrime();

    int c = 1;
    while(scanf("%d", &n) != EOF){
        if(c != 1){
            printf("\n");
        }
        printf("Case %d:\n", c++);
        set<int> s;
        for(int i = 1; i <= n; i++){
            isUsed[i] = false;
        }

        isUsed[1] = true;
        v[0] = 1;
        fillVector(0);
    }
    return 0;
}
