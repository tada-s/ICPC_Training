#include <bits/stdc++.h>

using namespace std;

bool isValid(int a, int b){
    int digit[10];
    for(int i = 0; i < 10; i++){
        digit[i] = 0;
    }
    for(int i = 0; i < 5; i++){
        digit[a % 10]++;
        a /= 10;
    }
    for(int i = 0; i < 5; i++){
        digit[b % 10]++;
        b /= 10;
    }
    for(int i = 0; i < 10; i++){
        if(digit[i] != 1){
            return false;
        }
    }
    return true;
}

int main(){
    //freopen("input.txt", "r", stdin);
    bool firstTime = true;
    int n;
    scanf("%d", &n);
    while(n != 0){
        if(firstTime){
            firstTime = false;
        }else{
            printf("\n");
        }
        bool existSolution = false;
        for(int x = 1234; x * n < 100000; x++){
            if(isValid(x, x * n)){
                existSolution = true;
                printf("%05d / %05d = %d\n", x * n, x, n);
            }
        }

        if(!existSolution){
            printf("There are no solutions for %d.\n", n);
        }

        scanf("%d", &n);
    }
    return 0;
}
