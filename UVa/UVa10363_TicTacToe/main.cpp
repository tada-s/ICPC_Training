#include <iostream>
#include <stdio.h>
using namespace std;


char m[3][3];

bool isValid(){
    int x = 0, o = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(m[i][j] == 'X') x++;
            else if(m[i][j] == 'O') o++;
        }
    }

    if(!((x == o) || (x - o == 1))) return false;

    int lineX = 0, lineO = 0;

    for(int i = 0; i < 3; i++){
        int sum = 0;
        for(int j = 0; j < 3; j++){
            sum += m[i][j];
        }
        if(sum == 3 * 'O') lineO++;
        else if(sum == 3 * 'X') lineX++;
    }
    for(int j = 0; j < 3; j++){
        int sum = 0;
        for(int i = 0; i < 3; i++){
            sum += m[i][j];
        }
        if(sum == 3 * 'O') lineO++;
        else if(sum == 3 * 'X') lineX++;
    }
    {
        int sum = 0;
        for(int i = 0; i < 3; i++){
            sum += m[i][i];
        }
        if(sum == 3 * 'O') lineO++;
        else if(sum == 3 * 'X') lineX++;
    }
    {
        int sum = 0;
        for(int i = 0; i < 3; i++){
            sum += m[i][3 - (i + 1)];
        }
        if(sum == 3 * 'O') lineO++;
        else if(sum == 3 * 'X') lineX++;
    }

    if(lineO != 0 && lineX != 0) return false;

    if((lineX != 0) && (x == o)){
        return false;
    }

    if((lineO != 0) && (x - o == 1)){
        return false;
    }

    return true;
}

int main()
{
    int N;
    scanf("%d", &N);
    for(int c = 0; c < N; c++){
        getchar();
        for(int j = 0; j < 3; j++){
            for(int i = 0; i < 3; i++){
                m[i][j] = getchar();
            }
            getchar();
        }
        if(isValid()) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
