#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    while(n != 0){
        multiset<int> s;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            int k;
            scanf("%d", &k);
            for(int j = 0; j < k; j++){
                int x;
                scanf("%d", &x);
                s.insert(x);
            }


            int h = *(--s.end());
            int l = *(s.begin());


            sum += (h - l);

            s.erase(--s.end());
            s.erase(s.begin());
        }

        printf("%ld\n", sum);

        scanf("%d", &n);
    }
    return 0;
}
