#include <iostream>
#include <vector>
#include <bitset>
#include <stdio.h>
#include <map>

using namespace std;

bitset<1010> bs;
vector<int> employeeT[1010];
map<string,int> employeeNN;
int employeeTNum;
int groups;


void floodfill(int i){
    int e;
    if(!bs.test((size_t)i)){
        bs.set((size_t)i);
        for(int j = 0; j < employeeT[i].size(); j++){
            e = employeeT[i][j];
            for(int k = 0; k < employeeT[e].size(); k++){
                if(employeeT[e][k] == i){
                    floodfill(employeeT[i][j]);
                    break;
                }
            }
        }
    }
}

void setTransitiveRelation(int,int);

void setTransitiveRelation2(int i, int j){
//    printf("set%d,%d:",i,j);
    if(!bs.test((size_t)j)){
  //      printf("ok\n");
        bs.set((size_t)j);
        employeeT[i].push_back(j);
        for(int k = 0; k < employeeT[j].size(); k++){
            setTransitiveRelation2(i,employeeT[j][k]);
        }
    }//else printf("no\n");
}

void setTransitiveRelation(int i, int j){
        for(int k = 0; k < employeeT[j].size(); k++){
            setTransitiveRelation2(i,employeeT[j][k]);
        }
}


int main()
{
    char s[15];
    int p, t, e1, e2;
    freopen("input.txt","r",stdin);
    scanf("%d %d",&p, &t);
    getchar();
    while(!(p==0 && t==0)){
//printf("groups\n");
        for(int i = 0; i < p; i++){
            gets(s);
            employeeNN[s] = i;
        }
        employeeTNum = 0;
        for(int i = 0; i < t; i++){
            gets(s);
            e1 = employeeNN[s];
            gets(s);
            e2 = employeeNN[s];
            employeeT[e1].push_back(e2);
//printf("%d -> %d\n",e1,e2);
        }
//printf("asdfasdf\n");
        for(int i = 0; i < p; i++){
            bs.reset();
            bs.set((size_t) i);
            int k = employeeT[i].size();
            for(int j = 0; j < k; j++){
                bs.set((size_t) employeeT[i][j]);
            }
            for(int j = 0; j < k; j++){
//printf("calling:%d,%d\n",i,employeeT[i][j]);
                setTransitiveRelation(i,employeeT[i][j]);
            }
        }
        for(int i = 0; i < p; i++){
            for(int j = 0; j < employeeT[i].size(); j++){
//printf("%d -> %d\n",i,employeeT[i][j]);
            }
        }
        bs.reset();
        groups = 0;
        for(int i = 0; i < p; i++){
            if(!bs.test(i)){
                groups++;
                floodfill(i);
            }
        }
        printf("%d\n",groups);
        employeeNN.clear();
        for(int i = 0; i < p; i++){
            employeeT[i].clear();
        }
        scanf("%d %d", &p, &t);
        getchar();
    }
    return 0;
}



