#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    getline(cin, str);
    while(str[0] != '#'){
        string str2 = str;
        sort(str2.begin(), str2.end());
        next_permutation(str.begin(), str.end());
        if(str == str2){
            cout << "No Successor" << endl;
        }else{
            cout << str << endl;
        }
        getline(cin, str);
    }
    return 0;
}
