#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    int t, r, h;
    while(scanf("%d %d %d", &t, &r, &h) == 3){

        int priceT[20], priceR[20], priceH[20];
        int tr[20][20], rh[20][20], ht[20][20];

        for(int i = 0; i < t; i++){
            scanf("%d", &priceT[i]);
            for(int j = 0; j < r; j++){
                scanf("%d", &tr[i][j]);
            }
        }
        for(int i = 0; i < r; i++){
            scanf("%d", &priceR[i]);
            for(int j = 0; j < h; j++){
                scanf("%d", &rh[i][j]);
            }
        }
        for(int i = 0; i < h; i++){
            scanf("%d", &priceH[i]);
            for(int j = 0; j < t; j++){
                scanf("%d", &ht[i][j]);
            }
        }
        int minPrice = 1 << 29;
        int minT = -1;
        int minR = -1;
        int minH = -1;

        for(int tt = 0; tt < t; tt++){
            for(int rr = 0; rr < r; rr++){
                for(int hh = 0; hh < h; hh++){
                    if(tr[tt][rr] == 0 && rh[rr][hh] == 0 && ht[hh][tt] == 0){
                        long long price = priceT[tt] + priceR[rr] + priceH[hh];
                        if(price < minPrice){
                            minPrice = price;
                            minT = tt;
                            minR = rr;
                            minH = hh;
                        }
                    }
                }
            }
        }

        if(minT == -1){
            printf("Don't get married!\n");
        }else{
            printf("%d %d %d:%d\n", minT, minR, minH, minPrice);
        }
    }
    return 0;
}
