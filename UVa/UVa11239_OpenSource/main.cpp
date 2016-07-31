#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair

int main(){
    //freopen("input.txt", "r", stdin);

    while(true){
        map<string, set<string> > m;
        stack<string> st;

        string projectname;
        string str;
        getline(cin, str);
        if(str[0] == '0') break;
        while(str[0] != '1'){
            if(isupper(str[0])){
                projectname = str;
                st.push(projectname);
            }else{
                m[projectname].insert(str);
                if(!st.empty()){
                    if(st.top() == projectname){
                        st.pop();
                    }
                }
            }
            getline(cin, str);
        }

        #define sunion(a, b, c) set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.end()));
        #define sintersec(a, b, c) set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.end()));
        #define sdiff(a, b, c) set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.end()));


        set<string> a;
        set<string> b;
        for(__typeof(m.begin()) iter = m.begin(); iter != m.end(); iter++){
            set<string> s1, s2, s3;
            sintersec(b, iter->second, s1);
            sunion(a, s1, s2);
            a = s2;
            sunion(b, iter->second, s3);
            b = s3;
        }

        set< pair<int, string> > s;
        for(__typeof(m.begin()) iter = m.begin(); iter != m.end(); iter++){
            set<string> aux;
            sdiff(iter->second, a, aux);
            s.insert(mkp(-aux.size(), iter->first));
        }
        while(!st.empty()){
            s.insert(mkp(0, st.top()));
            st.pop();
        }

        for(__typeof(s.begin()) iter = s.begin(); iter != s.end(); iter++){
            cout <<  iter->second << ' ' << -iter->first << endl;
        }

    }
    return 0;
}
