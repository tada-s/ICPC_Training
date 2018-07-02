#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> point;


int crossp(point v1, point v2){
  return v1.first * v2.second - v1.second * v2.first;
}

bool isInside(point square[], int x, int y){
  for(int i = 0; i < 4; i++){
    point v1;
    v1.first = square[(i + 1) % 4].first - square[i].first;
    v1.second = square[(i + 1) % 4].second - square[i].second;
    
    point v2;
    v2.first = x - square[i].first;
    v2.second = y - square[i].second;

    int product = crossp(v1, v2);
    //printf("(%d,%d)x(%d,%d)=%d", v1.first, v1.second, v2.first, v2.second, product);
    if(product > 0){
      return false;
    }
  }
  return true;
}

int main(){
  pair<int, int> p[4];
  for(int i = 0; i < 4; i++){
    scanf("%d%d", &p[i].first, &p[i].second);
    p[i].first = p[i].first * 2;
    p[i].second = p[i].second * 2;
  }

  pair<int, int> q[4];
  for(int i = 0; i < 4; i++){
    scanf("%d%d", &q[i].first, &q[i].second);
    q[i].first = q[i].first * 2;
    q[i].second = q[i].second * 2;
  }

  sort(p, p + 4);
  swap(p[2], p[3]);
  sort(q, q + 4);
  swap(q[1], q[2]);
  swap(q[2], q[3]);
  /*for(int i = 0; i < 4; i++){
    printf("(%d,%d) ", p[i].first, p[i].second);
  }
  putchar(10);
  for(int i = 0; i < 4; i++){
    printf("(%d,%d) ", q[i].first, q[i].second);
    }
  printf("[]%d []\n", isInside(p, 12, 6));
  printf("[]%d []\n", isInside(q, 12, 6));
  return 0;*/
  for(int x = -200; x <= 200; x++){
    for(int y = -200; y <= 200; y++){
      if(isInside(p, x, y) && isInside(q, x, y)){
	printf("YES\n");
	return 0;
      }
    }
  }
  printf("NO\n");

  
  
  return 0;
}
