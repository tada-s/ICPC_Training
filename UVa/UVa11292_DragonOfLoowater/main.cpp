#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    while(!(n == 0 && m == 0)){
        priority_queue<int> dragonHead;
        for(int i = 0; i < n; i++){
            int x;
            scanf("%d", &x);
            dragonHead.push(-x);
        }

        priority_queue<int> knightHeight;
        for(int i = 0; i < m; i++){
            int x;
            scanf("%d", &x);
            knightHeight.push(-x);
        }

        int cost = 0;
        while(!dragonHead.empty() && !knightHeight.empty()){
            while(!knightHeight.empty()){
                if(-dragonHead.top() <= -knightHeight.top()){
                    break;
                }
                knightHeight.pop();
            };
            if(!knightHeight.empty()){
                cost += -knightHeight.top();
                dragonHead.pop();
                knightHeight.pop();
            }
        }

        if(dragonHead.empty()){
            printf("%d\n", cost);
        }else{
            printf("Loowater is doomed!\n");
        }


        scanf("%d%d", &n, &m);
    }
    return 0;
}
