#include <stdio.h>
int main()
{
    int n;
    int m;
    scanf("%d",&m);
    for(int i = 0; i < m; i++){
        scanf("%d",&n);
        n = (int)((n * 567 / 9 + 7492 )*235/47-498);
        n = (n %100 - n % 10)/10;
        if(n < 0) n = -n;
        printf("%d\n",n);
    }
    return 0;
}
