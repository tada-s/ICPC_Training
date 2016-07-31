#include <stdio.h>
#include <ctype.h>

typedef unsigned long long number;

int main(){
  number sum = 0;
  number v[3] = {1, 0, 0};
  number s = 0;
  char c;

  while(scanf("%c",&c) != EOF){
    if(isdigit(c)){
      s = (s + (c - '0'))%3;
      sum += v[s];
      v[s]++;
    }else if(c == '\n'){
      printf("%llu\n", sum);
      sum = 0;
      s = 0;
      v[0] = 1; v[1] = 0; v[2] = 0;
    }else{
      s = 0;
      v[0] = 1; v[1] = 0; v[2] = 0;
    }
  }

  return 0;
}
