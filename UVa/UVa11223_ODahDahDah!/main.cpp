#include <bits/stdc++.h>

using namespace std;

char morse2char(string str){
    if(str == ".-") return 'A';
    else if(str == "-...") return 'B';
    else if(str == "-.-.") return 'C';
    else if(str == "-..") return 'D';
    else if(str == ".") return 'E';
    else if(str == "..-.") return 'F';
    else if(str == "--.") return 'G';
    else if(str == "....") return 'H';
    else if(str == "..") return 'I';
    else if(str == ".---") return 'J';
    else if(str == "-.-") return 'K';
    else if(str == ".-..") return 'L';
    else if(str == "--") return 'M';
    else if(str == "-.") return 'N';
    else if(str == "---") return 'O';
    else if(str == ".--.") return 'P';
    else if(str == "--.-") return 'Q';
    else if(str == ".-.") return 'R';
    else if(str == "...") return 'S';
    else if(str == "-") return 'T';
    else if(str == "..-") return 'U';
    else if(str == "...-") return 'V';
    else if(str == ".--") return 'W';
    else if(str == "-..-") return 'X';
    else if(str == "-.--") return 'Y';
    else if(str == "--..") return 'Z';
    else if(str == "-----") return '0';
    else if(str == ".----") return '1';
    else if(str == "..---") return '2';
    else if(str == "...--") return '3';
    else if(str == "....-") return '4';
    else if(str == ".....") return '5';
    else if(str == "-....") return '6';
    else if(str == "--...") return '7';
    else if(str == "---..") return '8';
    else if(str == "----.") return '9';
    else if(str == ".-.-.-") return '.';
    else if(str == "--..--") return ',';
    else if(str == "..--..") return '?';
    else if(str == ".----.") return '\'';
    else if(str == "-.-.--") return '!';
    else if(str == "-..-.") return '/';
    else if(str == "-.--.") return '(';
    else if(str == "-.--.-") return ')';
    else if(str == ".-...") return '&';
    else if(str == "---...") return ':';
    else if(str == "-.-.-.") return ';';
    else if(str == "-...-") return '=';
    else if(str == ".-.-.") return '+';
    else if(str == "-....-") return '-';
    else if(str == "..--.-") return '_';
    else if(str == ".-..-.") return '"';
    else if(str == ".--.-.") return '@';
    else return 0;
}

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; i++){
        string input;
        getline(cin, input);
        stringstream stream(input);

        cout << "Message #" << i << endl;
        string str;
        while(stream >> str){
            cout << morse2char(str);
            if(stream.tellg() == -1) break;
            if(stream.tellg() + 1 < input.size()){
                if(input[ stream.tellg() + 1 ] == ' '){
                    cout << ' ';
                }
            }
        }

        cout << endl;
        if(i != n){
            cout << endl;
        }
    }
    return 0;
}
