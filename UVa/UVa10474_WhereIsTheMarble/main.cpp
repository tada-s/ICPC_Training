#include <bits/stdc++.h>

using namespace std;

#define pb push_back
typedef vector<int> vi;

int main(){
    //freopen("input.txt", "r", stdin);
    int n, q;
    int c = 0;
    vi v;
    scanf("%d %d", &n, &q);
    while(!(n == 0 && q == 0)){
        for(int i = 0; i < n; i++){
            int x;
            scanf("%d", &x);
            v.pb(x);
        }
        sort(v.begin(), v.end());
        printf("CASE# %d:\n", ++c);
        for(int i = 0; i < q; i++){
            int x;
            scanf("%d", &x);
            typeof(v.begin()) iter = lower_bound(v.begin(), v.end(), x);
            if(iter == v.end()){
                printf("%d not found\n", x);
            }else if(*iter != x){
                printf("%d not found\n", x);
            }else{
                printf("%d found at %d\n", x, (iter-v.begin()) + 1);
            }
        }
        v.clear();
        scanf("%d %d", &n, &q);
    }
    return 0;
}
