#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    int v[1000];
    int n;
    scanf("%d", &n);
    while(n != 0){
        scanf("%d", &v[0]);
        while(v[0] != 0){
            for(int i = 1; i < n; i++){
                scanf("%d", &v[i]);
            }

            stack<int> s1;
            for(int i = n; i >= 1; i--){
                s1.push(i);
            }
            stack<int> s2;

            bool impossible = false;
            for(int i = 0; i < n && ! impossible; i++){
                if(!s2.empty()){
                    if(s2.top() == v[i]){
                        s2.pop();
                        continue;
                    }
                }
                if(s1.empty()){
                    impossible = true;
                    break;
                }
                while(s1.top() != v[i]){
                    s2.push(s1.top());
                    s1.pop();
                    if(s1.empty()){
                        impossible = true;
                        break;
                    }
                }
                if(!s1.empty()){
                    if(s1.top() == v[i]){
                        s1.pop();
                        continue;
                    }
                }
            }
            printf("%s\n", impossible ? "No" : "Yes");

            scanf("%d", &v[0]);
        }
        printf("\n");
        scanf("%d", &n);
    }
    return 0;
}
