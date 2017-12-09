#include <bits/stdc++.h>

using namespace std;

int v[500 + 1];
long long accum[500 + 1];
int m, k;

int p(long long maxV){
    int i0 = m - 1;
    int i1 = m - 1;
    int kk = 1;
    for(int i = m - 1; i >= 0; i--){
        i0 = i;
        long long sum = accum[i1] - accum[i0] + v[i0];

        if(kk + i < k){
            kk++;
            i1 = i0 - 1;
        }else if(maxV < v[i1]){
            kk++;

            i1 = i0 - 1;
        }else if(maxV < sum){
            kk++;

            i1 = i0;
        }
    }
    return kk;
}

long long getRealMaxV(long long maxV){
    int i0 = m - 1;
    int i1 = m - 1;
    int kk = 1;
    stack<int> s;
    for(int i = m - 1; i >= 0; i--){
        //printf("%d: %d ", i, v[i]);
        s.push(v[i]);
        i0 = i;
        long long sum = accum[i1] - accum[i0] + v[i0];

        if(kk + i < k){
            //printf(" a\n");
            int aux = s.top();
            s.pop();
            s.push(-1);
            s.push(aux);
            kk++;
            i1 = i0 - 1;
        }else if(maxV < v[i1]){
            //printf(" c\n");
            s.push(-1);
            kk++;

            i1 = i0 - 1;
        }else if(maxV < sum){
            //printf(" d\n");
            int aux = s.top();
            s.pop();
            s.push(-1);
            s.push(aux);
            kk++;

            i1 = i0;
        }else{
            //printf(" e\n");
        }
    }
    if(s.top() == -1){
        s.pop();
    }
    long long realMaxV = 0;
    long long sum = 0;
    while(!s.empty()){
        if(s.top() == -1){
            realMaxV = max(realMaxV, sum);
            sum = 0;
        }else{
            sum += s.top();
        }
        s.pop();
    }
    realMaxV = max(realMaxV, sum);
    return realMaxV;
}

void pprint(long long maxV){
    //printf("maxV=%d\n", maxV);
    int i0 = m - 1;
    int i1 = m - 1;
    int kk = 1;
    stack<int> s;
    for(int i = m - 1; i >= 0; i--){
        //printf("%d: %d ", i, v[i]);
        s.push(v[i]);
        i0 = i;
        int sum = accum[i1] - accum[i0] + v[i0];

        if(kk + i < k){
            //printf(" a\n");
            int aux = s.top();
            s.pop();
            s.push(-1);
            s.push(aux);
            kk++;
            i1 = i0 - 1;
        }else if(maxV < v[i1]){
            //printf(" c\n");
            s.push(-1);
            kk++;

            i1 = i0 - 1;
        }else if(maxV < sum){
            //printf(" d\n");
            int aux = s.top();
            s.pop();
            s.push(-1);
            s.push(aux);
            kk++;

            i1 = i0;
        }else{
            //printf(" e\n");
        }
    }
    if(s.top() == -1){
        s.pop();
    }
    printf("%d", s.top());
    s.pop();
    while(!s.empty()){
        if(s.top() == -1){
            printf(" /");
        }else{
            printf(" %d", s.top());
        }
        s.pop();
    }
    printf("\n");
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    while(n--){
        scanf("%d%d", &m, &k);

        for(int i = 0; i < m; i++){
            scanf("%d", &v[i]);
        }

        accum[0] = v[0];
        for(int i = 1; i < m; i++){
            accum[i] = accum[i - 1] + v[i];
        }

        long long l = 1;
        long long u = accum[m - 1];
        long long mid;
        while(l <= u){
            mid = (l + u) / 2;
            int e = p(mid);
            if(-k <= -e && mid >= getRealMaxV(mid)){
                u = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        /*printf("p(%I64d)=%d, %I64d\n", l-1, p(l-1), getRealMaxV(l));
        printf("p(%I64d)=%d, %I64d\n", l, p(l), getRealMaxV(l));
        printf("p(%I64d)=%d, %I64d\n", l+1, p(l+1), getRealMaxV(l));
        printf("p(%d)=%d, %I64d\n", 20065, p(20065), getRealMaxV(20065));
        printf("p(%d)=%d, %I64d\n", 9066, p(9066), getRealMaxV(9066));*/
        pprint(getRealMaxV(l));
        //pprint(l+1);
    }
    return 0;
}
