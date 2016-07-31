#include <bits/stdc++.h>

using namespace std;

long long calcScore(const char* str){
    long long sum = 0;
    long long i = 0;
    while(str[i] != '\0'){
        sum += str[i] - 'A' + 1;
        i++;
    }
    return sum;
}

int main(){
    FILE *fp;
    vector<string> v;
    fp = fopen("p022_names.txt", "rb");
    char str[128];
    while(!feof(fp)){
        fscanf(fp,"\"%[A-Z]\",", str);
        v.push_back(string(str));
    }
    sort(v.begin(), v.end());
    long long sum = 0;
    for(int i = 0; i < v.size(); i++){
        sum += (i+1) * calcScore(v[i].c_str());
    }
    printf("%I64d",sum);
    return 0;
}
