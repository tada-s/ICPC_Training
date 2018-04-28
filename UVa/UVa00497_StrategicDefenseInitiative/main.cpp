#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define UNDEF (-1)

vector<int> v1;
vector<int> v2;
int dp[1000][1000];
stack<int> printStack;

void printlis(int i, int j){
    if(i < 0 || j < 0){
        while(!printStack.empty()){
            printf("%d\n", printStack.top());
            printStack.pop();
        }
        return;
    }
    //printf("at (%d, %d) = %d, %d:%d:%d\n", i, j, dp[i][j], dp[i - 1][j - 1], dp[i - 1][j], dp[i][j- 1]);
    if(v1[i] == v2[j]){
        printStack.push(v1[i]);
        printlis(i - 1, j - 1);
    }else if(dp[i - 1][j] == dp[i][j]){
        printlis(i - 1, j);
    }else{
        printlis(i, j - 1);
    }
}

int lis(int i, int j){
    if(i < 0 || j < 0){
        return 0;
    }
    if(dp[i][j] == UNDEF){
        if(v1[i] == v2[j]){
            dp[i][j] = lis(i - 1, j - 1) + 1;
        }else{
            dp[i][j] = max(lis(i - 1, j), lis(i, j - 1));
        }
    }
    return dp[i][j];
}

int main(){
    //freopen("input.txt", "r", stdin);

    int t;
    scanf("%d%*c%*c", &t);

    for(int tt = 0; tt < t; tt++){
        char str[32];
        int code = scanf("%[^\n]%*c", str);
        while(code != EOF && code != 0){
            int x;
            sscanf(str, "%d", &x);
            v1.pb(x);
            code = scanf("%[^\n]%*c", str);
        };
        scanf("%*c");

        for(int i = 0; i < v1.size(); i++){
            v2.pb(v1[i]);
        }
        sort(v2.begin(), v2.end());

        int n = v1.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = UNDEF;
            }
        }
        printf("Max hits: %d\n", lis(n - 1, n - 1));
        printlis(n - 1, n - 1);

        printf("%s", (tt == t - 1) ? "": "\n");

        v1.clear();
        v2.clear();
    }

    return 0;
}
