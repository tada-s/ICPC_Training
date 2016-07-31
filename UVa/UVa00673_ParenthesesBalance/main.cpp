#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d%*c", &n);
    for(int i = 0; i < n; i++){
        char str[128 + 1] = "";
        scanf("%[^\n]%*c", str);
        if(str[0] == '\0') scanf("%*c");
        stack<char> s;
        bool flag = false;
        for(int j = 0; str[j] != '\0'; j++){
            char c = str[j];
            if(c == '(' || c == '['){
                s.push(c);
            }else if(c == ')' || c == ']'){
                if(!s.empty()){
                    if((s.top() == '(' && c == ')') || (s.top() == '[' && c == ']')){
                        s.pop();
                    }else{
                        flag = true;
                        break;
                    }
                }else{
                    flag = true;
                    break;
                }
            }
        }
        printf("%s\n", s.empty() && !flag ? "Yes" : "No");
    }
    return 0;
}
