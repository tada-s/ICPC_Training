#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mkp make_pair

int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    cin.ignore();
    for(int tt = 0; tt < t; tt++){
        string title;
        getline(cin, title);

        map<string, long long> ingredient;

        long long m, n, b;
        cin >> m >> n >> b;
        for(int i = 0; i < m; i++){
            string name;
            long long price;
            cin >> name >> price;
            ingredient[name] = price;
        }
        cin.ignore();

        vector< pair<int, string> > v;
        for(int i = 0; i < n; i++){
            string recipename;
            getline(cin, recipename);
//cout << "recipe: " << recipename << endl;
            long long price = 0;
            int k;
            cin >> k;
            for(int i = 0; i < k; i++){
                string name;
                int q;
                cin >> name >> q;
                price += ingredient[name] * q;
            }
            if(price <= b){
                v.pb(mkp(price, recipename));
            }
            cin.ignore();
        }

        transform(title.begin(), title.end(), title.begin(), ::toupper);
        cout << title << endl;
        sort(v.begin(), v.end());
        if(!v.empty()){
            for(int i = 0; i < v.size(); i++){
                cout << v[i].second << endl;
            }
        }else{
            cout << "Too expensive!" << endl;
        }
        cout << endl;
    }
    return 0;
}
