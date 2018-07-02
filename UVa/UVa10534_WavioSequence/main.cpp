#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int n;
int v1[10000];
int v2[10000];
int llis[10000];
int lhead[10000];
int rlis[10000];
int rhead[10000];

void lis(int v[], int lis[], int head[]){
    vector<int> headIndex;
    vector<int> parentIndex;

    headIndex.pb(0);
    parentIndex.pb(-1);
    head[0] = v[headIndex.back()];
    lis[0] = 1;
    for(int i = 1; i < n; i++){

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
	
	if(parentIndex[i] == -1){
	  lis[i] = 1;
	}else{
	  lis[i] = lis[parentIndex[i]] + 1;
	}
	head[i] = v[headIndex.back()];
    }

    /*int index = headIndex[headIndex.size() - 1];
    vector<int> lis(headIndex.size());
    int c = headIndex.size() - 1;
    while(index != -1){
        lis[c] = index;
        c--;
        index = parentIndex[index];
    }
    headIndex.clear();
    parentIndex.clear();*/

}

int main(){
  //freopen("input.txt", "r", stdin);

    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &v1[i]);
            v2[n - 1 - i] = v1[i];
        }

        lis(v2, rlis, rhead);
        lis(v1, llis, lhead);

	int wMax = -1;
	for(int i1 = 0; i1 < n; i1++){
	  int i2 = n - i1 - 1;
	  
	  int rl = rlis[i1];
	  int ll = llis[i2];
	  if(rhead[i1] <= lhead[i2]){
	    ll--;
	  }
	  if(rhead[i1] >= lhead[i2]){
	    rl--;
	  }
	  int w = min(rl, ll) * 2 + 1;
	  wMax = max(wMax, w);
	}
	printf("%d\n", wMax);

    }


    return 0;
}
