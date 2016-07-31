#include <bits/stdc++.h>

using namespace std;

// modulus 7 starts with Monday
long long JDN(int day, int month, int year){
    long long a = (14 - month) / 12;
    long long y = year + 4800 - a;
    long long m = month + 12 * a - 3;
    return day + ( (153 * m + 2)/5 )+ 365 * y + (y/4) - (y/100) + (y/400) - 32045;
}

int main(){
    int cDays = 0;

    for(int y = 1901; y <= 2000; y++){
        for(int m = 1; m <= 12; m++){
            if(JDN(1,m,y) % 7 == 6){
                cDays++;
            }
        }
    }
    printf("%d",cDays);
    return 0;
}
