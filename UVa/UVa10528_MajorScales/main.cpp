#include <bits/stdc++.h>

using namespace std;

int map1(char c){
    switch(c){
    case 'C': return 0;
    case 'c': return 1;
    case 'D': return 2;
    case 'd': return 3;
    case 'E': return 4;
    case 'F': return 5;
    case 'f': return 6;
    case 'G': return 7;
    case 'g': return 8;
    case 'A': return 9;
    case 'a': return 10;
    case 'B': return 11;
    default : return -1;
    }
}

string map2(int n){
    switch(n){
    case 0: return "C";
    case 1: return "C#";
    case 2: return "D";
    case 3: return "D#";
    case 4: return "E";
    case 5: return "F";
    case 6: return "F#";
    case 7: return "G";
    case 8: return "G#";
    case 9: return "A";
    case 10: return "A#";
    case 11: return "B";
    default : return "BAD D:";
    }
}

#define KEYS 5
int keys[KEYS] = {2, 4, 6, 9, 11};

int main(){
    //freopen("input.txt", "r", stdin);
    string input;
    getline(cin, input);
    while(input != "END"){
        stringstream stream(input);
        vector<int> v;
        string str;
        while(stream >> str){
            v.push_back( map1( str[0] + (str[1] == '#' ? 'a' - 'A' : 0) ) );
        }

        bool key[12];
        for(int i = 0; i < 12; i++){
            key[i] = true;
        }

        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < KEYS; j++){
                key[ (v[i] + keys[j]) % 12 ] = false;
            }
        }

        bool flag = false;
        for(int i = 0; i < 12; i++){
            if(key[i]){
                if(!flag){
                    flag = true;
                }else{
                    cout << ' ';
                }
                cout << map2(i);
            }
        }
        cout << endl;

        getline(cin, input);
    }
    return 0;
}
