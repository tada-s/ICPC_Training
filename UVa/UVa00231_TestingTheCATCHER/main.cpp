#include <bits/stdc++.h>

using namespace std;
#define pb push_back

int lis(vector<int> &v){
    vector<int> head;
    vector<int> headPointer;
    vector<int> predecesor;

    head.pb(v[0]);
    headPointer.pb(0);
    predecesor.pb(-1);

    for(int i = 1; i < v.size(); i++){
        int key = v[i];
        int lb = 0;
        int ub = head.size() - 1;
        while(lb <= ub){
            int mid = (lb + ub) / 2;
            if(key < head[mid]){
                ub = mid - 1;
            }else{
                lb = mid + 1;
            }
        }

        //printf("cs: headsize = %d key: %d position: %d\n", head.size(), key, lb);
        if(lb == head.size()){
            //printf("insert\n");
            predecesor.push_back(headPointer[headPointer.size() - 1]);

            head.push_back(key);
            headPointer.push_back(i);
        }else{
            //printf("replace head[%d] == %d to %d\n", lb, head[lb], key);
            predecesor.push_back(predecesor[headPointer[lb]]);

            head[lb] = key;
            headPointer[lb] = i;
        }
    }
/*
    printf("\n V:\n");
    for(int i = 0; i < v.size(); i++){
        printf("%2d ", v[i]);
    }
    printf("\n Index:\n");
    for(int i = 0; i < v.size(); i++){
        printf("%2d ", i);
    }

    printf("\n HEAD:\n");
    for(int i = 0; i < head.size(); i++){
        printf("%2d ", head[i]);
    }

    printf("\n HEADP:\n");
    for(int i = 0; i < headPointer.size(); i++){
        printf("%2d ", headPointer[i]);
    }

    printf("\n PRE:\n");
    for(int i = 0; i < predecesor.size(); i++){
        printf("%2d ", predecesor[i]);
    }

    printf("\n rev LIS:\n");
    int pointer2 = headPointer[headPointer.size() - 1];
    while(pointer2 != -1){
        printf("%2d ", v[pointer2]);
        pointer2 = predecesor[pointer2];
    }*/

    int c = 0;
    int pointer = headPointer[headPointer.size() - 1];
    while(pointer != -1){
        c++;
        pointer = predecesor[pointer];
    }

    return c;
}

int main(){
    //freopen("input.txt", "r", stdin);
    int x;
    int testNumber = 1;

    scanf("%d", &x);
    while(x != -1){
        vector<int> v;
        while(x != -1){
            v.push_back(-x);
            scanf("%d", &x);
        }
        if(testNumber != 1){
            printf("\n");
        }
        printf("Test #%d:\n  maximum possible interceptions: %d\n", testNumber++, lis(v));
        v.clear();
        scanf("%d", &x);
    }

    /*for(int key = -5; key <= 55; key += 5){
        int lb = 0;
        int ub = 5;
        while(lb <= ub){
            int mid = (ub + lb) / 2;
            if(key < v[mid]){
                ub = mid - 1;
            }else{
                lb = mid + 1;
            }
        }

        if(lb == 0){
            printf("Not Found! Smaller than lower bound\n");
        }else if(v[lb - 1] != key && lb == 6){
            printf("Not Found! Bigger than lower bound\n");
        }else if(v[lb - 1] != key && lb != 6){
            printf("Not Found! Between the index %d and %d\n", lb - 1, lb);
        }else{
            printf("Found key %d at index: %d\n", key, lb - 1);
        }

    }*/



    return 0;
}
