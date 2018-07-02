#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int sign(int n){
    return (n > 0) - (n < 0);
}

void kingsp(ii s, ii t){
    int dx = t.first - s.first;
    int dy = t.second - s.second;
    printf("%d\n", max(abs(dx), abs(dy)) );
    if( !(abs(dx) == abs(dy)) ){
        int delta = abs(dx) - abs(dy);
        if(delta > 0){
            if(dx > 0){
                s.first += delta;
                for(int i = 0; i < delta; i++){
                    printf("R\n");
                }
            }else{
                s.first -= delta;
                for(int i = 0; i < delta; i++){
                    printf("L\n");
                }
            }
        }else{
            if(dy > 0){
                s.second -= delta;
                for(int i = 0; i < -delta; i++){
                    printf("U\n");
                }
            }else{
                s.second += delta;
                for(int i = 0; i < -delta; i++){
                    printf("D\n");
                }
            }
        }
    }
    dx = t.first - s.first;
    dy = t.second - s.second;
    if(dx != 0){
        if(dx > 0){
            if(dy > 0){
                for(int i = 0; i < dx; i++){
                    printf("RU\n");
                }
            }else{
                for(int i = 0; i < dx; i++){
                    printf("RD\n");
                }
            }
        }else{
            if(dy > 0){
                for(int i = 0; i < -dx; i++){
                    printf("LU\n");
                }
            }else{
                for(int i = 0; i < -dx; i++){
                    printf("LD\n");
                }
            }
        }
    }
}

int main(){
    char str[3];
    ii s, t;
    scanf("%s",str);
    s.first = str[0] - 'a';
    s.second = str[1] - '0';
    scanf("%s",str);
    t.first = str[0] - 'a';
    t.second = str[1] - '0';
    kingsp(s,t);
    return 0;
}
