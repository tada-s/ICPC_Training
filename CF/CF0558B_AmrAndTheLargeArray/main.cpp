#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair
#define pb push_back

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    int n;
    scanf("%d", &n);

    vii v;
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        v.pb(mkp(a, i));
    }

    sort(v.begin(), v.end());

    #define INF 1<<29
    int maxSeqLength = 0;
    int minInterval = INF;
    int intervalB = 0;
    int intervalE = 0;

    int begin = 0;
    for(int i = 0; i < n - 1; i++){
        if(v[i].first != v[i+1].first){
            int end = i;
            if(end - begin + 1 > maxSeqLength || (end - begin + 1 == maxSeqLength && v[end].second - v[begin].second < minInterval)){
                intervalB = v[begin].second;
                intervalE = v[end].second;
                minInterval = intervalE - intervalB;
                maxSeqLength = end - begin + 1;
            }
            begin = i + 1;
        }
    }
    int end = n - 1;
    if(end - begin + 1 > maxSeqLength || (end - begin + 1 == maxSeqLength && v[end].second - v[begin].second < minInterval)){
        intervalB = v[begin].second;
        intervalE = v[end].second;
        minInterval = intervalE - intervalB;
        maxSeqLength = end - begin + 1;
    }

    printf("%d %d\n", intervalB + 1, intervalE + 1);

    return 0;
}
