#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long number;

int main(){
    int ii = 0;
    number x;
    cin >> x;
    for(int i = (int) floor(log(x) / log(10)); i >= 0; i--){
        char digit[19];
        sprintf(digit, "%llu", (number) (x - pow(10,i)));
        cout << "digit:[" << digit << "]" << endl;

        int digitFreq[10];
        for(int j = 0; j < 10; j++){
            digitFreq[j] = 0;
        }
        for(int j = 0; j < ii; j++){

        }

        ii++;
    }
    return 0;
}
/*
bool itsOk(char str[]){
    int l = strlen(str);
    int digit[10];
    for(int j = 0; j < 10; j++){
        digit[j] = 0;
    }

    for(int j = 0; j < i; j++){
        digit[ str[j] - '0' ]++;
        if(digit[ str[j] - '0' ] == 3){
            error = true;
            break;
        }
    }
}

int main(){
    char str[19];
    while(scanf("%s", str) != EOF){

        bool gotIt = false;

        int l = strlen(str);
        for(int i = l - 1; i >= 0; i--){
            bool error = false;

            int digit[10];
            for(int j = 0; j < 10; j++){
                digit[j] = 0;
            }

            //test1
            for(int j = 0; j < i; j++){
                digit[ str[j] - '0' ]++;
                if(digit[ str[j] - '0' ] == 3){
                    error = true;
                    break;
                }
            }

            if(error) continue;

            //test2
            for(int d = str[i] - '0' - 1; d >= 0; d--){
                if(digit[d] != 2){
                    //great!!! Go Fish
                    gotIt = true;
                    str[i] = d + '0';
                    digit[d]++;
                    int x = 9;
                    for(int j = i + 1; j < l; j++){
                        while(digit[x] == 2){
                            x--;
                        }
                        str[j] = x + '0';
                        digit[x]++;
                    }
                    break;
                }
            }

            if(gotIt) break;
        }

        printf("%s", str);
    }


    return 0;
}*/
