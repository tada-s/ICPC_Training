#include <bits/stdc++.h>

using namespace std;

int k;
int v[13];
stack<int> s;

void f(int i, int n){
    s.push(v[i]);
    if(n == 6){
        stack<int> s1 = s;
        stack<int> s2;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        printf("%d", s2.top());
        s2.pop();
        while(!s2.empty()){
            printf(" %d", s2.top());
            s2.pop();
        }
        printf("\n");
    }else{
        if(k - i + n >= 6){
            for(int j = i + 1; j < k; j++){
                f(j, n + 1);
            }
        }
    }
    s.pop();
}

int main(){
    //freopen("input.txt", "r", stdin);
    bool firstTime = true;

    scanf("%d", &k);
    while(k != 0){
        if(firstTime){
            firstTime = false;
        }else{
            printf("\n");
        }

        for(int i = 0; i < k; i++){
            scanf("%d", &v[i]);
        }

        for(int i = 0; k - i >= 6; i++){
            f(i, 1);
        }

        scanf("%d", &k);
    }
    return 0;
}
