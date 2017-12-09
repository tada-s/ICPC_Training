#include <stdio.h>

using namespace std;

int v[100000 + 3];

int main(){
    //freopen("input.txt", "r", stdin);

    int y;
    while(scanf("%d", &y) != EOF){
        int p;
        scanf("%d", &p);

        v[0] = -1;
        for(int i = 1; i <= p; i++){
            scanf("%d", &v[i]);
        }
        v[p + 1] = 1<<29;

        int maxN = 0;
        int maxL;
        int maxU;

        for(int i = 1; i <= p; i++){
            int key = v[i] + y - 1;

            int l = i;
            int u = p + 1;
            int mid;
            while(l <= u){
                mid = (l + u) / 2;
                if(v[mid] <= key){
                    l = mid + 1;
                }else{
                    u = mid - 1;
                }
            }

            int n = u - i + 1;
            if(maxN < n){
                maxN = n;
                maxL = v[i];
                maxU = v[u];
            }
        }

        printf("%d %d %d\n", maxN, maxL, maxU);


    }
    return 0;
}
