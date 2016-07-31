#include <bits/stdc++.h>

using namespace std;

vector<int> pset;

void initSet(int n){
    pset.resize(n);
    for(int i = 0; i < n; i++){
        pset[i] = i;
    }
}

int findSet(int i){
    if(pset[i] != i){
        pset[i] = findSet(pset[i]);
    }
    return pset[i];
}

void unionSet(int i, int j){
    pset[findSet(i)] = findSet(j);
}

int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for(int tt = 0; tt < t; tt++){
        int n;
        scanf("%d%*c", &n);

        initSet(n + 1);

        char str[128];
        int success = 0, unsuccess = 0;
        str[0] = '\0';
        scanf("%[^\n]%*c", str);
        while(str[0] != '\0'){
            char a;
            int b, c;
            sscanf(str, "%c %d %d", &a, &b, &c);
            if(a == 'c'){
                unionSet(b, c);
            }else{
                if(findSet(b) == findSet(c)){
                    success++;
                }else{
                    unsuccess++;
                }
            }
            str[0] = '\0';
            scanf("%[^\n]%*c", str);
        }

        printf("%d,%d\n", success, unsuccess);
        if(tt != t - 1){
            printf("\n");
        }

    }
    return 0;
}
