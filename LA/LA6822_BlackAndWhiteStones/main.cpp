#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int main(){
  long long a, b;
  char v[5000+10];
  while(scanf("%I64d %I64d", &a, &b) != EOF){
    getchar();
    scanf("%s",v);
    int cW = 0;
    int cB = 0;
    int n;
    for(int i = 0 ; v[i] != '\0'; i++){
      if(v[i] == 'W') cW++;
      else if(v[i] == 'B') cB++;
    }
    n = cW + cB;

    queue<int> qW;
    queue<int> qB;
    for(int i = 0; i < cB; i++){
      if(v[i] == 'W') qW.push(i);
    }
    for(int i = n - 1; i >= cB; i--){
      if(v[i] == 'B') qB.push(i);
    }

    long long coin = 0;
    while( !qW.empty() && !qB.empty() ){
      long long iW, iB;
      iW = qW.front(); qW.pop();
      iB = qB.front(); qB.pop();
      coin += min(a, (a-b) * (iB-iW));
    }
    //printf("%I64d\n",coin); //THIS LINE COST ME 41 submission...
    cout << coin << endl;
  }

  return 0;
}
