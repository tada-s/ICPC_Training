#include <bits/stdc++.h>

using namespace std;

int letterN(int n){
    if(n < 10)
        switch(n){
            case 1: return 3;
            case 2: return 3;
            case 3: return 5;
            case 4: return 4;
            case 5: return 4;
            case 6: return 3;
            case 7: return 5;
            case 8: return 5;
            case 9: return 4;
            default: return 0;
        }
    else if (n == 10) return 3;
    else if(n == 11) return 6;
    else if(n == 12) return 6;
    else if(n == 13) return 8;
    else if(n == 14) return 8;
    else if(n == 15) return 7;
    else if(n == 16) return 7;
    else if(n == 17) return 9;
    else if(n == 18) return 8;
    else if(n == 19) return 8;
    else if(n < 30) return 6 + letterN(n%10);
    else if(n < 40) return 6 + letterN(n%10);
    else if(n < 50) return 5 + letterN(n%10);
    else if(n < 60) return 5 + letterN(n%10);
    else if(n < 70) return 5 + letterN(n%10);
    else if(n < 80) return 7 + letterN(n%10);
    else if(n < 90) return 6 + letterN(n%10);
    else if(n < 100) return 6 + letterN(n%10);
    else if(n == 1000) return 3 + 8;
    else if(n % 100 == 0) return letterN(n/100) + 7;
    else if(n < 1000) return letterN(n/100) + 7 + 3 + letterN(n%100);
    return 0;
}

int main(){
    int sum = 0;
    for(int i = 0; i <= 1000; i++){
        sum += letterN(i);
    }
    printf("%d",sum);
    return 0;
}

