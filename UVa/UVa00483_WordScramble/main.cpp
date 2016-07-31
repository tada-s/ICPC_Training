#include <bits/stdc++.h>

using namespace std;

int main(){
  //freopen("input.txt", "r", stdin);
  string line, word;
  istringstream iss;

  while(getline(cin, line)){
    iss.clear();
    iss.str(line);

    iss >> word;
    reverse(word.begin(), word.end());
    cout << word;    
    while(iss >> word){
      reverse(word.begin(), word.end());
      cout << ' '  << word;
    }
    cout << endl;
  }
  
  return 0;
}
