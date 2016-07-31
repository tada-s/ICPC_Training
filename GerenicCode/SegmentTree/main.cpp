#include <bits/stdc++.h>

using namespace std;

#define pb push_back
typedef vector<int> vi;

vi stv;
vi v;

typedef struct {
    int index;
    int left;
    int right;
} stnode;

stnode getLeftNode(stnode n){
    stnode nL = {2 * n.index, n.left, (n.left + n.right) / 2};
    return nL;
}

stnode getRightNode(stnode n){
    stnode nR = {2 * n.index + 1, (n.left + n.right) / 2 + 1, n.right};
    return nR;
}

stnode getRootNode(){
    stnode nR = {1, 0, v.size()-1};
    return nR;
}

int stCreate(stnode n){
    if(n.left == n.right){
        stv[n.index] = v[n.left];
    }else{
        stv[n.index] = stCreate(getLeftNode(n)) + stCreate(getRightNode(n));
    }
    return stv[n.index];
}

int stQuery(int qleft, int qright, stnode n){
    if(qleft <= n.left && n.right <= qright){
        return stv[n.index];
    }else{
        stnode nL = getLeftNode(n);
        stnode nR = getRightNode(n);
        if(qleft <= nL.right && nR.left <= qright){
            return stQuery(qleft, qright, nL) + stQuery(qleft, qright, nR);
        }else if(qleft <= nL.right){
            return stQuery(qleft, qright, nL);
        }else if(nR.left <= qright){
            return stQuery(qleft, qright, nR);
        }else{
            return 0;
        }
    }
}

int stModify(int i, int value, stnode n){
    stnode nL = getLeftNode(n);
    stnode nR = getRightNode(n);
    int delta = 0;
    if(n.left == n.right){
        stv[n.index] = value;
    }else{
        if(nL.left <= i && i <= nL.right){
            stModify(i, value, nL);
        }else{
            stModify(i, value, nR);
        }
        stv[n.index] = stv[nL.index] + stv[nR.index];
    }
    return stv[n.index];
}

int main(){
    v.pb(2);
    v.pb(3);
    v.pb(7);
    v.pb(11);
    v.pb(4);
    v.pb(5);
    stv.resize(pow(2, ceil(log(6)/log(2))));
    stCreate(getRootNode());
    stModify(3, 10, getRootNode());
    printf("%d", stQuery(0,4, getRootNode()));
    return 0;
}
