#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2){
    if(p1.first.first != p2.first.first){
        return p1.first.first > p2.first.first;
    }
    if(p1.first.second != p2.first.second){
        return p1.first.second < p2.first.second;
    }
    if(p1.second != p2.second){
        return p1.second < p2.second;
    }
    return true;
}

int main(){
    //freopen("input.txt", "r", stdin);
    bool solved[100 + 1][10];
    int penalty[100 + 1][10];
    vector<pair<pair<int, int>, int> > contestant(100 + 1);
    bool submitted[100 + 1];

    int n;
    scanf("%d%*c%*c", &n);
    for(int nn = 0; nn < n; nn++){
        for(int i = 0; i <= 100; i++){
            contestant[i].first.first = 0;
            contestant[i].first.second = 0;
            contestant[i].second = i;
            submitted[i] = false;
            for(int j = 0 ; j < 10; j++){
                solved[i][j] = false;
                penalty[i][j] = 0;
            }
        }


        char str[128];
        scanf("%[^\n]%*c", str);
        while(strlen(str) != 0){
            int c, p, t;
            char l;
            sscanf(str, "%d %d %d %c", &c, &p, &t, &l);
            if(!solved[c][p]){
                if(l == 'I'){
                    penalty[c][p] += 20;
                }else if(l == 'C'){
                    solved[c][p] = true;
                    penalty[c][p] += t;
                    contestant[c].first.first++;
                    contestant[c].first.second += penalty[c][p];
                }
            }
            submitted[c] = true;

            str[0] = '\0';
            scanf("%[^\n]%*c", str);
        }
        scanf("%*c");
        sort(contestant.begin(), contestant.end(), cmp);

        for(int i = 0; i < contestant.size(); i++){
            if(submitted[contestant[i].second]){
                printf("%d %d %d\n", contestant[i].second, contestant[i].first.first, contestant[i].first.second);
            }
        }

        if(nn != n - 1){
            printf("\n");
        }
    }
    return 0;
}
