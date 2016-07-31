#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mkp make_pair

int main(){
    int t;
    scanf("%d", &t);
    cin.ignore();
    for(int tt = 0; tt < t; tt++){
        cin.ignore();
        vector<pair<int, int> > p;
        vector<string> v;

        string input;
        getline(cin, input);
        stringstream stream(input);
        int x;
        int i = 1;
        while(stream >> x){
            p.pb(mkp(x, i));
            i++;
        }
        sort(p.begin(), p.end());

        getline(cin, input);
        stringstream stream2(input);
        string y;\
        while(stream2 >> y){
            v.pb(y);
        }
        for(int i = 0; i < p.size(); i++){
            cout << v[p[i].second - 1] << endl;
        }
        if(tt != t - 1){
            cout << endl;
        }
    }
    return 0;
}
