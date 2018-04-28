#include <bits/stdc++.h>

using namespace std;

#define pb push_back

vector<int> v;
vector<int> headIndex;
vector<int> parentIndex;

int getLongestSubsequence(int x){
    int lb = 0;
    int ub = headIndex.size() - 1;
    while(lb <= ub){
        int mid = (lb + ub) / 2;
        int x2 = v[headIndex[mid]];
        if(x2 < x){
            lb = mid + 1;
        }else{
            ub = mid - 1;
        }
    }
    return ub;
}

int main(){
    //freopen("input.txt", "r", stdin);

    int x;
    while(scanf("%d", &x) != EOF){
        v.pb(x);
    }


    headIndex.pb(0);
    parentIndex.pb(-1);

    for(int i = 1; i < v.size(); i++){
        int index = getLongestSubsequence(v[i]);
        if(index + 1 == headIndex.size()){
            headIndex.pb(i);
        }else{
            int currentHead = v[headIndex[index + 1]];
            if(v[i] <= currentHead){
                headIndex[index + 1] = i;
            }
        }
        if(index == -1){
            parentIndex.pb(-1);
        }else{
            parentIndex.pb(headIndex[index]);
        }
    }

    stack<int> s;
    int index = headIndex[headIndex.size() - 1];
    while(index != -1){
        s.push(v[index]);
        index = parentIndex[index];
    }

    printf("%d\n-\n", s.size());
    while(!s.empty()){
        printf("%d\n", s.top());
        s.pop();
    }

    return 0;
}
