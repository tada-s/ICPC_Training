#include <bits/stdc++.h>

using namespace std;

typedef long long number;

map<pair<int, int>, number> dpTable;

number f(int x, int y){
    pair<int, int> p = (x < y)?(make_pair(x,y)):(make_pair(y,x));
    if(dpTable.find(p) == dpTable.end()){
        if(x == 0 || y == 0) return 1;
        number r = f(x-1, y) + f(x, y-1);
        dpTable[p] = r;
        return r;
    }else{
        return dpTable[p];
    }
}

int main(){
    printf("%I64d",f(20,20));
    return 0;
}
