#include <bits/stdc++.h>

using namespace std;

#define UNDEF (-1)
#define pb push_back

int n;
int v1[4000];
int v2[4000];


int lis(){
    vector<int> headerIndex;
    vector<int> parentIndex;

    headerIndex.pb(0);
    parentIndex.pb(-1);
    for(int i = 1; i < 2 * n; i++){
        int key = v1[i];
        int lb = 0;
        int ub = headerIndex.size() - 1;
        while(lb <= ub){
            int mid = (ub + lb) / 2;
            if(v1[headerIndex[mid]] < key){
                lb = mid + 1;
            }else{
                ub = mid - 1;
            }
        }
        if(ub + 1 == headerIndex.size()){
            headerIndex.pb(i);
        }else{
            if(v1[i] < v1[headerIndex[ub + 1]]){
                headerIndex[ub + 1] = i;
            }
        }
        if(ub == -1){
            parentIndex.pb(-1);
        }else{
            parentIndex.pb(headerIndex[ub]);
        }
    }

    return headerIndex.size();

}

int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for(int tt = 0; tt < t; tt++){
        scanf("%d", &n);

        for(int i = 0; i < n; i++){
            scanf("%d", &v1[n + i]);
            v1[n - i - 1] = v1[n + i];
        }

        if(n == 0){
            printf("%d\n", 0);
        }else{
            printf("%d\n", lis());
        }
    }
    return 0;
}
