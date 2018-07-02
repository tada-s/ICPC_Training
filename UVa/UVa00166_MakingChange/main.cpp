#include <bits/stdc++.h>
#define INF (1<<29)
using namespace std;

int coin[6];
int coinValue[6] = {1, 2, 4, 10, 20, 40};

int minCoin(int x){
    int auxCoin[6];
    for(int i = 0; i < 6; i++){
        auxCoin[i] = coin[i];
    }

    int coins = 0;
    int pointer = 5;
    while(x > 0){
        if(pointer < 0){
            return INF;
        }else if(auxCoin[pointer] == 0){
            pointer--;
        }else if(x - coinValue[pointer] < 0){
            pointer--;
        }else{
            x = x - coinValue[pointer];
            auxCoin[pointer]--;
            coins++;
        }
    }
    return coins;
}

int minCoinShop(int x){
    int coins = 0;
    int pointer = 5;
    while(x > 0){
        if(pointer < 0){
            return INF;
        }else if(x - coinValue[pointer] < 0){
            pointer--;
        }else{
            x = x - coinValue[pointer];
            coins++;
        }
    }
    return coins;
}

int main(){
    //freopen("input.txt", "r", stdin);
    while(true){
        int sum = 0;
        for(int i = 0; i < 6; i++){
            scanf("%d", &coin[i]);
            sum += coin[i];
        }
        if(sum == 0) break;

        int a,b;
        scanf("%d.%d", &a, &b);
        int transaction = (a * 100 + b) / 5;

        int minTotalCoin = INF;
        for(int x = transaction; x <= 600 / 5; x++){
            int y = x - transaction;

            int coin1 = minCoin(x);
            int coin2 = minCoinShop(y);

            minTotalCoin = min(minTotalCoin, coin1 + coin2);
        }

        printf("%3d\n", minTotalCoin);

    }

    return 0;
}
