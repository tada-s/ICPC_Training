#include <bits/stdc++.h>

using namespace std;

struct triple{
    int a,b,c;
};

typedef pair<int, int> ii;
#define mkp make_pair
#define rep(c,n) for(__typeof(n) c = 0; c < n; c++)
#define repstl(i,c) for(__typeof(c.begin()) i = c.begin(); i != c.end(); i++)

int main(){
    int n;
    priority_queue<ii> pR;
    map<int, int> mR;
    scanf("%d", &n);
    int rr;
    rep(c,n){
        scanf("%d", &rr);
        mR[rr]++;
    }

    repstl(iter,mR){
        pR.push(mkp(iter->second,iter->first));
    }

    stack<triple> outputS;
    int outputN = 0;
    bool again = true;

    while(again){
        ii p1, p2, p3;
        if(!pR.empty()){
            p1 = pR.top();
            pR.pop();
            if(!pR.empty()){
                p2 = pR.top();
                pR.pop();
                if(!pR.empty()){
                    p3 = pR.top();
                    pR.pop();

                    triple t;
                    t.a = p1.second;
                    t.b = p2.second;
                    t.c = p3.second;
                    outputS.push(t);
                    outputN++;
                    p1.first--;
                    p2.first--;
                    p3.first--;
                    if(p1.first > 0) pR.push(p1);
                    if(p2.first > 0) pR.push(p2);
                    if(p3.first > 0) pR.push(p3);

                }else{
                    again = false;
                }
            }else{
                again = false;
            }
        }else{
            again = false;
        }
    }

    printf("%d\n", outputN);
    for(int i = 0; i < outputN; i++){
        triple t = outputS.top();
        outputS.pop();
        if(t.a < t.b) swap(t.a,t.b);
        if(t.b < t.c) swap(t.b,t.c);
        if(t.a < t.b) swap(t.a,t.b);
        printf("%d %d %d\n", t.a, t.b, t.c);
    }

    return 0;
}
