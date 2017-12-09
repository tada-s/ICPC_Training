#include <bits/stdc++.h>

using namespace std;

typedef struct Box{
    int a, b, c;
};

vector<Box> boxes;

bool isUsed[10];

int maxStack(int x, int y){
    if(x > y){
        maxStack(y, x);
    }

    int maxStackSize = 0;

    for(int i = 0; i < boxes.size(); i++){
        if(!isUsed[i]){
            isUsed[i] = true;
            Box box = boxes[i];
            if(box.a <= x && box.b <= y){
                maxStackSize = max(maxStackSize, maxStack(box.a, box.b) + 1);
            }
            if(box.a <= x && box.c <= y){
                maxStackSize = max(maxStackSize, maxStack(box.a, box.c) + 1);
            }
            if(box.b <= x && box.a <= y){
                maxStackSize = max(maxStackSize, maxStack(box.b, box.a) + 1);
            }
            if(box.b <= x && box.c <= y){
                maxStackSize = max(maxStackSize, maxStack(box.b, box.c) + 1);
            }
            if(box.c <= x && box.a <= y){
                maxStackSize = max(maxStackSize, maxStack(box.c, box.a) + 1);
            }
            if(box.c <= x && box.b <= y){
                maxStackSize = max(maxStackSize, maxStack(box.c, box.b) + 1);
            }
            isUsed[i] = false;
        }
    }

    return maxStackSize;
}

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int caseNumber = 1;
    while(n != 0){
        for(int i = 0; i < n; i++){
            isUsed[i] = false;
        }
        boxes.clear();
        for(int i = 0; i < n; i++){
            Box box;
            scanf("%d %d %d", &box.a, &box.b, &box.c);
            boxes.push_back(box);
        }
        printf("Case %d: %d\n", caseNumber++, maxStack(100, 100));
        scanf("%d", &n);
    }
    return 0;
}
