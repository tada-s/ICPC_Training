#include <bits/stdc++.h>

using namespace std;

#define EMPTY 1<<30
#define INF ((ll)1)<<60
typedef long long ll;
ll dpMax[15][15];
ll dpMin[15][15];
char op[15];
ll v[15];

ll operate(ll n1, ll n2, int i){
    if(op[i] == '+'){
        return n1 + n2;
    }else{
        return n1 * n2;
    }
}

ll getMax(int i, int j){
    if(dpMax[i][j] == EMPTY){
        if(i == j){
            dpMax[i][j] = v[i];
        }else{
            ll m = 0;
            for(int k = i; k < j; k++){
                m = max(m, operate(getMax(i, k), getMax(k + 1, j), k));
            }
            dpMax[i][j] = m;
        }
    }
    return dpMax[i][j];
}

ll getMin(int i, int j){
    if(dpMin[i][j] == EMPTY){
        if(i == j){
            dpMin[i][j] = v[i];
        }else{
            ll m = INF;
            for(int k = i; k < j; k++){
                m = min(m, operate(getMin(i, k), getMin(k + 1, j), k));
            }
            dpMin[i][j] = m;
        }
    }
    return dpMin[i][j];
}

int read(){
    char str[128];
    scanf("%[^\n]%*c", str);
    char* straux = str;
    int x, c;
    int delta;

    int i = 0;
    while(sscanf(straux, "%d%c%n", &x, &c, &delta) == 2){
        straux += delta;
        v[i] = x;
        op[i] = c;
        i++;
    }
    v[i] = x;
    i++;

    return i;
}

int main(){
    int n;
    scanf("%d%*c", &n);
    for(int nn = 0; nn < n; nn++){
        int length = read();
        for(int i = 0; i < length; i++){
            for(int j = 0; j < length; j++){
                dpMax[i][j] = EMPTY;
                dpMin[i][j] = EMPTY;
            }
        }
        printf("The maximum and minimum are %ld and %ld.\n", getMax(0, length - 1), getMin(0, length - 1));
    }
    return 0;
}
