#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore(1);
    map<string, int> m;
    for(int i = 0; i < n; i++){
        string line;
        getline(cin, line);
        stringstream stream(line);
        string country;
        stream >> country;
        m[country]++;
    }
    for(typeof(m.begin()) iter = m.begin(); iter != m.end(); iter++){
        cout << iter->first << ' ' << iter->second << endl;
    }
    return 0;
}
