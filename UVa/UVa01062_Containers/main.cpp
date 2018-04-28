#include <bits/stdc++.h>


using namespace std;

int main(){
    freopen("input.txt", "r", stdin);

    int caseCounter = 0;
    char str[1000 + 1];
    scanf("%s", str);
    while(strcmp(str, "end") != 0){
        caseCounter++;

        stack<int> s[26];
        for(int i = 0; i < 26; i++){
            while(!s[i].empty()){
                s[i].pop();
            }
        }

        int stackCounter = 0;
        for(int i = 0; str[i] != '\0'; i++){
            char c = str[i];
            int actualStack = 0;
            while(!s[actualStack].empty()){
                if(s[actualStack].top() >= c){
                    break;
                }
                actualStack++;
            }
            if(s[actualStack].empty()){
                stackCounter++;
            }
            s[actualStack].push(c);

        }

        printf("Case %d: %d\n", caseCounter, stackCounter);

        scanf("%s", str);
    }

    return 0;
}
