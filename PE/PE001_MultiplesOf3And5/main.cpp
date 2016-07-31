/*
 * Project Euler 001 - Multiples of 3 and 5
 *
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include <bits/stdc++.h>

using namespace std;

#define upperBound 1000

bitset<upperBound> bs;

int main(){
    bs.reset();
    for(int i = 3; i < upperBound; i+=3){
        bs.set(i,true);
    }
    for(int i = 5; i < upperBound; i+=5){
        bs.set(i,true);
    }
    int sum = 0;
    for(int i = 1; i < upperBound; i++){
        if(bs.test(i) == true){
            sum += i;
        }
    }
    printf("%d",sum);
    return 0;
}
