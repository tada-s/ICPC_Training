#include <iostream>
#include <stdio.h>
#include <strings.h>

using namespace std;

class Arr{
public:
    char name[12];
    int b;
    int d;
    int l[12];
    int u[12];
    int c[12];
};

char s[128];
Arr a[128];
int b;
int n, r;
Arr auxA;


Arr getArray(char* name){

    for(int i = 0; i < 128; i++){
        if(!strcmp(a[i].name,name)){
            return a[i];
        }
    }
}

int main()
{

    freopen("input.txt","r",stdin);

    scanf("%d%d",&n,&r);


    for(int i = 0; i < n; i++){
        scanf("%s%d%d%d",
              &a[i].name,
              &a[i].b,
              &b,
              &a[i].d);
        a[i].c[ a[i].d ] = b;
        for(int j = 1; j <= a[i].d; j++){
            scanf("%d%d",&a[i].l[j],&a[i].u[j]);
        }
        for(int j = a[i].d - 1; j > 0; j--){
            a[i].c[j] = a[i].c[j+1] * (a[i].u[j+1]-a[i].l[j+1] + 1);
            a[i].c[0] -= a[i].c[j] * a[i].l[j];
        }
        a[i].c[0] = a[i].b + a[i].c[0] - a[i].c[ a[i].d ] * a[i].l[ a[i].d ];
    }


    int dir;
    int k[12];
    for(int i = 0; i < r; i++){
        scanf("%s",s);
        auxA = getArray(s);
        dir = auxA.c[0];
        for(int j = 1; j <= auxA.d; j++){
            scanf("%d",&k[j]);
            dir = dir + auxA.c[j] * k[j];
        }
        printf("%s[%d",auxA.name,k[1]);
        for(int j = 2; j <= auxA.d; j++){
            printf(", %d",k[j]);
        }
        printf("] = %d\n",dir);
    }


    return 0;
}

