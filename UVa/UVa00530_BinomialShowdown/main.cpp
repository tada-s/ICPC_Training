#include <cstdio>

using namespace std;

int binomial(int a, int b){
    long long p = 1;
    if (b > a/2) b = a - b;
    for(int i = 0; i < b; i++) p = p * (a-i) / (i+1);
    return p;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    while(!(a == 0 && b == 0)){
        printf("%d\n", binomial(a,b));
        scanf("%d %d", &a, &b);
    }
    return 0;
}
