#include <bits/stdc++.h>

using namespace std;

int solution[8];
int solutionCounter;

bool isValid(int v[], int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(v[i] == v[j] || v[i] - i == v[j] - j || v[i] + i == v[j] + j){
                return false;
            }
        }
    }
    return true;
}

void forcedBacktrackingPrint(int i, int r, int c){
    if(i == 8){
        printf("%2d     ", solutionCounter++);
        for(int j = 0; j < 8; j++){
            printf(" %d", solution[j] + 1);
        }
        printf("\n");
    }else{
        if(i == c){
            solution[i] = r;
            if(isValid(solution, i + 1)){
                forcedBacktrackingPrint(i + 1, r, c);
            }
        }else{
            for(int j = 0; j < 8; j++){
                solution[i] = j;
                if(isValid(solution, i + 1)){
                    forcedBacktrackingPrint(i + 1, r, c);
                }
            }
        }
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        if(i != 0){
            printf("\n");
        }
        int r, c;
        scanf("%d%d", &r, &c);
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        solutionCounter = 1;
        forcedBacktrackingPrint(0, r - 1, c - 1);
    }

    return 0;
}
