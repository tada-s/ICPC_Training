#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>
#define mkp make_pair
#define rep(c,n) for(__typeof(n) c = 0; c < n; c++)
#define INF 1<<29

int tower[110];
int iMin, iMax;
int n, k, a;

stack<ii> st;

void findMinMax(){
    iMin = 0;
    iMax = 0;
    rep(c,n){
        if(tower[c] < tower[iMin]) iMin = c;
        if(tower[c] > tower[iMax]) iMax = c;
    }
}

void moveT(){
    int cS,d;
    int s = 0;
    rep(c,n){
        s += tower[c];
    }
    cS = s / n;
    d = ((s%n)==0 ? 0 : 1);
    rep(c,k){
        findMinMax();

        if(tower[iMin] == cS && tower[iMax] == cS + d) break;

        tower[iMin]++;
        tower[iMax]--;
        st.push(mkp(iMax, iMin));
    }
}

void print(){
    ii aux;
    findMinMax();
    printf("%d %d\n", tower[iMax] - tower[iMin], st.size());
    while(!st.empty()){
        aux = st.top();
        st.pop();
        printf("%d %d\n", aux.first + 1, aux.second + 1);
    }


}

int main(){
    scanf("%d %d", &n, &k);
    rep(c,n){
        scanf("%d",&a);
        tower[c] = a;
    }

    moveT();

    print();

    return 0;
}
