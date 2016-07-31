#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair
#define pb push_back

vector< pair<string, pair<int, int> > > v;
vector<string> attacker(5);
list<int> li;

int maxAS, maxDS;

void take(int i, int m){
    if(m == 0){
        vector<int> v2(li.begin(), li.end());
        //copy(li.begin(), li.end(), back_inserter(v2));
        #define DEFENCE = 1
        #define ATACKER = 2
        int aS = 0;
        int dS = 0;
        for(int i = 0; i < 10; i++){
            dS += v[i].second.second;
        }
        for(int i = 0; i < 5; i++){
            aS += v[v2[i]].second.first;
            dS -= v[v2[i]].second.second;
        }
        if(aS > maxAS){
            maxAS = aS;
            maxDS = dS;
            for(int i = 0; i < 5; i++){
                attacker[i] = v[v2[i]].first;
            }
        }else if(aS == maxAS && dS > maxDS){
            maxDS = dS;
            for(int i = 0; i < 5; i++){
                attacker[i] = v[v2[i]].first;
            }
        }
    }else{
        for(int j = i; j <= 10 - m; j++){
            li.push_front(j);
            take(j + 1, m - 1);
            li.pop_front();
        }
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    int caseN = 1;
    int t;
    scanf("%d", &t);
    for(int tt = 0; tt < t; tt++){
        maxAS = 0;
        maxDS = 0;
        for(int i = 0; i < 10; i++){
            char str[20 + 1];
            int a, d;
            scanf("%s%d%d", str, &a, &d);
            v.pb(mkp(str, mkp(a, d)));
        }

        sort(v.begin(), v.end());

        take(0, 5);

        vector<string> defence;
        for(int i = 0; i < 10; i++){
            bool exist = false;
            for(int j = 0; j < 5; j++){
                if(v[i].first == attacker[j]){
                    exist = true;
                    break;
                }
            }
            if(!exist){
                defence.pb(v[i].first);
            }
        }
        sort(attacker.begin(), attacker.end());
        sort(defence.begin(), defence.end());

        printf("Case %d:\n", caseN++);
        printf("(%s", attacker[0].c_str());
        for(int i = 1; i < 5; i++){
            printf(", %s", attacker[i].c_str());
        }
        printf(")\n(%s", defence[0].c_str());
        for(int i = 1; i < 5; i++){
            printf(", %s", defence[i].c_str());
        }
        printf(")\n");

        v.clear();
    }
    return 0;
}
