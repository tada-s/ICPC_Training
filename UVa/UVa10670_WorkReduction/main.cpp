#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair
#define pb push_back

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    for(int tt = 1; tt <= t; tt++){
        int n, m, l;
        scanf("%d%d%d", &n, &m, &l);

        vector<pair<int, string> > cost;

        for(int i = 0; i < l; i++){
            char str[64];
            char name[64];
            int a, b;
            scanf("%s", str, &a, &b);

            strcpy(name, str);
            int j = 0;
            while(name[j] != ':'){
                j++;
            }
            name[j] = '\0';
            sscanf(str + j + 1, "%d,%d", &a, &b);
            //printf("[%s][%d][%d]", str + j, a, b);


            int x = n;
            int c = 0;
            while(b < (x - (x / 2)) * a && (x / 2) >= m){
                c += b;
                x /= 2;
            }
            c += (x - m) * a;

            cost.pb(mkp(c, string(name)));
        }

        sort(cost.begin(), cost.end());

        printf("Case %d\n", tt);
        for(int i = 0; i < cost.size(); i++){
            printf("%s %d\n", cost[i].second.c_str(), cost[i].first);
        }



    }
    return 0;
}
