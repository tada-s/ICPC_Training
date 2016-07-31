#include <bits/stdc++.h>

using namespace std;

#define INF 1<<29
#define pb push_back
typedef vector<int> vi;

vi v;
vi st, lazy;

typedef struct {
    int i;
    int left;
    int right;
} node;

node rootNode(){
    return ({node r = {1, 0, v.size() - 1}; r;});
}

node leftNode(node n){
    return ({node r = {n.i * 2, n.left, (n.left + n.right) / 2}; r;});
}

node rightNode(node n){
    return ({node r = {n.i * 2 + 1, (n.left + n.right) / 2 + 1, n.right}; r;});
}

int create(node n){
    int s1 = v.size();
    int s2 = pow(2, ceil(log(s1) / log(2)));
    st.resize(s2);
    lazy.resize(s2, 0);
    int m;
    if(n.left == n.right){
        m = v[n.left];
    }else{
        m = min(create(leftNode(n)), create(rightNode(n)));
    }
    return st[n.i] = m;
}

int query(int qleft, int qright, node n){
    node nL = leftNode(n);
    node nR = rightNode(n);
    if(lazy[n.i] != 0){
        st[n.i] += lazy[n.i];
        if(n.left != n.right){
            st[nL.i] += lazy[n.i];
            st[nR.i] += lazy[n.i];
        }
        lazy[n.i] = 0;
    }
    printf("%d %d %d : st:%d Lz:%d")
    if(qleft <= n.left && n.right <= qright){
        return st[n.i];
    }else{
        int m = -INF;
        if(qleft <= nL.right){
            m = min(m, query(qleft, qright, nL));
        }
        if(nR.left <= qright){
            m = min(m, query(qleft, qright, nR));
        }
        return m;
    }
}

int modify(int mleft, int mright, int value, node n){
    node nL = leftNode(n);
    node nR = rightNode(n);
    if(lazy[n.i] != 0){
        st[n.i] += lazy[n.i];
        if(n.left != n.right){
            lazy[nL.i] += lazy[n.i];
            lazy[nR.i] += lazy[n.i];
        }
        lazy[n.i] = 0;
    }

    if(n.left <= mleft && mright <= n.right){
        st[n.i] += value;
        if(n.left != n.right){
            lazy[nL.i] += value;
            lazy[nR.i] += value;
        }
    }else{
        if(mleft <= nL.right){
            modify(mleft, mright, value, nL);
        }else if(nR.left <= mright){
            modify(mleft, mright, value, nR);
        }
        st[n.i] = min(st[nL.i], st[nR.i]);
    }
    return st[n.i];
}

int main(){
    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        v.pb(x);
    }

    create(rootNode());

    int m;
    scanf("%d%*c", &m);
    for(int i = 0; i < m; i++){
        char str[64];
        scanf("%[^\n]%*c", str);
        int a, b, c;
        if(sscanf(str,"%d %d %d", &a, &b, &c) == 2){
            printf("%d\n", query(a,b, rootNode()));
        }else{
            modify(a, b, c, rootNode());
        }
        printf("%d %d %d\n", a, b, c);

    }
    return 0;
}
