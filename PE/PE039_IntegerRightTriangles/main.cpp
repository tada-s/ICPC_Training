#include <bits/stdc++.h>

using namespace std;

bool isPitagorean(int a, int b, int c){
    return a*a + b*b == c*c;
}

int f(int p){
    int n = 0;
    for(int a = 1; a <= p - 2; a++){
        for(int b = a + 1; b <= p - a - 1; b++){
            int c = p - a - b;
            if(a < b && b < c){
                if(isPitagorean(a,b,c)){
                    n++;
                }
            }else{
            	break;
            }
        }
    }
    return n;
}


int main(){
    int maxN = 0;
    int maxI = 0;
    for(int i = 3; i <= 1000; i++){
    int n = f(i);
        if(n > maxN){
            maxN = n;
            maxI = i;
        }
    }
    printf("%d",maxI);
    return 0;
}
