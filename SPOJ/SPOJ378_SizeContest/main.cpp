#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    long long s = 0;
    scanf("%d",&t);
    for(int i = 0; i < t; i++){
       scanf("%d",&n);
       if(n > 0) s += n;
    }
    printf("%d",s);
    return 0;
}
