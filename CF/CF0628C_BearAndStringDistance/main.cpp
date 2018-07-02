#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    char str[100000 + 1];
    char str2[100000 + 1];
    scanf("%s", str);

    bool completed = false;
    strcpy(str2, str);
    for(int i = 0; i < n; i++){
        int delta = max(abs(str[i] - 'a'), abs(str[i] - 'z'));
        if(k > delta){
            k = k - delta;
            str2[i] = (abs(str[i] - 'a') < abs(str[i] - 'z')) ? 'z' : 'a';
        }else{
            char c1 = str[i] + k;
            char c2 = str[i] - k;
            if('a' <= c1 && c1 <= 'z'){
                str2[i] = c1;
            }else{
                str2[i] = c2;
            }
            completed = true;
            break;
        }
    }

    if(completed){
        printf("%s\n", str2);
    }else{
        printf("-1\n");
    }
    return 0;
}
