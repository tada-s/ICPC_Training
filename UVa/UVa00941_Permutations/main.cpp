#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long number;

number c['z' + 1];

void init(char str[]){

    for(int i = 'a'; i <= 'z'; i++){
        c[i] = 0;
    }
    int l = strlen(str);
    for(int i = 0; i < l; i++){
        c[ str[i] ]++;
    }
}

number factorial(number n){
    if(n == 0) return 1;
    number p = 1;
    for(int i = 1; i <= n; i++){
        p = p * i;
    }
    return p;
}

string getPermutation(char str[], number n){
    string permutation = "";
    int l = strlen(str);
    number totalp = factorial(l);
    for(int i = 'a'; i <= 'z'; i++){
        totalp = totalp / factorial(c[i]);
    }


    while(l != 0){
        /*printf("%d %d\n", totalp);
        for(int i = 'a'; i <= 'z'; i++){
            printf("[%c] = %d\n", i, c[i]);
        }
        getchar();*/
        number sum = 0;
        for(int i = 'a'; i <= 'z'; i++){
            number delta = (totalp * c[i] / l);
            if(sum + delta > n){
                permutation += i;
                totalp = (totalp * c[i] / l);
                n -= sum;
                sum = 0;
                c[i]--;
                l--;
                break;
            }else{
                sum += delta;
            }
        }
    }
    return permutation;
}

int main(){
    int s;
    scanf("%d", &s);
    for(int ss = 0; ss < s; ss++){
        char str[128];
        int n;
        scanf("%s %d", str, &n);


        /*for(int i = 1; i <= 20; i++){
            for(int j = 0; j < i; j++){
                str[j] = 'a' + j;
            }
            str[i] = '\0';
            init(str);
            printf("GetStarted with %s\n", str);
            string permutation = getPermutation(str, factorial(i) - 1);
            printf("%s\n", permutation.c_str());
        }*/

        init(str);
        string permutation = getPermutation(str, n);
        printf("%s\n", permutation.c_str());
    }
    return 0;
}
