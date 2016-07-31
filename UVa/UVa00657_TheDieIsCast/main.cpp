#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
#define pb push_back

int m[50][50];
int w, h;
vi v;
#define VISITED '-'

int ix[] = {1, 0, -1, 0};
int iy[] = {0, 1, 0, -1};

int isInBound(int i, int j){
    if(!(0 <= i && i <= h - 1)) return false;
    if(!(0 <= j && j <= w - 1)) return false;
    return true;
}

void fillDot(int i, int j){
    m[i][j] = VISITED;
    for(int k = 0; k < 4; k++){
        int x = ix[k] + i;
        int y = iy[k] + j;
        if( isInBound(x, y) ){
            if(m[x][y] == 'X'){
                fillDot(x, y);
            }
        }
    }
}

int getDotNumber(int i, int j){
    int n = 0;
    m[i][j] = VISITED;
    for(int k = 0; k < 4; k++){
        int x = ix[k] + i;
        int y = iy[k] + j;
        if( isInBound(x, y) ){
            if(m[x][y] == '*'){
                n += getDotNumber(x, y);
            }else if(m[x][y] == 'X'){
                fillDot(x, y);
                n++;
            }
        }
    }
    return n;
}

int main(){
    int t = 0;
    scanf("%d %d%*c", &w, &h);
    while(! (w == 0 && h == 0)){
        v.clear();
        t++;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                char x;
                scanf("%c", &x);
                m[i][j] = x;
            }
            scanf("%*c");
        }

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(m[i][j] == '*'){
                    int n = getDotNumber(i, j);
                    v.pb(n);
                }
            }
        }
        sort(v.begin(), v.end());

        printf("Throw %d\n", t);
        printf("%d", v[0]);
        for(int i = 1; i < v.size(); i++){
            printf(" %d", v[i]);
        }
        printf("\n\n");
        scanf("%d %d%*c", &w, &h);
    }
    return 0;
}
