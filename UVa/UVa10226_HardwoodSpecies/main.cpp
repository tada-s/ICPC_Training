#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();
    for(int tt = 0; tt < t; tt++){
        map<string, int> m;
        int total = 0;

        string str;
        getline(cin, str);
        while(str.length() != 0){
            m[str]++;
            total++;
            getline(cin, str);
        }

        for(__typeof(m.begin()) iter = m.begin(); iter != m.end(); iter++){
            cout << iter->first << ' ' << fixed << setprecision(4) << (iter->second * 100) / ((double) total) << endl;
        }

        if(tt != t - 1){
            cout << endl;
        }
    }
    return 0;
}
