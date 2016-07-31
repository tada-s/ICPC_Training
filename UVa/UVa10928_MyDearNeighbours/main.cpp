#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF (1 << 29)

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for(int nn = 0; nn < n; nn++){
        int p;
        cin >> p;
        cin.ignore();
        vector<int> v;
        int minC = INF;
        for(int i = 1; i <= p; i++){
            string input;
            getline(cin, input);
            stringstream stream(input);

            int x;
            int c = 0;
            while(stream >> x){
                c++;
            }
            if(c < minC){
                minC = c;
                v.clear();
                v.pb(i);
            }else if(c == minC){
                v.pb(i);
            }
        }
        cin.ignore();

        cout << v[0];
        for(int i = 1; i < v.size(); i++){
            cout << ' ' << v[i];
        }
        cout << endl;
    }



    return 0;
}
