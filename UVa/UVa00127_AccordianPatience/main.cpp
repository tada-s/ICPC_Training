#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair
#define pb push_back

vector< stack< pair<char, char> > > v;

bool match(int a, int b){
    if(a >= 0 && b >= 0){
        pair<char, char> p1 = v[a].top();
        pair<char, char> p2 = v[b].top();
        return (p1.first == p2.first) || (p1.second == p2.second);
    }
    return false;
}

bool isempty(int a){
    return v[a].empty();
}

void erase(int a){
    v.erase(v.begin() + a);
}

void move(int a, int b){
    v[b].push(v[a].top());
    v[a].pop();
}

void play(){
    int head = 0;
    while(head < v.size()){
        if(match(head, head - 3)){
            move(head, head - 3);
            if(isempty(head)){
                erase(head);
            }
            head -= 3;
        }else if(match(head, head - 1)){
            move(head, head - 1);
            if(isempty(head)){
                erase(head);
            }
            head -= 1;
        }else{
            head++;
        }
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    char str[3];
    scanf("%s", str);
    while(str[0] != '#'){
        v.clear();
        stack< pair<char, char> > s;
        s.push(mkp(str[0], str[1]));
        v.pb(s);
        s.pop();
        for(int i = 1; i < 52; i++){
            scanf("%s", str);
            s.push(mkp(str[0], str[1]));
            v.pb(s);
            s.pop();
        }

        play();

        if(v.size() == 1){
            printf("1 pile remaining: 52\n");
        }else{
            printf("%d piles remaining:", v.size());
            for(int i = 0; i < v.size(); i++){
                printf(" %d", v[i].size());
            }
            printf("\n");
        }
        scanf("%s", str);
    }

    return 0;
}
