#include <stdio.h>

using namespace std;

bool isDigitRep(int n){
    char str[5];
    sprintf(str, "%d", n);
    int digit[10];
    for(int i = 0; i < 10; i++){
        digit[i] = 0;
    }
    for(int i = 0; str[i] != '\0' ; i++){
        digit[ str[i] - '0' ]++;
    }
    for(int i = 0; i < 10; i++){
        if(digit[i] > 1) return true;
    }
    return false;
}

int main(){
    int v[5000+1];
    v[0] = 0;
    for(int i = 1; i <= 5000; i++){
        if(!isDigitRep(i)){
            v[i] = v[i-1] + 1;
        }else{
            v[i] = v[i-1];
        }
    }

    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        printf("%d\n", v[m] - v[n-1]);
    }

    return 0;
}
