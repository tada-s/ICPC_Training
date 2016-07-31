#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int t[1010];
    scanf("%d", &n);
    while(!feof(stdin)){
        for(int i = 0; i < n; i++){
            scanf("%d",&t[i]);
        }
        sort(t, t+n);
        int sum1 = 0;
        for(int i = 0; i < n; i += 2){
            int delta = abs(t[i] - t[(i+1)%n]);
            sum1 += min(24-delta, delta);
        }
        int sum2 = 0;
        for(int i = 1; i < n; i += 2){
            int delta = abs(t[i] - t[(i+1)%n]);
            sum2 += min(24-delta, delta);
        }
        printf("%d\n", min(sum1, sum2));
        scanf("%d", &n);
    }
    return 0;
}
