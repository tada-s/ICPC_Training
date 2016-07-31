/*
 * Project Euler 004 - Largest palindrome product
 *
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(long long n){
    int digit[32];
    int i = 0;
    while(n != 0){
        digit[i++] = n % 10;
        n = (n - n % 10) / 10;
    }
    for(int j = 0; j < i/2; j++){
        if(digit[j] != digit[i-j-1]){
            return false;
        }
    }
    return true;
}

typedef struct{
    int a;
    int b;
    int c;
} triple;

bool tripleCMP(triple t1, triple t2){
    return t1.a > t2.a;
}

int main(){/*
    int n1, n2;
    n1 = 999;
    for(n1 = 999; n1 > 0; n1--){
        for(n2 = 999; n2 >= n1; n2--){
            if(isPalindrome(n1*n2))
        }
    }*/

    vector<triple> v;
    for(int i = 999; i > 800; i--){
        for(int j = 999; j >= i; j--){
            triple t;
            t.a = i*j;
            t.b = i;
            t.c = j;
            v.push_back(t);
        }
    }

    sort(v.begin(), v.end(), tripleCMP);
    //FILE* f = freopen("output.txt","w",stdout);
    for(int i = 0; i < v.size(); i++){
        printf("%d %d %d\n",v[i].a,v[i].b,v[i].c);
        /*if(isPalindrome(v[i].a)) {
            printf("Is palindrome!!");
            break;
        }*/
    }
    //fclose(f);
}
