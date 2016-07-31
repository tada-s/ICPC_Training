#include <bits/stdc++.h>

using namespace std;

#define LSOne(x) ((x) & -(x))
#define mkp make_pair
#define pb push_back

vector<int> ft;
int rsq(int a){
    a = ft.size() - a - 1;
    int sum = 0;
    for(; a; a -= LSOne(a)){
//printf("[%d!%d]", a, ft.size());
        sum += ft[a];
    }
    return sum;
}

void actualizar(int k, int v){
    k = ft.size() - k - 1;
    for(; k < (int) ft.size(); k += LSOne(k)){

        ft[k] += v;
    }
}

bool cmp1(pair<int, int> p1, pair<int, int> p2){
    if(p1.first != p2.first) return p1.first > p2.first;
    else return p1.second > p2.second;
}

int main(){
    //freopen("input.txt", "r", stdin);
    int v[500000];
    int n;
    scanf("%d", &n);
    while(n != 0){
        for(int i = 0; i < n; i++){
            scanf("%d", &v[i]);
        }

        vector<pair<int, int> > p;
        for(int i = 0; i < n; i++){
            p.pb(mkp(v[i], i));
        }
        sort(p.begin(), p.end(), cmp1);

        ft.clear();
        ft.resize(n + 1);
        for(int i = 0; i < n; i++){
            actualizar(i, 1);
        }

        long long sum = 0;
        for(int i = 0; i < n; i++){
            int x = rsq(p[i].second) - 1;
//printf("[%d %d]", x, p[i].second);
            sum += x;
            actualizar(p[i].second, -1);
        }

//printf("!");
        printf("%ld\n", sum);

        scanf("%d", &n);
    }
    return 0;
}
