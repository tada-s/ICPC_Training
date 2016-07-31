#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    int f, r;
    while(scanf("%d %d", &f, &r) == 2){
        int ft[10];
        int rt[10];

        for(int i = 0; i < f; i++){
            scanf("%d", &ft[i]);
        }

        for(int i = 0; i < r; i++){
            scanf("%d", &rt[i]);
        }

        set<double> d;

        for(int i = 0; i < f; i++){
            for(int j = 0; j < r; j++){
                d.insert(rt[j]/ (double) ft[i]);
            }
        }

        double maxD = 0;

        double first = *d.begin();
        double second;
        __typeof(d.begin()) iter = d.begin();
        iter++;
        for(; iter != d.end(); iter++){
            second = first;
            first = *iter;
            maxD = max(maxD, first / second);
        }

        printf("%.02f\n", maxD);
    }
    return 0;
}
