#include <bits/stdc++.h>

using namespace std;

int bubblesort(int v[], int l){
    int c = 0;
    bool flag = true;
    while(flag){
        flag = false;
        for(int i = 0; i < l - 1; i++){
            if(v[i] > v[i + 1]){
                swap(v[i], v[i + 1]);
                c++;
                flag = true;
            }
        }
    }
    return c;
}

int main(){
    int n;
    int v[50 + 1];
    scanf("%d", &n);
    for(int nn = 0; nn < n; nn++){
        int l;
        scanf("%d", &l);
        for(int i = 0; i < l; i++){
            int x;
            scanf("%d", &x);
            v[i] = x;
        }

        printf("Optimal train swapping takes %d swaps.\n", bubblesort(v, l));
    }


    return 0;
}
