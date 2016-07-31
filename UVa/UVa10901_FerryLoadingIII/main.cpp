#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair
#define INF (1<<29)

#define LEFT 1
#define RIGHT 0
int n, t, m;
int timeT;
int cartime[10000 + 1];
queue< pair<int, int> > q[2];

bool existCar(){
    return !q[LEFT ].empty() || !q[RIGHT].empty();
}

void transportCar(int pos){
    int car = 0;
    while(!q[pos].empty()){
        if(car == n || q[pos].front().second > timeT){
            break;
        }else{
            //printf("[%d]", timeT + t);
            cartime[q[pos].front().first] = timeT + t;
            q[pos].pop();
            car++;
        }
    }
}

bool existCarWaiting(int pos){
    if(q[pos].empty()){
        return false;
    }else if(q[pos].front().second > timeT){
        return false;
    }else{
        return true;
    }
}

int willExistCarTime(){
    int t = INF;
    if(!q[LEFT].empty()){
        t = min(t, q[LEFT].front().second);
    }
    if(!q[RIGHT].empty()){
        t = min(t, q[RIGHT].front().second);
    }
    return t;
}

bool willExistCar(){
    return willExistCarTime() != INF;
}


int main(){
    //freopen("input.txt", "r", stdin);
    int c;
    scanf("%d", &c);
    for(int cc = 0; cc < c; cc++){

        scanf("%d%d%d", &n, &t, &m);

        for(int i = 0; i < m; i++){
            int x;
            char str[8];
            scanf("%d %s", &x, str);
            if(strcmp(str, "left") == 0){
                q[LEFT].push(mkp(i, x));
            }else{
                q[RIGHT].push(mkp(i, x));
            }
        }

        timeT = 0;
        int pos = LEFT;
        int oppos = RIGHT;

        while(existCar()){
            if(existCarWaiting(pos)){
                transportCar(pos);
                timeT += t;
                swap(pos, oppos);
            }else if(existCarWaiting(oppos)){
                timeT += t;
                swap(pos, oppos);
            }else if(willExistCar()){
                timeT = willExistCarTime();
            }
        }

        for(int i = 0; i < m ;i++){
            printf("%d\n", cartime[i]);
        }
        if(cc != c - 1){
            printf("\n");
        }
    }
    return 0;
}
