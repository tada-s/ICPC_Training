#include <bits/stdc++.h>

using namespace std;

#define INF 1<<29

#define MAX 1
#define MIN -1

int N = 0;

int stv[(1<<27)-1];
int stvmin[(1<<27)-1];
int v[100][100];

typedef struct {
    int index;
    int x1;
    int y1;
    int x2;
    int y2;
} stnode;

enum stCode{
    ROOT, UL, UR, DL, DR
};

stnode getNode(stnode n, stCode code){
    int x1 = n.x1;
    int y1 = n.y1;
    int x2 = n.x2;
    int y2 = n.y2;
    int x12 = (x1 + x2) / 2;
    int y12 = (y1 + y2) / 2;
    if(x1 == x2){
        switch(code){
        case UL:{
            stnode r = {4 * n.index - 2,
                x1, y1,
                x2, y12
            };
            return r;
        }case UR:{
            stnode r = {4 * n.index - 1,
                x1, y1,
                x2, y12
            };
            return r;
        }case DL:{
            stnode r = {4 * n.index,
                x1, y12 + 1,
                x2, y2
            };
            return r;
        }case DR:{
            stnode r = {4 * n.index + 1,
                x1, y12 + 1,
                x2, y2
            };
            return r;
        }
        }
    }
    if(y1 == y2){
        switch(code){
        case UL:{
            stnode r = {4 * n.index - 2,
                x1, y1,
                x12, y2
            };
            return r;
        }case UR:{
            stnode r = {4 * n.index - 1,
                x12 + 1, y1,
                x2, y2
            };
            return r;
        }case DL:{
            stnode r = {4 * n.index,
                x1, y1,
                x12, y2
            };
            return r;
        }case DR:{
            stnode r = {4 * n.index + 1,
                x12 + 1, y1,
                x2, y2
            };
            return r;
        }
        }
    }
    switch(code){
    case UL:{
        stnode r = {4 * n.index - 2,
            x1, y1,
            x12, y12
        };
        return r;
    }case UR:{
        stnode r = {4 * n.index - 1,
            x12 + 1, y1,
            x2, y12
        };
        return r;
    }case DL:{
        stnode r = {4 * n.index,
            x1, y12 + 1,
            x12, y2
        };
        return r;
    }case DR:{
        stnode r = {4 * n.index + 1,
            x12 + 1, y12 + 1,
            x2, y2
        };
        return r;
    }
    }
}


stnode getRootNode(){
    stnode nR = {1, 0, 0, N - 1, N - 1};
    return nR;
}


int stCreate(stnode n, int code){
    if(n.x1 == n.x2 && n.y1 == n.y2){
        stv[n.index] = v[n.x1][n.y1];
        stvmin[n.index] = v[n.x1][n.y1];
    }else{
        if(code == MAX){
            stv[n.index] = -INF;
            stv[n.index] = max(stv[n.index], stCreate(getNode(n, UL), code));
            stv[n.index] = max(stv[n.index], stCreate(getNode(n, UR), code));
            stv[n.index] = max(stv[n.index], stCreate(getNode(n, DL), code));
            stv[n.index] = max(stv[n.index], stCreate(getNode(n, DR), code));
        }else{
            stvmin[n.index] = INF;
            stvmin[n.index] = min(stvmin[n.index], stCreate(getNode(n, UL), code));
            stvmin[n.index] = min(stvmin[n.index], stCreate(getNode(n, UR), code));
            stvmin[n.index] = min(stvmin[n.index], stCreate(getNode(n, DL), code));
            stvmin[n.index] = min(stvmin[n.index], stCreate(getNode(n, DR), code));
        }
    }
    if(code == MAX) return stv[n.index];
    else return stvmin[n.index];
}

bool hasintersection(int x1, int y1, int x2, int y2, stnode n){
    if(n.x2 < x1 || n.y2 < y1) return false;
    if(x2 < n.x1 || y2 < n.y1) return false;
    return true;
}

bool contain(int x, int y, stnode n){
    return (n.x1 <= x && x <= n.x2 && n.y1 <= y && y <= n.y2);
}

int stQuery(int qx1, int qy1, int qx2, int qy2, stnode n, int code){
    if((qx1 <= n.x1 && n.x2 <= qx2) && (qy1 <= n.y1 && n.y2 <= qy2)){
    if(code == MAX) return stv[n.index];
    else return stvmin[n.index];
    }else{
        stnode nUL = getNode(n, UL);
        stnode nUR = getNode(n, UR);
        stnode nDL = getNode(n, DL);
        stnode nDR = getNode(n, DR);
        if(code == MAX){
            int m = -INF;
            //printf("\n q: %d %d %d %d, n: %d %d %d %d\n", qx1, qy1, qx2, qy2, n.x1, n.y1, n.x2, n.y2);
            if(hasintersection(qx1, qy1, qx2, qy2, nUL)){
                m = max(m, stQuery(qx1, qy1, qx2, qy2, nUL, code));
            }
            if(hasintersection(qx1, qy1, qx2, qy2, nUR)){
                m = max(m, stQuery(qx1, qy1, qx2, qy2, nUR, code));
            }
            if(hasintersection(qx1, qy1, qx2, qy2, nDL)){
                m = max(m, stQuery(qx1, qy1, qx2, qy2, nDL, code));
            }
            if(hasintersection(qx1, qy1, qx2, qy2, nDR)){
                m = max(m, stQuery(qx1, qy1, qx2, qy2, nDR, code));
            }
        return m;
        }else{
            int m = INF;
            //printf("\n q: %d %d %d %d, n: %d %d %d %d\n", qx1, qy1, qx2, qy2, n.x1, n.y1, n.x2, n.y2);
            if(hasintersection(qx1, qy1, qx2, qy2, nUL)){
                m = min(m, stQuery(qx1, qy1, qx2, qy2, nUL, code));
            }
            if(hasintersection(qx1, qy1, qx2, qy2, nUR)){
                m = min(m, stQuery(qx1, qy1, qx2, qy2, nUR, code));
            }
            if(hasintersection(qx1, qy1, qx2, qy2, nDL)){
                m = min(m, stQuery(qx1, qy1, qx2, qy2, nDL, code));
            }
            if(hasintersection(qx1, qy1, qx2, qy2, nDR)){
                m = min(m, stQuery(qx1, qy1, qx2, qy2, nDR, code));
            }
        return m;
        }

    }
}

int stModify(int x, int y, int value, stnode n, int code){
    int delta = -INF;
    if(n.x1 == n.x2 && n.y1 == n.y2){
        if(code == MAX)
            delta = max(value, stv[n.index]);
        else
            delta = min(value, stvmin[n.index]);
    }else{
        stnode nUL = getNode(n, UL);
        stnode nUR = getNode(n, UR);
        stnode nDL = getNode(n, DL);
        stnode nDR = getNode(n, DR);
        if(contain(x, y, nUL)){
            delta = stModify(x, y, value, nUL, code);
        }else if(contain(x, y, nUR)){
            delta = stModify(x, y, value, nUR, code);
        }else if(contain(x, y, nDL)){
            delta = stModify(x, y, value, nDL, code);
        }else if(contain(x, y, nDR)){
            delta = stModify(x, y, value, nDR, code);
        }
    }
    if(code == MAX)
        stv[n.index] = max(stv[n.index], delta);
    else
        stvmin[n.index] = min(stvmin[n.index], delta);
    return delta;
}

int main(){
    freopen("input.txt", "r", stdin);
    scanf("%d %*d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &v[i][j]);
        }
    }
    stCreate(getRootNode(), MAX);
    stCreate(getRootNode(), MIN);
    //printf("query : %d\n", stQuery(2,2,4,4,getRootNode()));

    int q;
    scanf("%d%*c", &q);
    for(int i = 0; i < q; i++){
        int a = '!',b = 0,c = 0,d = 0,e = 0;
        scanf("%c %d %d %d %d%*c", &a, &b, &c, &d, &e);
        if(a == 'q'){
            printf("%d %d\n", stQuery(b,c,d,e,getRootNode(),MAX), stQuery(b,c,d,e,getRootNode(),MIN));
        }else if(a == 'c'){
            stModify(b, c, d, getRootNode(),MAX);
            stModify(b, c, d, getRootNode(),MIN);
        }
    }
    return 0;
}
