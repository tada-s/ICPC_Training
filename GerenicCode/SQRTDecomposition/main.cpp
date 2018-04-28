#include <bits/stdc++.h>

using namespace std;


void preprocess(vector<int> v){
    int b = (int) sqrt(v.size()) + 1;
    bucket.resize(b);
    for(int i = 0; i < v.size(); i++){
        bucket[i / b] += v[i];
    }
}

int rsq(int i, int j){
    int b = bucket.size();
    int sum = 0;
    int bi = i / b, bj = j / b;
    if (bi == bj){
        for (int k = i; k <= j; k++)
            sum += v[i];
    } else {
        for (int k=i; k<=(bi + 1) * b - 1; k++)
            sum += v[i];
        for (int k = bi + 1; k <= bj - 1; k++)
            sum += bucket[k];
        for (int k = bj * len; k <= j; k++)
            sum += v[k];
    }
    return sum;
}

void update(int i, int x){
    int b = bucket.size();
    v[i] += x;
    bucket[i / b] += x;
}

int main(){

    return 0;
}
