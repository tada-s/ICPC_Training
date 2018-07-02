#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long number;

int main(){
    number nx, bx;
    cin >> nx >> bx;
    number x = 0;
    for(int i = 0; i < nx; i++){
        int aux;
        cin >> aux;
        x = x * bx + aux;
    }
    number ny, by;
    cin >> ny >> by;
    number y = 0;
    for(int i = 0; i < ny; i++){
        int aux;
        cin >> aux;
        y = y * by + aux;
    }
    printf("%c\n", (x == y) ? '=' : ( (x > y) ? '>' : '<' ));
    return 0;
}
