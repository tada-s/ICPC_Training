#include <bits/stdc++.h>

using namespace std;

vector<int> v;

void initSet(int n){
    v.resize(n);
    for(int i = 0; i < n; i++){
        v[i] = i;
    }
}

int findSet(int n){
    if(v[n] != n){
        v[n] = findSet(v[n]);
    }
    return v[n];
}

void unionSet(int i, int j){
    v[findSet(i)] = findSet(findSet(j));
}


int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for(int tt = 0; tt < t; tt++){
        char str[3];
        scanf("%s%*c", str);

        char l = str[0];
        initSet(l + 1);
        str[0] = '\0';
        scanf("%[^\n]%*c", str);
        while(str[0] != '\0'){
            unionSet(str[0], str[1]);
            str[0] = '\0';
            scanf("%[^\n]%*c", str);
        }

        map<int, int> m;

        for(int i = 'A'; i <= l; i++){
            m[findSet(i)]++;
        }

        printf("%d\n", m.size());

        if(tt != t - 1){
            printf("\n");
        }
    }
    return 0;
}
