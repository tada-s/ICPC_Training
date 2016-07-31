#include <bits/stdc++.h>

using namespace std;

int n, m;
char dictionary[100][256];
char rule[256];

char output[1024];
int cursor;

void backtrackingPrint(int i){
    if(i == strlen(rule)){
        printf("%s\n", output);
    }else{
        if(rule[i] == '#'){
            for(int j = 0; j < n; j++){
                sprintf(output + cursor, "%s", dictionary[j]);
                cursor += strlen(dictionary[j]);
                backtrackingPrint(i + 1);
                cursor -= strlen(dictionary[j]);
            }
        }else{
            for(int j = 0; j <= 9; j++){
                sprintf(output + cursor, "%d", j);
                cursor++;
                backtrackingPrint(i + 1);
                cursor--;
            }
        }
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    while(scanf("%d", &n) != EOF){
        printf("--\n");
        for(int i = 0; i < n; i++){
            scanf("%s", dictionary[i]);
        }
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%s", rule);
            cursor = 0;
            backtrackingPrint(0);
        }
    }
    return 0;
}
