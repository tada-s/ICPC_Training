#include <bits/stdc++.h>

using namespace std;

int mcd(int n1, int n2){
    while(n2 != 0){
        n1 = n1 % n2;
        swap(n1, n2);
    }
    return n1;
}

int main(){
    int fn = 1, fd = 1;

    for(int a1 = 1; a1 <= 9; a1++){
        for(int a2 = 1; a2 <= 9; a2++){
            for(int b1 = 1; b1 <= 9; b1++){
                for(int b2 = 1; b2 <= 9; b2++){
                    if(10*a1 + a2 < 10*b1 + b2 && (a2 == b1)){
                        double d = (10*a1 + a2) / (double)(10*b1 + b2);
                        double eps = 1e-5;
                        if(abs(d - a1 / (double)b2) < eps || abs(d - a2 / (double)b1) < eps){
                            fn *= 10*a1 + a2;
                            fd *= 10*b1 + b2;
                        }
                    }
                }
            }
        }
    }
    printf("%d", fd / mcd(fn, fd));
    return 0;
}
