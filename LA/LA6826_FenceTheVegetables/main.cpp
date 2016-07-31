#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mkp make_pair

typedef pair<int, int> ii;
typedef vector<ii> vii;

vii getUpperHull(vii& v){
    vii increasingHull;
    int lastPoint = 0;
    increasingHull.pb(v[lastPoint]);
    for(int i = 0; i < v.size(); i++){
        if(v[i].second > v[lastPoint].second){
            if(v[i].first == v[lastPoint].first){
                increasingHull[lastPoint] = v[i];
            }else{
                increasingHull.pb(mkp(v[i].first, v[lastPoint].second));
                increasingHull.pb(v[i]);
            }
            lastPoint = i;
        }
    }

    vii decreasingHull;
    lastPoint = v.size()-1;
    decreasingHull.pb(v[lastPoint]);
    for(int i = v.size()-1; i >= 0; i--){
        if(v[i].second > v[lastPoint].second){
            if(v[i].first == v[lastPoint].first){
                decreasingHull[lastPoint] = v[i];
            }else{
                decreasingHull.pb(mkp(v[i].first, v[lastPoint].second));
                decreasingHull.pb(v[i]);
            }
            lastPoint = i;
        }
    }

    reverse(decreasingHull.begin(), decreasingHull.end());
    increasingHull.insert(increasingHull.end(), decreasingHull.begin(), decreasingHull.end());
    return increasingHull;
}

vii getLowerHull(vii& v){
    vii decreasingHull;
    int lastPoint = 0;
    decreasingHull.pb(v[lastPoint]);
    for(int i = 0; i < v.size(); i++){
        if(v[i].second < v[lastPoint].second){
            if(v[i].first == v[lastPoint].first){
                decreasingHull[lastPoint] = v[i];
            }else{
                decreasingHull.pb(mkp(v[i].first, v[lastPoint].second));
                decreasingHull.pb(v[i]);
            }
            lastPoint = i;
        }
    }

    vii increasingHull;
    lastPoint = v.size()-1;
    increasingHull.pb(v[lastPoint]);
    for(int i = v.size()-1; i >= 0; i--){
        if(v[i].second < v[lastPoint].second){
            if(v[i].first == v[lastPoint].first){
                increasingHull[lastPoint] = v[i];
            }else{
                increasingHull.pb(mkp(v[i].first, v[lastPoint].second));
                increasingHull.pb(v[i]);
            }
            lastPoint = i;
        }
    }
    reverse(increasingHull.begin(), increasingHull.end());
    decreasingHull.insert(decreasingHull.end(), increasingHull.begin(), increasingHull.end());
    return decreasingHull;
}

int main(){
    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    vii v;
    for(int i = 0; i < n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        v.pb(mkp(x+1,y+1));
        v.pb(mkp(x-1,y+1));
        v.pb(mkp(x+1,y-1));
        v.pb(mkp(x-1,y-1));
    }
    sort(v.begin(), v.end());
    vii lowerHull = getLowerHull(v);
    vii upperHull = getUpperHull(v);
    int area = 0;
    for(int i = 0; i < upperHull.size() - 1; i++){
        area += (upperHull[i+1].first - upperHull[i].first) * (upperHull[i].second);
    }
    for(int i = 0; i < lowerHull.size() - 1; i++){
        area -= (lowerHull[i+1].first - lowerHull[i].first) * (lowerHull[i].second);
    }
    printf("%d\n", area);
    return 0;
}
