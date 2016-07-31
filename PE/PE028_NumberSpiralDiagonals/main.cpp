#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(int n){
    if(n % 2 == 0){
        ll sum = 0;
        for(int i = 0; i < n/2; i++){
            sum += (2*i+1) * 10 + i*i * 16;
        }
        return sum;
    }else{
        ll sum = 1;
        for(int i = 0; i < (n-1)/2; i++){
            sum += (2*i+1)*(2*i+1)*4 + (2*i + 2) * 10;
        }
        return sum;
    }
}


int main(){

    printf("%I64d\n",f(1001));

    return 0;
}
