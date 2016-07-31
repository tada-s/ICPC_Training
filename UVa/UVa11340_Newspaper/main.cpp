#include <bits/stdc++.h>

using namespace std;

#define CHARVECTOR (1 << (8 * sizeof(char)))

int main(){
    //freopen("input.txt", "r", stdin);
    int charvalue[CHARVECTOR];
    int n, k, m;

    cin >> n;
cin.ignore();
    for(int nn = 0; nn < n; nn++){

        for(int i = 0; i < CHARVECTOR; i++){
            charvalue[i] = 0;
        }

        cin >> k;
cin.ignore();
        for(int i = 0; i < k; i++){
            char c;
            int v;
            cin >> c >> v;
cin.ignore();
            charvalue[c] = v;
        }

        unsigned long long total = 0;
        cin >> m;
        cin.ignore();
        for(int i = 0; i < m; i++){
char c;
while ((c = cin.get()) != '\n') {
    total += charvalue[c];
}
/*            string str;
            getline(cin, str);
            for(int j = 0; j < str.length(); j++){
                total += charvalue[(int) str[j]];
            }*/
        }

        printf("%.2lf$\n", total / 100.0);
        //cout << total / 100 << '.' << setfill('0') << setw(2) << total % 100 << '$' << endl;

    }
    return 0;
}
