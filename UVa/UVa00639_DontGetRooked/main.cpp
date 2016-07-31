#include <iostream>
#include <stdio.h>

#define REP(i, a, b) for(int i = int(a); i <= int(b); i++)

#define mapRook 'R'
#define mapEmpty '.'
#define mapWall 'X'


using namespace std;

int n;
char m[5][5];
int rootCount;
int maxRootCount;
bool existRook;

void putRook(){
    REP(i, 0, n-1){
        REP(j, 0, n-1){
            if(m[i][j] == mapEmpty){
                existRook = false;
                for(int k = i+1; m[k][j] != mapWall && k < n; k++)
                    if(m[k][j] == mapRook) existRook = true;
                for(int k = i-1; m[k][j] != mapWall && k >= 0; k--)
                    if(m[k][j] == mapRook) existRook = true;
                for(int k = j+1; m[i][k] != mapWall && k < n; k++)
                    if(m[i][k] == mapRook) existRook = true;
                for(int k = j-1; m[i][k] != mapWall && k >= 0; k--)
                    if(m[i][k] == mapRook) existRook = true;
                if(!existRook){
                    m[i][j] = mapRook;
                    rootCount++;
                    if(rootCount > maxRootCount) maxRootCount = rootCount;
                    putRook();
                    m[i][j] = mapEmpty;
                    rootCount--;
                }
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    while(n != 0){
        maxRootCount = 0;
        rootCount = 0;
        getchar();
        REP(i,0,n-1){
            REP(j,0,n-1){
                m[i][j] = getchar();
            }
            getchar();
        }
        putRook();
        printf("%d\n",maxRootCount);
        scanf("%d",&n);
    }
    return 0;

}
