#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int maxEnjoy = 0;
        for(int i = 0; i < 100; i++){
            int drinked = 0;
            int emptyBottle = i;
            int fullBottle = n;
            while(emptyBottle + fullBottle > 2 && emptyBottle + fullBottle > i){
                drinked += fullBottle;
                int newBottle = (emptyBottle + fullBottle) / 3;
                int remainBottle = (emptyBottle + fullBottle) % 3;
                fullBottle = newBottle;
                emptyBottle = remainBottle;
            }
            if(emptyBottle + fullBottle == i){
                drinked += fullBottle;
            }
            maxEnjoy = max(maxEnjoy, drinked);
        }

        printf("%d\n", maxEnjoy);
    }
    return 0;
}
