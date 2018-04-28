#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int n;
int v1[10000];
int v2[10000];

vector<int> lis(int v[]){
    vector<int> headIndex;
    vector<int> parentIndex;

    headIndex.pb(0);
    parentIndex.pb(-1);
    for(int i = 0; i < n; i++){

        int lb = 0;
        int ub = headIndex.size() - 1;
        int key = v[i];
        while(lb <= ub){
            int mid = (lb + ub) / 2;
            int value = v[headIndex[mid]];
            if(value < key){
                lb = mid + 1;
            }else{
                ub = mid - 1;
            }
        }
        int bestIndex = ub;
        if(bestIndex + 1 == headIndex.size()){
            headIndex.pb(i);
        }else{
            if(v[i] < v[headIndex[bestIndex + 1]]){
                headIndex[bestIndex + 1] = i;
            }
        }
        if(bestIndex == -1){
            parentIndex.pb(-1);
        }else{
            parentIndex.pb(headIndex[bestIndex]);
        }
    }


    int index = headIndex[headIndex.size() - 1];
    vector<int> lis(headIndex.size());
    int c = headIndex.size() - 1;
    while(index != -1){
        if(c == -10) break;
        lis[c] = index;
        c--;
        index = parentIndex[index];
    }
    headIndex.clear();
    parentIndex.clear();

    return lis;
}

int main(){
    freopen("input.txt", "r", stdin);

    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &v1[i]);
            v2[n - 1 - i] = v1[i];
        }

        vector<int> lis1 = lis(v1);
        vector<int> lis2 = lis(v2);

        if(lis1.size() == 1 || lis2.size() == 1){
            printf("1\n");
        }else{
            int i1 = 0;
            int i2 = lis2.size() - 1;
            while(lis1[i1] < lis2[i2]){
                if(v1[lis1[i1]] < v2[lis2[i2]]){
                    i1++;
                }else{
                    i2--;
                }
            }
            if(lis1[i1] == lis2[i2]){
                printf("%d\n", min(i1, i2) * 2 + 1);
            }else{
                if(v1[lis1[i1]] < v2[lis2[i2]]){
                    i2++;
                }else{
                    i1--;
                }
                if(v1[lis1[i1]] == v2[lis2[i2]]){
                    printf("%d\n", min(i1, i2) * 2 + 1);
                }else if(v1[lis1[i1]] < v2[lis2[i2]]){
                    printf("%d\n", min(i1 + 1, i2) * 2 + 1);
                }else{
                    printf("%d\n", min(i1, i2 + 1) * 2 + 1);
                }
            }
        }


    }


    return 0;
}
