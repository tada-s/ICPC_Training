#include <bits/stdc++.h>

using namespace std;

#define EMPTY -1

int dp[16][7];

int f(int a, int b){
    if(dp[a][b] == EMPTY){
        if(b == 1){
            dp[a][b] = 1;
        }else{
            int sum = 0;
            for(int i = 0; i <= a; i++){
                sum += f(i, b - 1);
            }
            dp[a][b] = sum;
        }
    }
    return dp[a][b];
}

int findN(int a, int b, int sequence[7]){
    if(b == 1){
        return 1;
    }else{
        int sum = 0;
        for(int i = 0; i <= a - sequence[b] - 1; i++){
            sum += f(i, b - 1);
        }
        return sum + findN(a - sequence[b], b - 1, sequence);
    }
}

void findSequence(int a, int b, int n, int sequence[]){
    if(b == 1){
        sequence[b] = a;
        return;
    }else{
        int lowerBound = 0;
        int upperBound = 0;
        for(int sequenceNumber = 0; sequenceNumber <= a; sequenceNumber++){
            upperBound += f(a - sequenceNumber, b - 1);
            if(lowerBound < n && n <= upperBound){
                sequence[b] = sequenceNumber;
                findSequence(a - sequenceNumber, b - 1, n - lowerBound, sequence);
                return;
            }
            lowerBound = upperBound;
        }
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 7; j++){
            dp[i][j] = EMPTY;
        }
    }

    int sequence[7];
    char command;
    int caseNumber = 1;
    while(true){
        scanf("%c", &command);
        switch(command){
        case 'm':
            for(int i = 6; i > 0; i--){
                int x;
                scanf("%d", &x);
                sequence[i] = x;
            }
            printf("Case %d: %d\n", caseNumber++, 15504 - findN(15, 6, sequence));
            break;
        case 'u':
            int y;
            scanf("%d", &y);
            findSequence(15, 6, y + 1, sequence);
            printf("Case %d: %d", caseNumber++, sequence[6]);
            for(int i = 6 - 1; i > 0; i--){
                printf(" %d", sequence[i]);
            }
            printf("\n");
            break;
        case 'e':
            return 0;
        }
    }



    return 0;
}
