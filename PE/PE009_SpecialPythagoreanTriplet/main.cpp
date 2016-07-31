/*
 * Project Euler 009 - Special Pythagorean Triplet
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 *      a2 + b2 = c2
 * For example, 32 + 42 = 9 + 16 = 25 = 52.
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

 #include <bits/stdc++.h>

 using namespace std;

 int main(){
    int a, b, c;
    for(b = 1; b < 500; b++){
        a = (1000000 - 2000 * b)/(2000 - 2 * b);
        c = (1000 - a - b);
        if(a*a + b*b == c*c){
            break;
        }
    }
    printf("%d", a * b * c);
    return 0;
 }
