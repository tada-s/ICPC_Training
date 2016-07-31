#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v = {1, 2, 2, 2, 5, 6, 6, 7, 7, 7, 9, 9, 9};
                   //0  1  2  3  4  5  6  7  8  9 10 11 12
    int query = 3;
    vector<int>::iterator iter = upper_bound(v.begin(), v.end(), query);
    if(iter != v.end()){
        cout << "v[" << (iter - v.begin()) << "] = " << *iter;
    }else{
        cout << "END! D:";
    }
    return 0;
}
