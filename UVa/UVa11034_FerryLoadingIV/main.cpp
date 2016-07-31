#include <bits/stdc++.h>

using namespace std;

#define LEFT 0
#define RIGHT 1
int l;
queue<int> q[2];

bool existCar(int pos){
    return !q[pos].empty();
}

bool existCar(){
    return existCar(LEFT) || existCar(RIGHT);
}

void loadcar(int pos){
    int space = 0;
    while(existCar(pos)){
        if(space + q[pos].front() < l){
            space += q[pos].front();
            q[pos].pop();
        }else{
            break;
        }
    }
}



int main(){
    //freopen("input.txt", "r", stdin);
    int c;
    scanf("%d", &c);
    for(int cc = 0; cc < c; cc++){
        int m;
        scanf("%d%d", &l, &m);
        l *= 100;

        for(int i = 0; i < m; i++){
            int x;
            char str[8];
            scanf("%d%s", &x, str);
            if(str[0] == 'l'){
                q[LEFT].push(x);
            }else{
                q[RIGHT].push(x);
            }
        }

        int pos = LEFT;
        int opos = RIGHT;
        int cross = 0;
        while(existCar()){
            if(existCar(pos)){
                loadcar(pos);
                swap(pos, opos);
                cross++;
            }else{
                swap(pos, opos);
                cross++;
            }
        }

        printf("%d\n", cross);
    }
    return 0;
}
