#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    char str1[1000000];
    char str2[1000000];
    while(scanf("%s%s", str1, str2) != EOF){
        int n1 = strlen(str1);
        int n2 = strlen(str2);
        int j = 0;
        bool matches = true;
        for(int i = 0; i < n1; i++){
            while(str1[i] != str2[j] && j < n2){
                j++;
            }
            if(str2[j] == '\0'){
                matches = false;
                break;
            }
            j++;
        }
        printf("%s\n", matches ? "Yes" : "No");
    }
    return 0;
}
