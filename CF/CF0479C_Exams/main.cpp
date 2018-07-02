#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
#define rep(c,n) for(__typeof(n) c = 0; c < n; c++)
#define mkp make_pair
#define all(x) x.begin(), x.end()

vector<ii> examDay;
int n, a, b;

int getMin(int n){
    return min(examDay[n].first, examDay[n].second);
}

int getMax(int n){
    return max(examDay[n].first, examDay[n].second);
}

int findDate(){
    int j;
    int i = getMin(0);
    for(j = 0; j < n; j++){
        if(getMin(j) >= i) i = getMin(j);
        else if(getMax(j) >= i) i = getMax(j);
    }
    return i;
}

int main(){
    scanf("%d", &n);
    rep(c,n){
        scanf("%d %d", &a, &b);
        examDay.push_back(mkp(a,b));
    }

    sort(all(examDay));

    int date = findDate();

    printf("%d",date);

    return 0;
}
