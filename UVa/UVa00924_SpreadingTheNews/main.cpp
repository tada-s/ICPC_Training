#include <iostream>
#include <vector>
#include <stdio.h>
#include <bitset>
#include <queue>

using namespace std;


vector<int> eFriends[2501];
bool isVisited[2501];

int main(){
    queue<int> q;
    int e, n, t;
    int x;
    int day, b, maxB, maxDay;
    //freopen("input.txt","r",stdin);
    scanf("%d",&e);
    for(int i = 0; i < e; i++){
        scanf("%d",&n);
        for(int j = 0; j < n; j++){
            scanf("%d",&x);
            eFriends[i].push_back(x);
        }
    }
    scanf("%d",&t);
    for(int i = 0; i < t; i++){
        scanf("%d",&x);
        if(eFriends[x].size() == 0 ){
            printf("0\n");
        }else{
            isVisited[x] = true;
            for(int j = 0; j < eFriends[x].size(); j++){
                q.push((eFriends[x])[j]);
            }
            q.push(-1);

            day = 1;
            maxDay = 0;
            maxB = 0;
            b = 0;
            while(true){
                x = q.front();
                q.pop();
                if(x == -1){
                    if(b > maxB ){
                        maxB = b;
                        maxDay = day;
                    }
                    day++;
                    b=0;
                    if(q.empty()) break;
                    q.push(-1);
                }else{
                    if(!isVisited[x]){
                        isVisited[x] = true;
                        b++;
                        for(int j = 0; j < eFriends[x].size(); j++){
                            if(!isVisited[(eFriends[x])[j]]){
                                q.push((eFriends[x])[j]);
                            }
                        }
                    }
                }
            }
            printf("%d %d\n",maxB, maxDay);
            for(int j = 0; j < e; j++){
                isVisited[j] = false;
            }
        }
    }
    return 0;
}
