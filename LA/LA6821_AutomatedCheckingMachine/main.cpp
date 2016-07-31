#include <bits/stdc++.h>

using namespace std;

int main(){
    int v1[5], v2[5];

    for(int i = 0; i < 5; i++){
        scanf("%d", &v1[i]);
    }

    while(!feof(stdin)){
        for(int i = 0; i < 5; i++){
            scanf("%d", &v2[i]);
        }
        int i;
        for(i = 0; i < 5; i++){
            if(v1[i] == v2[i]) break;
        }
        if(i == 5) printf("Y\n");
        else printf("N\n");

        for(int i = 0; i < 5; i++){
            scanf("%d", &v1[i]);
        }
    }

    return 0;
}
