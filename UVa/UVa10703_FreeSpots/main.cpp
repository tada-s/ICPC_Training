#include <bits/stdc++.h>

using namespace std;

int main(){
    int empty[500 + 1][500 + 1];
    int w, h, n;
    scanf("%d %d %d", &w, &h, &n);
    while(!(w == 0 && h == 0 && n == 0)){

        for(int i = 1; i <= w; i++){
            for(int j = 1; j <= h; j++){
                empty[i][j] = true;
            }
        }

        for(int i = 0; i < n; i++){
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            if(x1 > x2) swap(x1, x2);
            if(y1 > y2) swap(y1, y2);

            for(int i = x1; i <= x2; i++){
                for(int j = y1; j <= y2; j++){
                    empty[i][j] = false;
                }
            }
        }

        int e = 0;
        for(int i = 1; i <= w; i++){
            for(int j = 1; j <= h; j++){
                if(empty[i][j]){
                    e++;
                }
            }
        }

        if(e == 0){
            printf("There is no empty spots.\n");
        }else if(e == 1){
            printf("There is one empty spot.\n");
        }else{
            printf("There are %d empty spots.\n", e);
        }

        scanf("%d %d %d", &w, &h, &n);
    }
    return 0;
}
