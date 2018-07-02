#include <bits/stdc++.h>


int main(){
    //freopen("input.txt","r",stdin);
    int n;
    char s[128];
    scanf("%d",&n);
    getchar();
    for(int nn = 0; nn < n; nn++){
        gets(s);
        int numSystem = 2;
        int l = strlen(s);
        if(s[0] == 'R' && isdigit(s[1])){
            for(int i = 2; i < l; i++){
                if(s[i] == 'C' && isdigit(s[i+1])){
                    numSystem = 1;
                    break;
                }
            }
        }
        switch(numSystem){
            case 1:
                {
                    char outstr[128];
                    int i;
                    int num1 = 0, num2 = 0;
                    sscanf(s,"R%dC%d",&num1,&num2);
                    i = 0;
                    while(num2 != 0){
                        outstr[i] = (num2-1)%26 + 'A' ;
                        num2 = (num2 - (num2-1)%26)/26;
                        i++;
                    }
                    outstr[i] = '\0';
                    strrev(outstr);
                    printf("%s%d\n",outstr,num1);
                }
                break;
            case 2:
                {
                    int i = 0;
                    int num1 = 0, num2 = 0;
                    while(isalpha(s[i])){
                        num2 = num2 * 26 + (s[i] - 'A' + 1);
                        i++;
                    }
                    sscanf(&s[i],"%d",&num1);
                    printf("R%dC%d\n",num1,num2);
                }
                break;
        }
    }


    return 0;
}
