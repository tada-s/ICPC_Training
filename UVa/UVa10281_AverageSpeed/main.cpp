#include <iostream>
#include <stdio.h>

using namespace std;

int hh=0,mm=0,ss=0;
long int vv;
//int vv; Works

int main()
{
    //freopen("input.txt","r",stdin);
    long long unsigned int t0 = 0, t1 = 0;
    //int t0 = 0, t1 = 0; Works
    double d = 0;
    long int v = 0;
    //int v = 0; Works
    char s[128];
    while(gets(s)){
        if(sscanf(s,"%d:%d:%d %ld",&hh,&mm,&ss,&vv) == 3){
            t1 = hh*3600 + mm*60 + ss;
            d = d + v*(t1-t0) / 3600.0;
            t0 = t1;
            printf("%02d:%02d:%02d %.2lf km\n",hh,mm,ss,d);
        }else{
            t1 = hh*3600 + mm*60 + ss;
            d = d + v*(t1-t0) / 3600.0;
            t0 = t1;
            v = vv;
        }
    }

    return 0;
}

