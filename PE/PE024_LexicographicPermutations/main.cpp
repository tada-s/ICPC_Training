#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v(10);
    for(int i = 0; i < 10; i++) v[i] = i;
    for(int i = 1; i < 1000000; i++) next_permutation(v.begin(), v.end());
    for(int i = 0; i < 10; i++) printf("%d", v[i]);
    return 0;
}
