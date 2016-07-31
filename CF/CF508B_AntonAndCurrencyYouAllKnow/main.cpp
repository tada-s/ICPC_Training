#include <bits/stdc++.h>

using namespace std;

int main(){
  //freopen("input.txt","r", stdin);
  int candidate = -1;
  char str[(int) 1e5+2];
  scanf("%s", str);
  int l = strlen(str);
  for(int i = 0; i < l; i++){
    int n = (str[i] - '0');
    if(n % 2 == 0 && str[i] < str[l-1]){
      swap(str[i], str[l-1]);
      candidate = -2;
      break;
    }else if(n % 2 == 0){
      candidate = i;
    }
  }
  if(candidate == -1) printf("-1");
  else if (candidate == -2)  printf("%s",str);
  else{
    swap(str[candidate],str[l-1]);
    printf("%s",str);
  }
  return 0;
}
