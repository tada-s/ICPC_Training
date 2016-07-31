#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int c;
    int n,m;
    scanf("%d",&c);
    for(int i = 0; i < c; i++){
        scanf("%d%d",&n,&m);
        printf("%d\n",((int)ceil(n/3))*((int)ceil(m/3)));
    }
    return 0;
}
