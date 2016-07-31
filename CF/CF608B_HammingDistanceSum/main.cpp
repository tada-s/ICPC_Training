#include <bits/stdc++.h>

using namespace std;

int ones[200000 + 1];
int zeros[200000 + 1];

int one(int i, int j){
    if(j - 1 < 0){
        return ones[i];
    }
    return ones[i] - ones[j - 1];
}

int zero(int i, int j){
    if(j - 1 < 0){
        return zeros[i];
    }
    return zeros[i] - zeros[j - 1];
}

int main(){
    char str1[200000 + 2];
    char str2[200000 + 2];
    scanf("%s %s", str1, str2);

    if(strlen(str1) > strlen(str2)){
        swap(str1, str2);
    }

    int l1 = strlen(str1);
    int l2 = strlen(str2);

    ones[0] = str2[0] - '0';
    zeros[0] = '1' - str2[0];
    for(int i = 1; i < l2; i++){
        ones[i] = ones[i - 1] + (str2[i] - '0');
        zeros[i] = zeros[i - 1] + ('1' - str2[i]);
    }


    long long sum = 0;
    for(int i = 0; i < l1; i++){
        if(str1[i] == '1'){
            sum += zero(l2 - l1 + i, i);
        }else{
            sum += one(l2 - l1 + i, i);
        }
    }
    cout << sum << endl;
    return 0;
}
