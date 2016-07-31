#include <bits/stdc++.h>

using namespace std;

int getUpperBound(){
    //Finding zero with Newton method
    double x = 100;
    double lx = 0;
    while(abs(x-lx) > 1e-5){
        lx = x;
        x = x - ( pow(10,x) - pow(9,5) * x ) / ( pow(10,x)*log(10)/log(2.718281828) - pow(9,5) );
    }
    return (int)pow(10,ceil(x));

}

int f(int i){
    int sum = 0;
    while(i != 0){
        sum += (int)pow( (i%10), 5 );
        i = i / 10;
    }
    return sum;
}

int main(){
    int upperBound = getUpperBound();
    int sum = 0;

    for(int i = 2; i < upperBound; i++){
        if(i == f(i)){
            sum += i;
        }
    }

    printf("%d",sum);

    return 0;
}
