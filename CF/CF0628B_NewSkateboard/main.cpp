#include <bits/stdc++.h>

using namespace std;

#define num(x) ((x) - '0')

int main(){
    char str[300000 + 1];
    scanf("%s", str);
    int l = strlen(str);
    long long c = 0;
    for(int i = 1; i < l; i++){
        if((num(str[i - 1]) % 2 == 1) && (num(str[i]) % 4 == 2) ||
           (num(str[i - 1]) % 2 == 0) && (num(str[i]) % 4 == 0)){
            c += i;
        }
    }
    for(int i = 0; i < l; i++){
        if(num(str[i]) % 4 == 0){
            c++;
        }
    }
    cout << c << endl;
    return 0;
}
