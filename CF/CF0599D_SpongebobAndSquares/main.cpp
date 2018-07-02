#include <bits/stdc++.h>

using namespace std;

typedef long long number;

#define mkp make_pair
#define pb push_back

int main(){
    vector< pair<number, number> > v;
    number x;
    scanf("%I64d", &x);
    for(number n = 1; n < pow(3 * x, 1 / 3.0); n++){
        number m = (x * 6 / (n * (n + 1)) - (2 * n + 1)) / 3 + n;
        //cout << n << ' ' << m << endl;
        if(x == (n * (n + 1) * (2 * n + 1 + 3 * (m - n))) / 6){
            v.pb(mkp(n, m));
        }

    }

    if(v[v.size() - 1].first == v[v.size() - 1].second){
        printf("%d\n", v.size() * 2 - 1);
    }else{
        printf("%d\n", v.size() * 2);
    }
    for(int i = 0; i < v.size(); i++){
        printf("%I64d %I64d\n", v[i].first, v[i].second);
    }
    if(v[v.size() - 1].first != v[v.size() - 1].second){
        printf("%I64d %I64d\n", v[v.size() - 1].second, v[v.size() - 1].first);
    }
    for(int i = v.size() - 1 - 1; i >= 0; i--){
        printf("%I64d %I64d\n", v[i].second, v[i].first);
    }

    return 0;
}
