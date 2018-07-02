#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mkp make_pair

int main(){
    int sum = 0, block = 0, n, v[100000 + 1], v2[100000 + 1];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
        v2[i] = v[i];
    }
    sort(v2, v2 + n);
    for(int i = 0; i < n; i++){
        sum += v[i] - v2[i];
        if(sum == 0){
            block++;
        }
    }

    /*
    vector< pair<int, int> > v;
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int h;
        scanf("%d", &h);
        v.pb(mkp(h, i));
    }

    sort(v.begin(), v.end());

    int block = 0;
    for(int i = 0; i < n; i++){
        int target = v[i].second;
        for(int j = i + 1; j <= target; j++){
            target = max(target, v[j].second);
        }
        i = target;
        block++;
    }*/

    printf("%d\n", block);
    return 0;
}
