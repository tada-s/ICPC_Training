#include <bits/stdc++.h>

using namespace std;

#define TABLE_SIZE 20
#define UNDEF -1

int main(){
    //freopen("input.txt", "r", stdin);

    double change[TABLE_SIZE][TABLE_SIZE];

    int caseNumber = 1;

    int n;
    scanf("%d", &n);
    while(n != 0){
        int nameCounter = 1;
        map<string, int> nameIndex;
        vector<string> indexName(TABLE_SIZE);

        for(int i = 0; i < TABLE_SIZE; i++){
            change[i][i] = 1;
            for(int j = 0; j < TABLE_SIZE; j++){
                change[i][j] = UNDEF;
            }
        }

        for(int i = 0; i < n; i++){
            int val1, val2;
            char name1[32], name2[32];
            scanf("%d %s = %d %s%*c", &val1, name1, &val2, name2);
            string str1(name1);
            string str2(name2);
            if(nameIndex[str1] == 0){
                indexName[nameCounter] = str1;
                nameIndex[str1] = nameCounter++;
            }
            if(nameIndex[str2] == 0){
                indexName[nameCounter] = str2;
                nameIndex[str2] = nameCounter++;
            }

            change[nameIndex[str1]][nameIndex[str2]] = (double)(val2) / (double)(val1);
            change[nameIndex[str2]][nameIndex[str1]] = (double)(val1) / (double)(val2);
        }

        for(int k = 1; k < TABLE_SIZE; k++){
            for(int i = 1; i < TABLE_SIZE; i++){
                for(int j = 1; j < TABLE_SIZE; j++){
                    if(!(change[i][k] == UNDEF || change[k][j] == UNDEF)){
                        change[i][j] = change[i][k] * change[k][j];
                    }
                }
            }
        }

        int bestCurrency = -1;
        int bestValue = -1;
        double bestAccuracy = -1;

        int queryValue;
        char queryName[32];
        scanf("%d %s", &queryValue, queryName);
        int queryCurrency = nameIndex[queryName];

        for(int i = 1; i < TABLE_SIZE; i++){
            if(i != queryCurrency && change[queryCurrency][i] != UNDEF){
                int value = ceil(change[queryCurrency][i] * queryValue);
                if(value <= 100000){

                    if(bestAccuracy == -1){
                        bestAccuracy = change[i][queryCurrency] * value;
                        bestCurrency = i;
                        bestValue = value;
                    }else{
                        double newAccuracy = change[i][queryCurrency] * value;
                        if(newAccuracy < bestAccuracy){
                            bestAccuracy = newAccuracy;
                            bestCurrency = i;
                            bestValue = value;
                        }
                    }

                }
            }
        }

        printf("Case %d: %d %s\n", caseNumber++, bestValue, indexName[bestCurrency].c_str());

        scanf("%d", &n);
    }
    return 0;
}
