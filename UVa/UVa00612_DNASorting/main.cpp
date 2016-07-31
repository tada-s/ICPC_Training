#include <bits/stdc++.h>

using namespace std;

int inversion(string str){
    int m = 0;
    for(int i = 0; i < str.length(); i++){
        for(int j = i + 1; j < str.length(); j++){
            if(str[i] > str[j]){
                m++;
            }
        }
    }
    return m;
}

int cmp(string str1, string str2){
    return inversion(str1) < inversion(str2);
}

int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    for(int tt = 0; tt < t; tt++){
        int n, m;
        cin >> n >> m;
        string mat[100];
        for(int i = 0; i < m; i++){
            cin >> mat[i];
        }
        stable_sort(mat, mat + m, cmp);
        for(int i = 0; i < m; i++){
            cout << mat[i] << endl;
        }
        if(tt < t - 1) cout << endl;
    }
}
