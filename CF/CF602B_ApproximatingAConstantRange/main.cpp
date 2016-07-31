#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int v[100000 + 1];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    int maxRange = 0;
    int rangeL = 0;
    int rangeR = 0;
    int minV = v[0];
    int maxV = v[0];
    int delta = 0;
    for(int i = 1; i < n; i++){
        if(v[i] != minV && v[i] != maxV){
            if(v[i] > maxV){
                minV = maxV;
                maxV = v[i];
            }else{
                maxV = minV;
                minV = v[i];
            }
            rangeL = delta;
            rangeR = i;
            maxRange = max(maxRange, rangeR - rangeL);
        }else{
            rangeR = i;
            maxRange = max(maxRange, rangeR - rangeL);
        }
        if(v[i] != v[i - 1]){
            delta = i;
        }
        //printf("%d: (%d,%d) in range [%d, %d] with delta %d\n", i, maxV, minV, rangeL, rangeR, delta);
    }
    printf("%d\n", maxRange + 1);

    return 0;

}
