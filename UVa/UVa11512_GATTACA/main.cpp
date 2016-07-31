#include <bits/stdc++.h>

using namespace std;

string suffix[1000 + 1];

string common(string str1, string str2){
    int n = min(str1.length(), str2.length());
    int i;
    for(i = 0; i < n; i++){
        if(str1[i] != str2[i]){
            break;
        }
    }
    string str = str1;
    str.erase(i);
    return str;
}

void createSuffixArray(string str){
    int n = str.length();
    for(int i = 0; i < n; i++){
        suffix[i] = str;
        str.erase(0,1);
    }
    sort(suffix, suffix + n);
/*    for(int i = 0 ; i < n; i++){
        printf("%d: [%s]\n", i, suffix[i].c_str());
    }*/
}

void largestSubSequence(string str){
    createSuffixArray(str);
    int n = str.length();

    string strLargestCommon;
    int maxDeep = 0;
    for(int i = 0; i < n - 1; i++){
        string strCommon;
        strCommon = common(suffix[i], suffix[i+1]);
        int deep = strCommon.length();
/*printf("str: %s %s\n", suffix[i].c_str(), suffix[i+1].c_str());
printf("common: %d %s\n", deep, strCommon.c_str());
printf("maxDeep: %d\n", maxDeep);*/

        if(deep > maxDeep){
            maxDeep = deep;
            strLargestCommon = strCommon;
        }
    }
//printf("!! LARGEST %s\n", strLargestCommon.c_str());
    if(maxDeep != 0){
        int matches = 0;
        for(int i = 0; i < n; i++){
            string strCommon;
            strCommon = common(suffix[i], strLargestCommon);
            if(strCommon.length() == strLargestCommon.length()){
                matches++;
            }
        }
        if(matches != 1){
            printf("%s %d\n", strLargestCommon.c_str(), matches);
        }
    }else{
        printf("No repetitions found!\n");
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        char str[1000 + 1];
        scanf("%s", str);
        largestSubSequence(str);
    }
    return 0;
}
