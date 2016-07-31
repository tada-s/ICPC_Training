#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int minD(string s){
    int minD = 9999;
    for(int i = 0; i < s.size() - 1; i++){
        minD = min(minD, abs(s[i] - s[i+1]));
    }
    return minD;
}

int main(){
    string s;
    while(cin >> s){
        for(int i = 0; i < 10; i++){
            prev_permutation(s.begin(), s.end());
        }

        int maxD = 0;
        string candidateS;
        for(int i = 0; i < 21; i++){
            int d = minD(s);
            if(d > maxD){
                maxD = d;
                candidateS = s;
            }
            next_permutation(s.begin(), s.end());
        }

        cout << candidateS << maxD << endl;
    }
    return 0;
}
