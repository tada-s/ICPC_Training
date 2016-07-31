#include <bits/stdc++.h>

using namespace std;

class Team{
public:
    int a, b, c, d, e, f, g, h, i;
    string name;
    Team();
    bool operator<(const Team& r) const;
};

Team::Team(){
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    g = 0;
    h = 0;
    i = 0;
}

string strUpper(string str){
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

bool Team::operator<(const Team& r) const{
    if(b > r.b) return true;
    else if(b == r.b){
        if(d > r.d) return true;
        else if(d == r.d){
            if(g > r.g) return true;
            else if(g == r.g){
                if(h == r.h) return true;
                else if(h == r.h){
                    if(c < r.c) return true;
                    else if(c == r.c){
                        if(strUpper(name) < strUpper(r.name)) return true;
                    }
                }
            }
        }
    }
    return false;
}

int main(){

    //freopen("input.txt", "r", stdin);
    int n;
    scanf("%d%*c", &n);
    for(int nn = 0; nn < n; nn++){
        char tournamentname[100 + 1];
        scanf("%[^\n]%*c", tournamentname);

        map<string, int> m;
        int t;
        scanf("%d%*c", &t);
        vector<Team> teams(t);
        for(int i = 0; i < t; i++){
            char aux[30 + 1];
            scanf("%[^\n]%*c", aux);
            m[aux] = i;
            teams[i].name = aux;
        }

        int g;
        scanf("%d", &g);
        for(int i = 0; i < g; i++){
            char team1[30 + 1], team2[30 + 1];
            int goal1, goal2;
            scanf("%[^#]#%d@%d#%[^\n]%*c", team1, &goal1, &goal2, team2);

            int i1 = m[team1];
            int i2 = m[team2];

            if(goal1 == goal2){
                teams[i1].b += 1;
                teams[i2].b += 1;
                teams[i1].e++;
                teams[i2].e++;
            }else if(goal1 > goal2){
                teams[i1].b += 3;
                teams[i1].d++;
                teams[i2].f++;
            }else{
                teams[i2].b += 3;
                teams[i2].d++;
                teams[i1].f++;
            }

            teams[i1].c++;
            teams[i2].c++;

            teams[i1].g += goal1 - goal2;
            teams[i2].g += goal2 - goal1;

            teams[i1].h += goal1;
            teams[i2].h += goal2;

            teams[i1].i += goal2;
            teams[i2].i += goal1;
        }

        sort(teams.begin(), teams.end());

//printf("!");
        printf("%s\n", tournamentname);
        for(int i = 0; i < teams.size(); i++){
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i + 1, teams[i].name.c_str(), teams[i].b, teams[i].c, teams[i].d, teams[i].e, teams[i].f, teams[i].g, teams[i].h, teams[i].i);
        }
        if(nn != n - 1){
            printf("\n");
        }
    }
    return 0;
}

