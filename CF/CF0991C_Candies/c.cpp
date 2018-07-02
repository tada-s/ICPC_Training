#include <bits/stdc++.h>

using namespace std;

typedef long long number;

number simulateV(number n, number k);
number simulateP(number n, number k);

number simulateV(number n, number k){
  //cout <<  n << endl;
  if(n < k){
    return n;
  }else{
    return simulateP(n - k, k) + k;
  }
}

number simulateP(number n, number k){
  //cout <<  n << endl;
  number x = n / 10;
  return simulateV(n - x, k);
}


int main(){
  
  number n;
  cin >> n;

  number lb = 1;
  number ub = 1000000000000000000;
  //cout << simulateV(n, 1) << endl;
  //cout << simulateV(n, 2) << endl;
  //cout << simulateV(n, 3) << endl;
  
  while(lb <= ub){
    number mid = (ub + lb) / 2;

    if((simulateV(n, mid) * 2) <= n){
      lb = mid + 1;
    }else{
      ub = mid - 1;
    }
  }

  for(int k = -2; k <= 2; k++){
    if(ub + k >= 1){
      if(simulateV(n, ub + k) * 2 >= n){
	cout << ub + k << endl;
	return 0;
      }
    }
  }
  
  return 0;
}
