/*
 * Project Euler 005 - Smallest multiple
 *
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

#include <bits/stdc++.h>

using namespace std;

int mcd(int a, int b) {
   int iaux, i1, i2;
   i1 = max(a,b);
   i2 = min(a,b);
   do{
      iaux = i2;
      i2 = i1 % i2;
      i1 = iaux;
   } while (i2 != 0);
   return i1;
}

int mcm(int a, int b){
    return a * b / mcd(a,b);
}

int main(){
    int p = 1;
    for(int i = 2; i <= 20; i++){
        p = mcm(p,i);
    }
    printf("%d", p);
    return 0;
}
