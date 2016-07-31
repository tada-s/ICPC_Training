/*
 * Project Euler 006 - Sum square difference
 *
 * The sum of the squares of the first ten natural numbers is,
 *     1^2 + 2^2 + ... + 10^2 = 385
 * The square of the sum of the first ten natural numbers is,
 *     (1 + 2 + ... + 10) ^ 2 = 55 ^ 2 = 3025
 * Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 100;
    printf("%d", n * (n+1) * (3*n+2) * (n-1) / 12);
    return 0;
}
