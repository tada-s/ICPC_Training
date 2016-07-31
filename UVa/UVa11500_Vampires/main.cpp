#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;

int c;
int s;

int randomWalk(int v1, int v2, int a, int d){
    while(v1 > 0 && v2 > 0){
        int r = rand()%6;
        if(r < a){
            v1 += d;
            v2 -= d;
        }else{
            v1 -= d;
            v2 += d;
        }
    }
    if(v1 > 0) return 1;
    else return 2;
}

int main(){
    int ev1, ev2, at, d;
    scanf("%d %d %d %d", &ev1, &ev2, &at, &d);
    while(!(ev1 == 0 && ev2 == 0 && at == 0 && d == 0)){
        int n = 1000000;
        int p = 0;
        for(int i = 0; i < n; i++){
            int r = randomWalk(ev1, ev2, at, d);
            if(r == 1) p++;
        }
        printf("%f\n",(float)100*p/n);
        scanf("%d %d %d %d", &ev1, &ev2, &at, &d);
    }
    return 0;
}
