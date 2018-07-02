#include <bits/stdc++.h>

using namespace std;

int main(){
	int m, n;
	scanf("%d%d", &m, &n);
	int v1[10];
	int v2[10];
	for(int i = 0; i < m; i++){
		int x;
		scanf("%d", &v1[i]);
	}
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &v2[i]);
	}
	bool exists = false;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(v1[i] == v2[j]){
				printf("%d ", v1[i]);
				exists = true;
break;
			}
		}
	}

	
	
	return 0;
}
