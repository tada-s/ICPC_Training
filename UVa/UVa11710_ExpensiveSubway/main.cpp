#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mkp make_pair

vector<int> pset;
void initSet(int n){
    pset.resize(n);
    for(int i = 0; i < n; i++){
        pset[i] = i;
    }
}
int findSet(int i){
    return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}
void unionSet(int i, int j){
    pset[findSet(i)] = findSet(j);
}

int main(){
    //freopen("input.txt","r", stdin);
    int s, c;
    scanf("%d %d", &s, &c);
    while(!(s == 0 && c == 0)){
        initSet(s);
        map<string, int> m;
        for(int i = 0; i < s; i++){
            char str[11];
            scanf("%s", str);
            m[string(str)] = i;
        }
        vector< pair<int, pair<int, int> > > v;
        for(int i = 0; i < c; i++){
            char str1[11];
            char str2[11];
            int w;
            scanf("%s %s %d", str1, str2, &w);
            v.pb( mkp( w, mkp( m[string(str1)], m[string(str2)]) ) );
        }
        {
            char str[11];
            scanf("%*s");
        }
        sort(v.begin(), v.end());
        int sum = 0;
        int x = 0;
        for(int i = 0; i < v.size(); i++){
            if(findSet(v[i].second.first) != findSet(v[i].second.second)){
                unionSet(v[i].second.first, v[i].second.second);
                sum += v[i].first;
                x++;
            }
        }
        if(x == s - 1){
            printf("%d\n", sum);
        }else{
            printf("Impossible\n");
        }
        scanf("%d %d", &s, &c);
    }
    return 0;
}
