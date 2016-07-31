#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    scanf("%d%*c%*c", &n);
    char c;

    for(int nn = 0; nn < n; nn++){
        stack<char> s;
        scanf("%c", &c);
        while(c != '\n'){
//if(!s.empty()) printf("[%c,%c]", c, s.top());
//else printf("[%c, ]", c);
            switch(c){
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0':
                putchar(c);
                break;
            case '+':
            case '-':
                while(!s.empty()){
                    if(s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/'){
                        putchar(s.top());
                        s.pop();
                    }else{
                        break;
                    }
                }
                s.push(c);
                break;
            case '*':
            case '/':
                while(!s.empty()){
                    if(s.top() == '*' || s.top() == '/'){
                        putchar(s.top());
                        s.pop();
                    }else{
                        break;
                    }
                }
                s.push(c);
                break;
            case '(':
                s.push(c);
                break;
            case ')':
                while(s.top() != '('){
                    putchar(s.top());
                    s.pop();
                }
                s.pop();
                break;
            }
            if(!(scanf("%*c%c", &c) > 0)){
                break;
            }
        }
        while(!s.empty()){
            putchar(s.top());
            s.pop();
        }
        if(nn != n - 1){
            printf("\n\n");
        }else{
            printf("\n");
        }
    }
    return 0;
}
