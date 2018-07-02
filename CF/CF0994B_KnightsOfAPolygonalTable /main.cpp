#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	
	pair<int, long long> v[n];
	priority_queue<long long> q;
	map<int, int> m2;
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i].first);
		m2[v[i].first] = i;
	}
	for(int i = 0; i < n; i++){
		scanf("%I64d", &v[i].second);
	}

	sort(v, v + n);

	map<int, long long> m;

	long long sum = 0;
	for(int i = 0; i < n; i++){
		m[m2[v[i].first]] = sum + v[i].second;
		if(k != 0){
			if(q.size() < k){
				q.push(-v[i].second);
				sum += v[i].second;
			}else if(q.size() == k && -q.top() < v[i].second){
				sum -= (-q.top());
				q.pop();
				q.push(-v[i].second);
				sum += v[i].second;
			}
		}
	}
	for(int i = 0; i < n; i++){
		printf("%I64d ", m[i]);
	}
	

	return 0;
}
