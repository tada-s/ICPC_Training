#include <bits/stdc++.h>

using namespace std;

#define pb push_back


int v[100000];
int sum;

void merge(int a1, int b1, int a2, int b2){
    vector<int> v2;
    int i = a1, j = a2;
    while(i <= b1 && j <= b2){
        if(v[i] <= v[j]){
            v2.pb(v[i]);
            i++;
        }else{
            sum += (b1 - a1 + 1) + (j - a2) - v2.size();
            v2.pb(v[j]);
            j++;
        }
    }
    while(i <= b1){
        v2.pb(v[i]);
        i++;
    }
    while(j <= b2){
        v2.pb(v[j]);
        j++;
    }
    for(int i = a1; i <= b2; i++){
        v[i] = v2[i - a1];
    }
}

void mergesort(int a, int b){
    if(a != b){
        mergesort(a, (a + b) / 2);
        mergesort((a + b) / 2 + 1, b);
        merge(a, (a + b) / 2, (a + b) / 2 + 1, b);
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    while(n != 0){
        for(int i = 0; i < n; i++){
            scanf("%d", &v[i]);
        }
        sum = 0;
        mergesort(0, n - 1);
        /*for(int i = 0; i < n; i++){
            printf("%d ", v[i]);
        }*/
        printf("%s\n", sum % 2 ? "Marcelo" : "Carlos");
        scanf("%d", &n);
    }
    return 0;
}
