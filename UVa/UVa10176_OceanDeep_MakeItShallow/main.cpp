/*#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    int m;
    char c;
    char s[110];
    int i;

    do{
        gets(s);
        i = 0;
        c = s[0];
        while( c != '#'){
            m = m<<2 | (c-'0');
            if(m >= 131071) m -= 131071;
            c = s[++i];
        }
        if(m==0) printf("YES\n");
        else printf("NO\n");
    }while(!feof(stdin));
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long n=131071,m;
    freopen("input.txt","r",stdin);
    char c;
    while(!feof(stdin)){
        m = 0;
        c=getchar();
        if(feof(stdin)) exit(0);
        while( c != '#'){
            m = (m << 1) + (c - '0');
            if(m >= n) m = m - n;
            c = getchar();
        }
        if(m==0) printf("YES\n");
        else printf("NO\n");
        getchar();
    }
    return 0;
}

